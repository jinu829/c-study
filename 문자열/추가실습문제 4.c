#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	/* 
	   ���� ���ڿ� N���� ���� ������ �迭�� �Űܴ��, ������ ���ڿ��� ���̸� ���Ͽ�
	   ���� ���̰� �� ���ڿ��� ���� ���̰� ���� ���ڿ� ã��
	   (�׻� �̷��� ū Ʋ�� �� �����ô�!)
	*/

	int N;
	char str[10][101];
	int max = 0, maxint;
	int min = 101, minint;
	char tmp[101];
	scanf("%d", &N); //���� ���ڿ� ���� �Է¹ޱ�
	getchar(); //�߿�!!! getchar()������ ���Ͱ� �Ʒ� gets�Լ��� �� gets�Լ��� enter�� �ԷµǴ� �� �ֱ�
	for (int i = 0; i < N; i++)
	{
		gets(str[i]); //���ڿ� �Է¹ޱ�
		if (strlen(str[i]) > max) //���ڿ��� ���̰� ���ݱ��� ���� �͵� �� ���� ����, ���� ª���� üũ
		{
			max = strlen(str[i]);
			maxint = i;
		}
		if (strlen(str[i]) < min) 
		{
			min = strlen(str[i]);
			minint = i;
		}
	}

	/*
	  ���� ���� �� ���ڿ��� ���� ª�� ���ڿ��� ��������, �� ���ڿ����� 
	  ���������� ���� ���� �ܾ�� ���� ���� �ܾ �˾ƺ���
	  
	*/

	//printf("%s\n%s\n", str[maxint], str[minint]); 
	for (char* p = str[minint]; p < str[minint] + min; p++) //���� �� ���ڿ�, ���� ���� ���ڿ� ���� ���� �κ� �ι��ڷ� ġȯ
	{
		if (*p == ' ')
			*p = '\0';
	}
	for (char* p = str[maxint]; p < str[maxint] + max; p++)
	{
		if (*p == ' ')
			*p = '\0';
	}
	//printf("%s\n%s\n", str[maxint], str[minint]);
	strcpy(tmp, str[minint]); //ù �ܾ�� �ϴ� tmp�� �ֱ�
	for (char* p = str[minint]; p < str[minint] + min; p++) //�� �� tmp�� �� �ܾ�� ������ �ܾ�� ���ϸ鼭 ���������� ���� �� ������ üũ
	{
		if (strcmp(tmp, p) > 0)
		{
			strcpy(tmp, p); 
		}
		p += strlen(p);
	}
	printf("%s\n", tmp); //���� ���̰� ª�� ���ڿ����� ���� ���������� ���� �ܾ� ���� ���

	strcpy(tmp, str[maxint]);
	for (char* p = str[maxint]; p < str[maxint] + max; p++)
	{
		if (strcmp(tmp, p) < 0)
		{
			strcpy(tmp, p);
		}
		p += strlen(p);
	}
	printf("%s\n", tmp); //���� ���̰� �� ���ڿ����� ���� ���������� ���� �ܾ� ���� ���
	return 0;
}
