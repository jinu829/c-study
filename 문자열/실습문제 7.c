#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int N;
	//������ ���ڰ� ���� ������ ������ ���ڿ��� ���;� �ȴ� -> one, two three���� �迭��!!
	char str[11][10] = { "","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" }; 
	char arr[5]; 
	int i = 0, j;
	int count = 0;
	scanf("%d", &N);
	//�ڸ����� ���� THO, HUN��� -> �ڸ����� �˾ƾ�!
	//�� �ڸ��� ���� �ʿ� -> �迭�� ���
	while (N != 0) //N�� �ڸ����� ���ϴ� �ڵ�
	{
		arr[i] = N % 10;
		i++;
		count++;
		N /= 10;
	}

	for (j = i; j >= 0; j--) //��� -> 4�ڸ����� THO����, 3�ڸ����� HUN����, 2�ڸ����� TEN����...
	{
		if (j == 4) //if j == 4 -> N�� 4�ڸ� ���ڶ��
		{
			printf("%s THO ", str[arr[j - 1]]);
		}
		if (j == 3)
		{
			if (arr[j - 1] == 0) //���� 0�̶�� �ƹ��͵� ������� �ʾƾ� �ϴϱ�
				continue;
			else
				printf("%s HUN ", str[arr[j - 1]]);
		}
		if (j == 2)
		{
			if (arr[j - 1] == 0)
				continue;
			else
				printf("%s TEN ", str[arr[j - 1]]);
		}
		if (j == 1)
		{
			if (arr[j - 1] == 0)
				continue;
			else
				printf("%s", str[arr[j - 1]]);
		}
	}
	return 0;
}