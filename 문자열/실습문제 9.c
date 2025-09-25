#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int check(char* p);


//main 함수 -> 문자열을 입력받고, 문자열의 길이 측정하고, 문자열의 회문 여부 측정하면 끝!
//회문 여부를 어떻게 알 것인가?
int main()
{
	char str[31];
	gets(str); //str입력받기
	int lenstr = strlen(str); //str의 길이 측정
	printf("%d", lenstr);
	printf(" %d", check(str)); //1, 0둘 중 하나 출력
	return 0;
}

int check(char* p) //회문 여부를 구분하는 함수
{
	int lenp = strlen(p); //p와 정반대의 배열인 배열을 만들고 거기다가 strcmp를 사용하여 원래 배열과 비교를 해보자!
	char str2[31];
	int i;
	for (i = 0; i < lenp; i++) //p와 정반대의 배열을 만들기
	{
		str2[i] = p[lenp - i - 1];
	}
	str2[i] = '\0'; //strcmp의 정상 작동을 위해 마지막 부분에 널 문자 넣기
	if (strcmp(str2, p) == 0)
		return 1;
	else
		return 0;
}