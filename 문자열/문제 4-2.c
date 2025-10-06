#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int check_w(char* p, char* q);

int main()
{
	int N;
	int M;
	char str[10][101] = { '\0' };
	int arr[10];
	char tmp[100];
	int tmparr;
	scanf("%d %d", &N, &M);
	getchar(); // getchar()로 gets에 enter가 안들어가게 막기
	for (int i = 0; i < N; i++)
	{
		gets(str[i]);
	}
	for (int i = 0; i < N; i++) //check_w함수로 각각의 알파벳과 공백을 제외한 문자의 개수를 받아 arr[i]에 넣기
	{
		arr[i] = check_w(str[i], str[i] + M); 
		//printf("%d\n", arr[i]); 중간점검
	}
	for (int i = 0; i < N; i++) //버블 정렬로 내림차순 정리
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				
				tmparr = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmparr;

				strcpy(tmp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], tmp);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 0) //0개인 경우 출력 X
			break;
		else
			printf("%s\n", str[i], arr[i]);
	}
	return 0;
}

int check_w(char* p, char* q) //영어 알파벳과 공백을 제외한 문자의 개수를 세어 반환
{
	int count = 0;
	for (char* i = p; i < q; i++)
	{
		if (*i == '\0')
			break;
		if (!('a' <= *i && *i <= 'z' || 'A' <= *i && *i <= 'Z' || *i == ' ')) //만약 영어 알파벳과 공백을 제외한 문자라면
			count++;
	}
	return count;
}

/*
	5 15
	1 year is 365 days.
	How are you doing?
	**Notice**
	Winter is coming
	1+1=2
*/
