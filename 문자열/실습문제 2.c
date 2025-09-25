#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	char arr[10] = { NULL };
	int i;
	int N;
	scanf("%d", &N);
	for (i = 0; i < 9; i++)
	{
		arr[i] = N % 10 + '0';
		/*
		정수 문자열로 바꾸는 법 -> 아스키 코드를 항상 생각할 것!

		정수 0을 문자 '0'으로 바꾸고 싶다면 아스키 코드상 '0'에 해당하는 숫자를 더하면 됨 -> +'0' 을 하면 됨!
		정수 1을 문자 '1'로 바꾸고 싶다면? -> 똑같이  +'0'  을 하면 됨

		만약 0을 a로 바꾸고 싶다면? +'a'를 하면 된다
		만약 1을 b로 바꾸고 싶다면? 역시나 +'a'를 하면 된다!
		*/
		if (N / 10 == 0)
		{
			break;
		}
		N /= 10;
	}
	printf("%s", arr);
	return 0;
}