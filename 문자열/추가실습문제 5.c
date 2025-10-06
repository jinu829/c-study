#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main()
{
	int N, M1, M2;
	int max = 0, min = 101;
	int j = 0, k = 0, idx = 0;
	int first = 1;
	int count = 0;
	char str[20][101];
	char maxstr[101];
	char minstr[101];
	char temp[101];
	char finish1[101] = { '\0' };
	char finish2[101] = { '\0' };
	char realfinish[101] = { '\0' };

	scanf("%d %d %d", &N, &M1, &M2); 
	getchar();
	for (int i = 0; i < N; i++) //가장 긴 문자열과 가장 짧은 문자열 각각 구하기(문제 4번과 똑같)
	{
		gets(str[i]);
		if (strlen(str[i]) > max)
		{
			max = strlen(str[i]);
			strcpy(maxstr, str[i]);
		}
		if (strlen(str[i]) < min)
		{
			min = strlen(str[i]);
			strcpy(minstr, str[i]);
		}
	}
	printf("%s\n", maxstr); //가장 긴 문자열과 가장 짧은 문자열 출력
	printf("%s\n", minstr);
	while (j <= strlen(maxstr)) 
	{
		if (maxstr[j] != ' ' && maxstr[j] != '\0') // M1번째 단어 구하기
		{
			temp[idx++] = maxstr[j]; //공백이 아니면 일단 그냥 temp에 담기
		}
		else
		{
			temp[idx] = '\0'; //공백 부분을 널 문자로 바꾸기(문자열을 단어로 나눌 때처럼 -> 추가실습문제 1번 참고)
			if (count == M1) //만약 M1번째 단어라면
			{
				strcat(finish1, temp); //finish1에 붙이기 (finish1은 이미 모든 항이 '\0'처리되어있기에 그냥 strcat써도 됨)
			}
			idx = 0;
			count++;
		}
		j++;
	}
	count = 0;
	j = 0;
	idx = 0;
	while (j <= strlen(minstr)) //비슷하게 M2번째 단어 구하기
	{
		if (minstr[j] != ' ' && minstr[j] != '\0')
		{
			temp[idx++] = minstr[j];
		}
		else
		{
			temp[idx] = '\0';
			if (count == M2)
			{
				strcat(finish2, temp);
			}
			idx = 0;
			count++;
		}
		j++;
	}
	if (strcmp(finish1, finish2) < 0) //사전 순서에 따라 순서 다르게 붙이기
	{
		strcat(realfinish, finish1);
		strcat(realfinish, finish2);
	}
	if (strcmp(finish1, finish2) > 0)
	{
		strcat(realfinish, finish2);
		strcat(realfinish, finish1);
	}
	printf("%s", realfinish); //붙인 문자열 출력
	return 0;
}

/*
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december
*/