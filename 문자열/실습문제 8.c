#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	char A[51];
	char B[51];
	//A, B�� ���ؼ� ���������� �� '�ʴ�'���� ���� ��� -> ���������� ���� �� �������� strcmp�� ���ؼ� �˾ƺ���!!
	gets(A);
	gets(B);
	if (strcmp(A, B) > 0) //strcmp(A, B) > 0 : A�� B���� ���������� ���� ���
	{
		printf("%s%s", A, B);
	}
	if (strcmp(A, B) <= 0) //strcmp(A, B) < 0 : A�� B���� ���������� ���� ���, strcmp(A, B) == 0 : A�� B�� ������ ���� ���
	{
		printf("%s%s", B, A);
	}
	return 0;
}