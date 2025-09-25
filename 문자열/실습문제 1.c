#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	char arr[20];
	int i;
	scanf("%s", arr);
	for (i = 0; i < 20; i++)
	{
		if (arr[i] == NULL) //%s로 받는 경우 문자열로 받은 것이므로 자동으로 맨 뒤에 NULL문자가 생성된다 -> 만약 NULL문자가 나온다면 문자열의 끝일 것이다!
		{
			break;
		}
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			printf("%c", arr[i]);
		}
	}
	return 0;
}