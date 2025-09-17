#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

void input(int* p, int M); // 함수 정의

int* sel_max(int* p, int M);

void output(int* p, int N);

int main(void)
{
	int in[100], out[100], * max, i, N, M; //변수 정의
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		input(in, M); //M개의 정수 입력하기
		max = sel_max(in, M); //중복 횟수가 최대인 원소 중 첫 번째 원소의 주소를 max에 대입하기
		out[i] = *max; //나온 주소를 out[i]에 저장
	}
	output(out, N);
	return 0;
}

void input(int* p, int M) // input함수 설계
{
	for (int* q = p; q < p + M; q++) //*p가 가리키는 주소부터 M개의 정수 입력하기
	{
		scanf("%d", q);
	}
}

int* sel_max(int* p, int M)
{
	int max = 0; //중복 횟수가 최대인지를 확인하는 변수
	int* maxint = NULL; //중복 횟수가 최대인 원소의 주소를 담을 변수
	int count = 0; // 중복 횟수를 세는 변수

	for (int* q = p; q < p + M; q++) //중복인 원소 개수를 세는 함수
	{
		count = 0;
		for (int* i = p; i < p + M; i++)
		{
			if (*i == *q)
			{
				count++;
				if (count > max) //만약 count>max라면 -> 중복횟수가 기존 최대보다 더 많다면
				{
					max = count;
					maxint = q;
				}
			}
		}
	}
	return maxint;
}

void output(int* p, int N) //output함수
{
	for (int* q = p; q < p + N; q++) //N개의 정수 출력
	{
		printf(" %d", *q);
	}
}
