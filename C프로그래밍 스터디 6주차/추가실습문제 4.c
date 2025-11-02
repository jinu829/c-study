#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)  

//추가실습문제 3번이 구조체 문제였다면, 4번은 사실상 문자열 문제

struct string {
	char* str; 
	int words; 
};

int main()
{
	struct string* st; 
	struct string tmp2;
	int N;
	int len;
	char tmp[101];
	scanf("%d", &N);
	getchar();
	st = (struct string*)malloc(N * sizeof(struct string)); //1. 구조체  포인터 선언 후 동적 할당으로 N크기의 구조체 배열 만들기
	if (st == NULL) //오류 확인 까먹지 말기
	{
		printf("not enough memory!!");
		return -1;
	}
	for (int i = 0; i < N; i++) //2. 그 후 학교 ppt의 동적 할당 사용하여 문자열 할당 부분과 똑같이 하면됨.
	{
		gets(tmp);//2-1. 정적 배열 선언
		st[i].str = (char*)malloc((strlen(tmp) + 1) * sizeof(char)); //2-2. 그 후 정적 배열 길이 + 1만큼 동적 배열 할당
		if (st[i].str == NULL)
		{
			printf("not enough memory!!");
			return -1;
		}
		strcpy(st[i].str, tmp); //2-3. 정적 배열에 입력한 걸 그대로 동적 할당한 배열에 복사
	}
	for (int i = 0; i < N; i++) //3. 각 문자열의 단어 개수 세서 words에 저장
	{
		len = strlen(st[i].str);
		st[i].words = 0;
		for (char* p = st[i].str; p < st[i].str + len; p++)
		{
			if (*p == ' ') //띄어쓰기 개수 + 1이 곧 단어 개수니까
				st[i].words++;
		}
		st[i].words++;
	}
	for (int i = 0; i < N; i++) //이제 버블 정렬 사용해서 단어 개수 순으로 정렬해주면 됨.(문자열에서 늘 하던거)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (st[j].words < st[j + 1].words)
			{
				tmp2 = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp2;
			}
		}
	}
	for (int i = 0; i < N; i++) //이제  문자열과 단어 순 출력
	{
		printf("%s %d\n", st[i].str, st[i].words);
	}
	for (int i = 0; i < N; i++) //동적 할당한 부분들 해제
		free(st[i].str);
	free(st);
	return 0;
}