#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int main()
{
	char str[201], tmp[201], word[200][201], tmp2[201];
	gets(str);
	gets(tmp);
	int len = strlen(str);
	int idx = 0;
	int flag = 0;


	for (char* p = str; *p != '\0'; p++) //str을 단어 별로해서 word에 저장
	{
		if (*p == ' ')
			*p = '\0';
	}
	for (char* p = str; p < str + len; p++)
	{
		strcpy(word[idx++], p);
		p += strlen(p);
	}

	for (int i = 0; i < idx; i++) //일단 word[i]에 저장한 단어들 다 출력하기
	{
		printf("%s\n", word[i]);
		if (strcmp(word[i], tmp) == 0) //만약 두 번째 입력한 단어(tmp)와 중복된 단어가 있다면
		{
			flag = 1; //flag = 1;로 중복된 단어가 있다는 것 알리기
		}
	}
	if (flag == 0) //만약 중복된 단어가 없다면
	{
		printf("%s\n", tmp); //tmp도 출력

		strcpy(word[idx++], tmp); //tmp도 word배열에 넣기(이유는 아래에서)
	}

	for (int i = 0; i < idx; i++) //단어 단위로 정렬하기(사전순)
	{
		for (int j = 0; j < idx - 1; j++)
		{
			if (strcmp(word[j], word[j + 1]) > 0)
			{
				strcpy(tmp, word[j]); //중요!! 단어 정렬하는 코드
				strcpy(word[j], word[j + 1]);
				strcpy(word[j + 1], tmp);
			}
		}
	}

	strcpy(tmp2, word[0]); //출력 : 처음에는 널 문자가 없으므로 strcpy먼저 하기
	strcat(tmp2, " ");
	for (int i = 1; i < idx; i++)
	{
		strcat(tmp2, word[i]);
		strcat(tmp2, " ");
	}
	printf("%s", tmp2);
	return 0;
}

