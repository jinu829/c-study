#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	int N;
	int lenstr;
	int min = 101;
	int minint;
	char A[101][101];

	//N�� ���� 
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(A[i]); //���� : scanf("%s", ~)���� ���� ������ ������ ���� �������� �Է¹���. bur gets�� ������ �־ ���� �Է��� �ֱ� ������ ��� �Է¹���.
		//���� : This is String (Enter�Է�) ���� scanf�� This�� ���� but gets�� This is String �� ����

		lenstr = strlen(A[i]); //gets�� �Է¹��� ���ڿ� A[i]�� ���̸� strlen�� ���� ����
		if (lenstr < min) //���̰� �ּ��� �迭�� ã�� ����
		{
			min = lenstr;
			minint = i;
		}
	}
	printf("%s", A[minint]);
	return 0;
}