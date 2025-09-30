#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	char str1[100] = "Hello";
	char str2[100] = "World";
	char str3[100];

	printf("%d\n", strlen(str1));

	strcpy(str3, str1); //str3에 str1복사
	printf("%s\n", str3);

	strcat(str3, " "); // 띄어쓰기 붙이기
	strcat(str3, str2); //뒤에 str2붙이기
	printf("%s\n", str3);

	strcpy(str1, str2); //맨 처음 슬라이드에서 질문한 문자열을 바꾸는 방법
	if (strcmp(str1, str2) == 0) //str1과 str2가 같기에 0을 반환
		printf("they are same\n");

	strcpy(str3, "30"); //str3의 첫번째 칸에 문자열 30 복사
	printf("%d", atoi(str3)); //정수 30출력
	//strcpy, strcat은 문자열 복사, 붙이기 후 자동으로 '\0'문자를 붙여준다.
}


