#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void StringAdd(char arr[], char ch, int index);

int Convertor(char x);

int main()
{

	/*
	   문제를 간단히 정리하면
	   나올 수 있는 네 가지 상황
	   1. 짝 + 짝
	   2. 홀 + 홀
	   3. 홀 + 짝
	   4. 짝 + 홀
	   근데 3, 4번은 문제에서 아무 짓도 하지 않아도 된다 했으므로
	   우리는 1, 2번만 신경쓰면 된다.
	*/

	char str[20] = { '\0' };
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < len - 1; i++)
	{
		if (Convertor(str[i]) % 2 == 0) //1번 상황 -> 사이에 * 심기
		{
			if (Convertor(str[i + 1]) % 2 == 0)
			{
				StringAdd(str, '*', i + 1);
				len++;
				i++;
			}
		}
		if (Convertor(str[i]) % 2 != 0) //2번 상황 -> 사이에 + 심기
		{
			if (Convertor(str[i + 1]) % 2 != 0)
			{
				StringAdd(str, '+', i + 1);
				len++;
				i++;
			}
		}
	}
	printf("%s", str);

	return 0;
}

void StringAdd(char arr[], char ch, int index) 
{
	for (int i = strlen(arr) + 1; i > index; i--) //왜 시작위치가 int i = strlen(arr) + 1 일까? i = strlen(arr)이 아니라?
	{
		arr[i] = arr[i - 1]; //인덱스번째 원소부터 한 칸씩 뒤로 미루기
	}
	arr[index] = ch; //인덱스 부분에 '+'첨가
}

int Convertor(char x)
{
	return atoi(&x); //atoi말고 아스키 코드를 써도 가능
}