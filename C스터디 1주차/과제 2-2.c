#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int passengerN(int n);

void rebooking(int* ar);

int changeseat(int* ar);

int main()
{
	int N;
	int ar[21] = { '\0' }; // = { '\0' }이건 왜 한 걸까요?
	scanf("%d", &N);

	for (int* i = ar; i < ar + N; i++) //승객 수 입력
	{
		scanf("%d", i); 
	}
	if (passengerN(N) == -1) // 만약 승객 수가 부족하다면
		printf("-1");
	else // 승객 수가 충분하다면
	{
		printf("0\n"); //0출력

		rebooking(ar); //중복 확인 하고, 바꾸고

		for (int* i = ar; i < ar + N; i++) // 출력
		{
			printf("%d ", *i);
		}
	}

	return 0;
}

int passengerN(int n) 
{
	if (n >= 5)
		return 0;
	else
		return -1;
}

void rebooking(int* ar) 
{
	for (int* i = ar; *i != '\0'; i++) 
	{
		for (int* j = ar; *j != '\0'; j++) //중복인지 확인하고, 만약 중복이다? 바꾸기(changeseat함수 호출)
		{
			if (*i == *j)
			{
				if (i != j) //중복인 것 중 첫 번째가 아닌 것을 바꿔야 하기 때문에 조건문 작성
				{
					*j = changeseat(ar); //j가 중복되서 문제인 부분 : changeseat으로 바꾼 수 대입
				}
			}
		}
	}
}

int changeseat(int* ar) //배열에 없는 값 중 가장 작은 값 : 1부터 시작해서 중복된 값이 있으면 1 추가하고, 반복하고... 충분히 반복하면 원하는 값이 나오겠네?
{ 
	int count = 1;
	for (int* i = ar; *i != '\0'; i++)
	{
		for (int* j = ar; *j != '\0'; j++)
		{
			if (*j == count)
				count++;
		}
	}
	return count; //j값에 대입되는 값
}