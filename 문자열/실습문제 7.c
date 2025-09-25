#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int N;
	//일정한 숫자가 나올 때마다 일정한 문자열이 나와야 된다 -> one, two three등을 배열로!!
	char str[11][10] = { "","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" }; 
	char arr[5]; 
	int i = 0, j;
	int count = 0;
	scanf("%d", &N);
	//자릿수에 따라 THO, HUN출력 -> 자릿수를 알아야!
	//각 자릿수 또한 필요 -> 배열에 담기
	while (N != 0) //N의 자릿수를 구하는 코드
	{
		arr[i] = N % 10;
		i++;
		count++;
		N /= 10;
	}

	for (j = i; j >= 0; j--) //출력 -> 4자리수면 THO부터, 3자리수면 HUN부터, 2자리수면 TEN부터...
	{
		if (j == 4) //if j == 4 -> N이 4자리 숫자라면
		{
			printf("%s THO ", str[arr[j - 1]]);
		}
		if (j == 3)
		{
			if (arr[j - 1] == 0) //만약 0이라면 아무것도 출력하지 않아야 하니까
				continue;
			else
				printf("%s HUN ", str[arr[j - 1]]);
		}
		if (j == 2)
		{
			if (arr[j - 1] == 0)
				continue;
			else
				printf("%s TEN ", str[arr[j - 1]]);
		}
		if (j == 1)
		{
			if (arr[j - 1] == 0)
				continue;
			else
				printf("%s", str[arr[j - 1]]);
		}
	}
	return 0;
}