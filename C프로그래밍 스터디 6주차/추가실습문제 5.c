#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

//역시나 동적 할당을 가장한 문자열 문제

struct string {
	char* str;
	int words;
};

int main(void)
{
	struct string* st = NULL; // = NULL쓰는 것 추천!!
	struct string tmp2;
	char tmp[101];
	char** word;
	char* address;
	int N;
	int max = 0, maxint;
	int count = 0;
	scanf("%d", &N);
	getchar(); //바로 다음 받는게 gets니까 getchar()써주고
	st = (struct string*)malloc(N * sizeof(struct string)); // 1. 구조체  포인터 선언 후 동적 할당으로 N크기의 구조체 배열 만들기
	if (st == NULL)
	{
		printf("not enough memory!");
		return -1;
	}

	//2. 그 후 학교 ppt의 동적 할당 사용하여 문자열 할당 부분과 똑같이 하면됨. 4번이랑 거의 똑같
	for (int i = 0; i < N; i++) 
	{
		st[i].words = 0;
		gets(tmp);
		st[i].str = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
		if (st[i].str == NULL)
		{
			printf("not enough memory!");
			return -1;
		}
		strcpy(st[i].str, tmp);
		for (char* p = st[i].str; *p != '\0'; p++) //다만 여기서는 4번과 다르게 단어 개수까지 한번에 저장, 어떤 방법이 더 좋냐는 없음. 그냥 편한 방법으로 하기
		{
			if (*p == ' ')
			{
				st[i].words++;
			}
		}
		st[i].words++;
	}

	//3. 버블 정렬 이용해서 단어 개수 순으로 정렬
	for (int i = 0; i < N; i++) 
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

	//4. 이제부터 4번과 다른 부분, 먼저 각 문자를 단어로 나누어 2차원 배열(word)에 저장
	for (int i = 0; i < N; i++)
	{
		max = 0;
		word = (char**)malloc(st[i].words * sizeof(char*)); //관련 코드는 문자열 추가실습문제 1번 참고, 거기서 동적 할당하는 것만 조금 변형됨
		if (word == NULL)
		{
			printf("not enough memory!");
			return -1;
		}
		printf("%s ", st[i].str);
		for (char* p = st[i].str; *p != '\0'; p++)
		{
			if (*p == ' ')
				*p = '\0';
		}

		address = st[i].str; //st[i].str의 시작 주소 저장. 왜 이렇게? 나중에 해제 작업 위해서

		for (int j = 0; j < st[i].words; j++)
		{
			word[j] = (char*)malloc(strlen(st[i].str) * sizeof(char));
			if (word[j] == NULL)
			{
				printf("not enough memory!");
				return -1;
			}
			strcpy(word[j], st[i].str);
			st[i].str = st[i].str + strlen(st[i].str) + 1;
		}

		st[i].str = address; //작업 다 끝내고 st[i].str의 주소를 다시 처음 주소로 바꾸기 -> 왜? 나중에 free(st[i].str)을 해야할 텐데, free에서 인자는 꼭 처음에 '동적 할당할 때 할당된 주소'여야 함!
		//st[i].str = (char*)malloc((strlen(tmp) + 1) * sizeof(char));이부분에서 할당받은 주소. 따라서 본 코드에서는 이렇게  st[i].str의 주소값을 다시 조정해줌
		//저는 이게 최선이었지만 이것 말고도 방법이 많이 있을테니 한번 찾아보시면 좋을 것 같습니다!!

		//5. 각 문자열 마다 저장된 단어 중 중복 횟수가 가장 많은 단어를 찾기
		for (int j = 0; j < st[i].words; j++)
		{
			count = 0;
			for (int k = 0; k < st[i].words; k++) //5-1. 중복된 단어들 찾는 코드
			{
				if (strcmp(word[j], word[k]) == 0)
				{
					count++;
				}
			}
			//printf("%d\n", count);
			if (count > max) //5-2 : 중복 횟수가 가장 많은 코드 찾기
			{
				max = count;
				maxint = j;
			}
			if (count == max)
			{
				if (strcmp(word[j], word[maxint]) < 0)
				{
					maxint = j;
				}
			}
		}
		//printf("%d\n", maxint);
		printf("%d %s %d\n", st[i].words, word[maxint], max); //해당 문자열, 문자열의 단어 수, 중복 횟수가 가장 많은 단어, 해당 단어의 중복 횟수 출력

		for (int k = 0; k < st[i].words; k++) {
			free(word[k]);
		}
		free(word);
	}

	for (int i = 0; i < N; i++) { //6. 동적 할당한 부분들 해제 (word는 for문 안에서 동적 할당을 했기에 for 
		free(st[i].str);
	}
	free(st);
	return 0;
}
