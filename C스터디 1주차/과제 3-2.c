#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void PRT(int n, char* p);

int main()
{
	char str[100];
	char* i;
	int count = 1, max = 0;
	char* maxchar = NULL;
	for (i = str; i < str + 100; i++) //#�� ������ ������ ���Ҹ� �ް� �迭�� ����
	{
		scanf("%c", i); 
		if (*i == '#')
			break;
	}
	for (char* j = str; *j != '#'; j++) // �ҹ��ڷ� ������ �ܾ�� ���, �ҹ��ڰ� ���� �������� ��� ���, count �ϴٰ� �빮�ڰ� ������ ����
	{
		if (*j >= 'a' && *j <= 'z') //���� j�� �ҹ��ڶ��
		{
			if (*(j + 1) >= 'a' && *(j + 1) <= 'z')
			{
				count++;
				printf("%c", *j);
			}
			else
			{
				printf("%c", *j);
				printf("\n");
				if (count > max)
				{
					max = count;
					maxchar = j - count + 1; //�ܾ��� ó�� �ּҸ� maxchar�� ����
				}
				count = 1;
			}
		}
	}
	printf("%d %c\n", max, *maxchar);
	PRT(max, maxchar); //PRT�� n, p�� ���� max, maxchar�ֱ�
	return 0;
}

void PRT(int n, char* p) //p�� �ּҺ��� n�� ���� ����ϱ�
{
	for (char* i = p; i < p + n; i++)
	{
		printf("%c", *i);
	}
}