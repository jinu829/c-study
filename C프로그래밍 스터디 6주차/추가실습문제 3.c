#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)  

//동적 할당 문제를 가장한 구조체 문제 : 구조체 누가 더 잘하냐?

struct reserve {
	int id; 
	char grade[4]; 
	int price; 
};

void input(struct reserve* p, int N);

int cal_sum(struct reserve* p, int N, int id);

int main()
{
	struct reserve* re = NULL; //오류 확인 부분을 안전하게 넘어가려면 이렇게 =NULL로 선언해주는 게 좋습니다. (감점받는 경우를 본 적은 없지만 그래도 혹시 모르니)
	int N;
	int id;
	int total;
	scanf("%d", &N); 
	re = (struct reserve*)malloc(N * sizeof(struct reserve)); //1. N을 입력받고 N개 index를 가진 구조체 배열 생성, 각각의 원소 입력받기
	if (re == NULL) //동적 할당 후 오류 확인
	{
		printf("not enough memory!!");
		return -1;
	}
	input(re, N); //1-2 : input함수 활용해서 구조체 원소들 입력받기

	for (struct reserve* q = re; q < re + N; q++) //2. 가격 계산(우리가 구조체에서 보던 그 맛)
	{
		if (strcmp(q->grade, "VIP") == 0)
			q->price = 140000;
		if (strcmp(q->grade, "R") == 0)
			q->price = 110000;
		if (strcmp(q->grade, "S") == 0)
			q->price = 85000;
		if (strcmp(q->grade, "A") == 0)
			q->price = 55000;
	}
	scanf("%d", &id);
	for (struct reserve* q = re; q < re + N; q++) //3. 고객의 id를 입력받아, 해당 고객이 구매한 티켓의 등급과 티켓 가격을 입력순서대로 출력하고, 티켓 구매에 사용된 총 금액을 출력
	{
		if (q->id == id)
			printf("%s %d\n", q->grade, q->price);
	}
	total = cal_sum(re, N, id);
	printf("%d", total);
	free(re); //free항상 신경쓰기
	return 0;
}

void input(struct reserve* p, int N)
{
	for (struct reserve* q = p; q < p + N; q++) //문제 조건에 포인터를 직접 이동시키라는 표현이 있으면 이렇게 범위 작성 해야합니다.
	{
		scanf("%d %s", &q->id, q->grade);
	}
}

int cal_sum(struct reserve* p, int N, int id)
{
	int total = 0;
	for (struct reserve* q = p; q < p + N; q++)
	{
		if (q->id == id)
		{
			total += q->price;
		}
	}
	return total;
}