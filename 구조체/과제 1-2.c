#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct taxi_info { //문제에서 정의한 대로 구조체 선언
	char start[11];
	char target[11];
	double distance;
	int t_time;
	char late_night;
	int tot;
}TAXI;

TAXI* sel_max(TAXI* p, int N, char* s, char* d);

int main()
{
	TAXI p[20], * maxTAXI = NULL;
	int N;
	char s[11], d[11];
	scanf("%d", &N); //1. 정수 N입력받기
	getchar();
	for (int i = 0; i < N; i++) //2. N개의 출발지, 목적지, 이동거리, 정체시간, 심야운행여부 정보를 입력받아 구조체에 저장하기
	{
		scanf("%s %s %lf %d %c", p[i].start, p[i].target, &p[i].distance, &p[i].t_time, &p[i].late_night); //문자열 입력받을 때만 &안붙인다
		getchar(); //getchar()까먹지 말기!!
	}

	for (int i = 0; i < N; i++) //3. 요금 계산
		/*
		   1. 심야인지 주간인지 구분하고
		   2. 거리가 2km보다 더 긴지 아닌지 보고
		   3. 요금 계산(요금 계산은 문제에 나와있는데로 따라가기)
		*/
	{
		if (p[i].late_night == 'N')
		{
			if (p[i].distance <= 2)
			{
				p[i].tot = 3800 + (p[i].t_time / 30) * 100;
			}
			if (p[i].distance > 2)
			{
				p[i].tot = (((p[i].distance - 2) * 1000) / 100) * 100 + 3800 + (p[i].t_time / 30) * 100;
			} 
		}
		if (p[i].late_night == 'Y')
		{
			if (p[i].distance <= 2)
			{
				p[i].tot = 4800 + (p[i].t_time / 30) * 120;
			}
			if (p[i].distance > 2)
			{
				p[i].tot = (((p[i].distance - 2) * 1000) / 100) * 120 + 4800 + (p[i].t_time / 30) * 120;
			}
		}
	}

	scanf("%s %s", s, d); //4. 출발지와 목적지 정보 입력받아서, 금액이 가장 큰 경우 찾기

	maxTAXI = sel_max(p, N, s, d); /*매개변수에 뭐 넣어야 할지 생각
	TAXI구조체 배열 시작 주소 -> p, N개 -> N, 출발지, 목적지 문자열 시작 주소 -> s, d
								   */

	printf("%.2f %d %c %d", maxTAXI->distance, maxTAXI->t_time, maxTAXI->late_night, maxTAXI->tot);

	return 0;
}

TAXI* sel_max(TAXI* p, int N, char* s, char* d)
{
	int max = 0;
	TAXI* maxTAXI = NULL;
	for (TAXI* q = p; q < p + N; q++) //4-1 구조체 배열 원소를 하나하나씩 돌아보면서 비교해봅시다
	{
		if (strcmp(q->start, s) == 0 && strcmp(q->target, d) == 0) //만약 구조체 원소랑 s, d랑 출발지, 목적지가 같다면
		{
			if (q->tot > max) //만약 금액이 가장 크다면
			{
				max = q->tot;
				maxTAXI = q; //해당 구조체 원소 주소 변수에 넣기
			}
		}
	}
	return maxTAXI; //찾은 변수 반환
}