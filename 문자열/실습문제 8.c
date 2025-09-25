#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	char A[51];
	char B[51];
	//A, B랑 비교해서 사전순으로 더 '늦는'문장 먼저 출력 -> 사전순으로 뭐가 더 빠른지를 strcmp를 통해서 알아보자!!
	gets(A);
	gets(B);
	if (strcmp(A, B) > 0) //strcmp(A, B) > 0 : A가 B보다 사전순으로 늦은 경우
	{
		printf("%s%s", A, B);
	}
	if (strcmp(A, B) <= 0) //strcmp(A, B) < 0 : A가 B보다 사전순으로 빠른 경우, strcmp(A, B) == 0 : A가 B랑 완전히 같을 경우
	{
		printf("%s%s", B, A);
	}
	return 0;
}