#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	char str[101];
	char words[100][101];
	int len;
	int idx = 0;
	gets(str);
	len = strlen(str);
	// !!!!중요!!!! 단어별로 분리해서 이차원 배열에 넣는 법
	for (char* p = str; *p != '\0'; p++) // 단어는 띄어쓰기로 분리 : 띄어쓰기 부분을 먼저 널문자로 바꾸기(이유는 다음 for문에)
	{
		if (*p == ' ')
			*p = '\0';
	}

	for (char* p = str; p < str + len; p++)
	{
		strcpy(words[idx++], p); //널문자로 이전에 바꿨기에 strcpy로 딱 단어만 뽑아서 word에 복사 (strcpy는 널 문자까지 복사)
		p += strlen(p);//다음 단어의 초항으로 점프
	}

	for (int i = 0; i < idx; i++) // 이제 단어별로 word에 저장했으니, 사전적 순서가 가장 빠른 단어를 출력해야함
	{ //여기서는 word배열에 있는 단어들을 사전순으로 오름차순으로 배열하여 해결

		for (int j = 0; j < idx - 1; j++)
		{
			if (strcmp(words[j], words[j + 1]) > 0) //strcmp이용(strcmp는 앞 단어가 사전순으로 더 느리면 양수 반환)
			{
				strcpy(str, words[j]); // words[j]와 words[j + 1]의 문자열을 서로 스위칭하는 코드(자주 쓸 예정)
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], str);
			}
		}
	}
	printf("%s", words[0]); //정렬 후 가장 앞에 온 단어 출력
	return 0;
}
