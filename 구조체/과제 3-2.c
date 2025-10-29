#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct hotel_info { 
	char name[31];
	int grade;
	double critic;
	double distance;
	char breakfast;
}HOTEL;

int in_hotel_info(struct hotel_info* p);

void out_hotel_info(struct hotel_info* p, int N, int G, double D);

int main()
{
	HOTEL hotel[100];
	int count;
	int G;
	double D;
	count = in_hotel_info(hotel); //1. 호텔의 정보들을 입력받고, 호텔의 개수 count
	scanf("%d %lf", &G, &D);
	out_hotel_info(hotel, count, G, D); //2. 호텔 구조체 배열(구조체 배열의 첫 번째 주소), 개수, 원하는 호텔 등급, 호텔까지의 거리를 입력받고, 사전 순서 상 가장 빠른 호텔의 정보 출력하기
	return 0;
}

int in_hotel_info(struct hotel_info* p)
{
	int count = 0;
	for (HOTEL* q = p; q < p + 100; q++)
	{
		scanf("%s", q->name);
		if (strcmp(q->name, "0") == 0)
			break;
		scanf("%d %lf %lf %c", &q->grade, &q->critic, &q->distance, &q->breakfast);
		getchar();
		count++;
	}
	return count;
}

void out_hotel_info(struct hotel_info* p, int N, int G, double D)
{
	double max = -1;
	HOTEL tmp[100];
	HOTEL tmp2;
	int idx = 0;
	for (HOTEL* q = p; q < p + N; q++)
	{
		if (q->grade >= G && q->distance <= D) //2-1 : 먼저 G등급 이상이고 거리가 D이하인 호텔들만 추려서 새 구조체 배열에 넣기
		{
			tmp[idx++] = *q;
		}
	}
	for (int i = 0; i < idx; i++)//2-2 : G등급 이상이고 거리가 D 이하인 호텔을 순서대로 출력하기 위해, 먼저 호텔들 정렬
	{
		for (HOTEL* q = tmp; q < tmp + idx - 1; q++) 
		{
			if (q->critic < (q + 1)->critic)
			{
				tmp2 = *q;
				*(q) = *(q + 1);
				*(q + 1) = tmp2;
			}
			if (q->critic == (q + 1)->critic)
			{
				if (strcmp(q, q + 1) > 0) //평판도 동일 -> 사전 순서대로 하기 위해 추가 조건 도입
				{
					tmp2 = *q;
					*(q) = *(q + 1);
					*(q + 1) = tmp2;
				}
			}
		}
	}
	for (HOTEL* q = tmp; q < tmp + idx; q++)
	{
		printf("%s %d %.1f %.1f %c\n", q->name, q->grade, q->critic, q->distance, q->breakfast);
	}
}