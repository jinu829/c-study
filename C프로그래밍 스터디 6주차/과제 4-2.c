#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//앞에 2, 3번 문제가 엄청 괴랄했던 것에 비해, 4번은 상대적으로 쉬움

struct student {
	char* name;
	int firstStage;
	int interview;
	double sum;
};

int main()
{
	int N, M;
	char tmp[11];
	struct student* st;
	struct student tmp2;
	scanf("%d %d", &N, &M);
	getchar(); //getchar()사용하기

	//1. 구조체 포인터 선언 후 동적할당으로 N크기의 구조체 배열 선언 후 1단계 점수, 2단계 점수, 최종 점수 저장
	st = (struct student*)malloc(N * sizeof(struct student));
	for (int i = 0; i < N; i++)
	{
		st[i].sum = 0;
		scanf("%s %d %d", tmp, &st[i].firstStage, &st[i].interview); //name만 tmp로 먼저 맏고 그 다음 할당하는것만 신경써주면 됨
		getchar();
		st[i].sum += (st[i].firstStage * 7 + st[i].interview * 3) / 10.00; //최종 점수 계산
		st[i].name = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
		strcpy(st[i].name, tmp);
	}
	/*for (int i = 0; i < N; i++)
	{
		printf("%s %d %d\n", st[i].name, st[i].firstStage, st[i].interview); 중간점검
	}*/

	//2. 총점 높은 순으로 선별 -> 내림차순 하자!!
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (st[j].sum < st[j + 1].sum)
			{
				tmp2 = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp2;
			}
			if (st[j].sum == st[j + 1].sum)//1-1. 만약 총점 same -> 1차 점수 높은 사람이 먼저
			{
				if (st[j].firstStage < st[j + 1].firstStage)
				{
					tmp2 = st[j];
					st[j] = st[j + 1];
					st[j + 1] = tmp2;
				}
				if (st[j].firstStage == st[j + 1].firstStage) //1-2. 만약 1차 점수까지 same -> 이름 사전순(더 빠른 사람이 먼저 출력되어야 하니까)
				{
					if (strcmp(st[j].name, st[j + 1].name) > 0)
					{
						tmp2 = st[j];
						st[j] = st[j + 1];
						st[j + 1] = tmp2;
					}
				}
			}
		}
	}

	//3. 최종 출력
	for (int i = 0; i < M; i++)
	{
		printf("%s %d %d %.1f\n", st[i].name, st[i].firstStage, st[i].interview, st[i].sum);
		if (i == M - 1) //만약 M명 중 M등 출력하려할 때
		{
			if (st[i].firstStage == st[i + 1].firstStage && st[i].sum == st[i + 1].sum) //뒷사람이 1차 점수, 총점 다 같다면
			{
				M += 1; //M + 1로 뒷사람도 출력
			}
		}
	}
	printf("%d", M);

	//4. 해제

	return 0;
}