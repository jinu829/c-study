#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int check_w(char* p, char* q);

int main()
{
	int N;
	int M;
	char str[10][101] = { '\0' };
	int arr[10];
	char tmp[100];
	int tmparr;
	scanf("%d %d", &N, &M);
	getchar(); // getchar()�� gets�� enter�� �ȵ��� ����
	for (int i = 0; i < N; i++)
	{
		gets(str[i]);
	}
	for (int i = 0; i < N; i++) //check_w�Լ��� ������ ���ĺ��� ������ ������ ������ ������ �޾� arr[i]�� �ֱ�
	{
		arr[i] = check_w(str[i], str[i] + M); 
		//printf("%d\n", arr[i]); �߰�����
	}
	for (int i = 0; i < N; i++) //���� ���ķ� �������� ����
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				
				tmparr = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmparr;

				strcpy(tmp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], tmp);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 0) //0���� ��� ��� X
			break;
		else
			printf("%s\n", str[i], arr[i]);
	}
	return 0;
}

int check_w(char* p, char* q) //���� ���ĺ��� ������ ������ ������ ������ ���� ��ȯ
{
	int count = 0;
	for (char* i = p; i < q; i++)
	{
		if (*i == '\0')
			break;
		if (!('a' <= *i && *i <= 'z' || 'A' <= *i && *i <= 'Z' || *i == ' ')) //���� ���� ���ĺ��� ������ ������ ���ڶ��
			count++;
	}
	return count;
}

/*
	5 15
	1 year is 365 days.
	How are you doing?
	**Notice**
	Winter is coming
	1+1=2
*/
