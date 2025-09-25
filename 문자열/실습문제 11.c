#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	char str1[81];
	char str2[11];
	gets(str1); //str1, str2입력받기
	gets(str2);
	int lenstr1 = strlen(str1); //문자열 길이 추출하기
	int lenstr2 = strlen(str2); 
	int standard = 0;
	int flag = 0;
	printf("%d", lenstr1); //첫 번째 문자열 길이 출력

	for (int i = 0; i < lenstr1; i++) //str2가 str1에 포함되는가? 아닌가?
	{
		for (int j = i; j < i + lenstr2; j++) //이게 무슨 범위?
		{
			if (str1[j] != str2[j - i])
				standard++;
		}
		if (standard == 0) //
		{
			printf(" 1");
			flag = 1;
			break;
		}
		standard = 0;
	}
	if (flag == 0)
	{
		printf(" 0");
	}
	return 0;
}
