#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int input(int* p);

int* sel_next(int* p);

int number(int* p, int* q);

int main(void)
{
	int arr[100];
	int N;
	int M;
	int* last = NULL;
	int total;
	N = input(arr);
	for (int* q = arr; q < arr + N; ) //처음부터 시작해서 증가하다가 감소하는 부분 반환, 반환한 부분부터 시작, 증가하다가 감소하는 부분 반환....... -1 나올 때까지
	{
		if (q == arr + N - 1)
			break;
		last = sel_next(q); //마지막 주소를 sel_next함수로 지정
		total = number(q, last); //number함수 이용해서 한 숫자로 만들기
		printf("%d\n", total);
		q = last; //반환한 부분부터 시작
	}
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

int* sel_next(int* p) //첫번째 숫자 두번째 숫자  1. 감소하면 - 감소가 끝날 때까지, 2. 증가하면, 증가가 끝날 때까지
{
	int flag;
	int* q;
	if (*p > *(p + 1)) //먼저 첫번째 숫자와 두 번째 숫자가 감소하는지, 증가하는지를 봐야겠다!
		flag = 0;
	if (*p < *(p + 1))
		flag = 1;
	if (flag == 0) //감소하는 경우
	{
		for (q = p; *q != -1; q++) //감소가 끝나는 지점까지 반복, 감소가 끝나는 지점 주소 반환
		{
			if (*q < *(q + 1))
				return q;
		}
		return q - 1; //만약 -1부분까지 감소가 끝나지 않는다면, -1 바로 직전 주소를 반환
	}
	if (flag == 1) // 증가하는 경우
	{
		for (q = p; *q != -1; q++) //증가가 끝나는 지점까지 반복, 증가가 끝나는 지점 주소 반환
		{
			if (*q > *(q + 1)) 
				return q;
		}
		return q - 1; //만약 -1부분까지 증가가 끝나지 않는다면, -1 바로 직전 주소를 반환
	}
}

int number(int* p, int* q)
{
	int total = 0;
	for (int* i = p; i <= q; i++)
	{
		total *= 10;
		total += *i;
	}
	return total;
}