#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	/* 
	   먼저 문자열 N개를 각각 이차원 배열에 옮겨담고, 각각의 문자열의 길이를 비교하여
	   가장 길이가 긴 문자열과 가장 길이가 작은 문자열 찾기
	   (항상 이렇게 큰 틀을 잘 잡읍시다!)
	*/

	int N;
	char str[10][101];
	int max = 0, maxint;
	int min = 101, minint;
	char tmp[101];
	scanf("%d", &N); //받을 문자열 개수 입력받기
	getchar(); //중요!!! getchar()없으면 엔터가 아래 gets함수에 들어가 gets함수에 enter만 입력되니 꼭 넣기
	for (int i = 0; i < N; i++)
	{
		gets(str[i]); //문자열 입력받기
		if (strlen(str[i]) > max) //문자열의 길이가 지금까지 나온 것들 중 가장 긴지, 가장 짧은지 체크
		{
			max = strlen(str[i]);
			maxint = i;
		}
		if (strlen(str[i]) < min) 
		{
			min = strlen(str[i]);
			minint = i;
		}
	}

	/*
	  이제 가장 긴 문자열과 가장 짧은 문자열을 구했으니, 각 문자열에서 
	  사전적으로 가장 느린 단어와 가장 빠른 단어를 알아보기
	  
	*/

	//printf("%s\n%s\n", str[maxint], str[minint]); 
	for (char* p = str[minint]; p < str[minint] + min; p++) //가장 긴 문자열, 가장 작은 문자열 각각 띄어쓰기 부분 널문자로 치환
	{
		if (*p == ' ')
			*p = '\0';
	}
	for (char* p = str[maxint]; p < str[maxint] + max; p++)
	{
		if (*p == ' ')
			*p = '\0';
	}
	//printf("%s\n%s\n", str[maxint], str[minint]);
	strcpy(tmp, str[minint]); //첫 단어는 일단 tmp에 넣기
	for (char* p = str[minint]; p < str[minint] + min; p++) //그 후 tmp에 들어간 단어랑 나머지 단어랑 비교하면서 사전적으로 누가 더 빠른지 체크
	{
		if (strcmp(tmp, p) > 0)
		{
			strcpy(tmp, p); 
		}
		p += strlen(p);
	}
	printf("%s\n", tmp); //가장 길이가 짧은 문자열에서 가장 사전적으로 느린 단어 먼저 출력

	strcpy(tmp, str[maxint]);
	for (char* p = str[maxint]; p < str[maxint] + max; p++)
	{
		if (strcmp(tmp, p) < 0)
		{
			strcpy(tmp, p);
		}
		p += strlen(p);
	}
	printf("%s\n", tmp); //가장 길이가 긴 문자열에서 가장 사전적으로 빠른 단어 마저 출력
	return 0;
}
