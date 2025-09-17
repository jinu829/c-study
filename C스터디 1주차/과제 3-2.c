#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void PRT(int n, char* p);

int main()
{
	char str[100];
	char* i;
	int count = 1, max = 0;
	char* maxchar = NULL;
	for (i = str; i < str + 100; i++) //#이 나오기 전까지 원소를 받고 배열에 저장
	{
		scanf("%c", i); 
		if (*i == '#')
			break;
	}
	for (char* j = str; *j != '#'; j++) // 소문자로 구성된 단어들 출력, 소문자가 나올 때까지는 계속 출력, count 하다가 대문자가 나오면 리셋
	{
		if (*j >= 'a' && *j <= 'z') //만약 j가 소문자라면
		{
			if (*(j + 1) >= 'a' && *(j + 1) <= 'z')
			{
				count++;
				printf("%c", *j);
			}
			else
			{
				printf("%c", *j);
				printf("\n");
				if (count > max)
				{
					max = count;
					maxchar = j - count + 1; //단어의 처음 주소를 maxchar로 설정
				}
				count = 1;
			}
		}
	}
	printf("%d %c\n", max, *maxchar);
	PRT(max, maxchar); //PRT의 n, p에 각각 max, maxchar넣기
	return 0;
}

void PRT(int n, char* p) //p의 주소부터 n개 원소 출력하기
{
	for (char* i = p; i < p + n; i++)
	{
		printf("%c", *i);
	}
}