#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main()
{
	char str[201];
	char word[20][201]; //이차원 배열 생성
	int idx = 0;
	int len;
	char tmp[201];
	gets(str);

	len = strlen(str); //str의 길이를 미리 len이란 변수에 넣어두기
	// 단어별로 분리해서 이차원 배열에 넣기(까먹었다면 추가실습문제1 다시 복습하기)
	for (char* p = str; *p != '\0'; p++)
	{
		if (*p == ' ')
			*p = '\0';
	}
	

	for (char* p = str; p < str + len;) 
	{
		strcpy(word[idx++], p); 
		printf("%s\n", word[idx - 1]); //뽑은 단어 출력
		p += (strlen(p) + 1); 
	}


	for (int i = 0; i < idx; i++) //영어 사전순으로 정렬
	{
		for (int j = 0; j < idx - 1; j++)
		{
			if (strcmp(word[j], word[j + 1]) > 0) //만약 뒤에 께 사전순으로 더 빠르다면
			{
				strcpy(tmp, word[j]); //앞뒤 단어 스위칭
				strcpy(word[j], word[j + 1]);
				strcpy(word[j + 1], tmp);
			}
		}
	}
	for (int i = 0; i < idx; i++) //정렬한 단어 순서대로 출력
	{
		printf("%s ", word[i]);
	}
	return 0;
}