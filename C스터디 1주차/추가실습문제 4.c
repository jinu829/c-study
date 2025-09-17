#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int input(int* p); // 함수 정의

int* sel_next(int* p, int N, int M);

int number(int* p, int* q);

int main(void)
{
	int arr[100];
	int N;
	int M;
	int* last = NULL;
	int total;
	N = input(arr); // 배열 원소의 개수를 N에 입력
	scanf("%d", &M); //M입력받기
	last = sel_next(arr, N, M); // sel_next함수를 이용하여 증가가 끝나는 시점을 last에 입력받기
	total = number(arr + M, last); // 배열 원소들을 합하여 total에 저장하기
	printf("%d", total); //total출력
	return 0;
}

int input(int* p)
{
	int count = 0;
	for (int* i = p; i < p + 100; i++)
	{
		scanf("%d", i);
		if (*i == -1)
			break;
		count++;
	}
	return count;
}

int* sel_next(int* p, int N, int M)
{
	for (int* q = p + M; q < p + N; q++)
	{
		if (*(q + 1) < *q) // 만약 q+1의 값의 q보다 작다면(증가가 끝남)  q의 위치 반환
			return q;
	}
	return p + N - 1; //만약 -1전까지 계속 증가하면, 마지막 원소의 주소 반환
}

int number(int* p, int* q)
{
	int total = 0; //전부 다 합한 값을 담을 변수

	for (int* i = p; i <= q; i++)
	{
		total *= 10;
		total += *i;
	}
	return total;
}
