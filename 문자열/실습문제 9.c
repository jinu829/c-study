#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int check(char* p);


//main �Լ� -> ���ڿ��� �Է¹ް�, ���ڿ��� ���� �����ϰ�, ���ڿ��� ȸ�� ���� �����ϸ� ��!
//ȸ�� ���θ� ��� �� ���ΰ�?
int main()
{
	char str[31];
	gets(str); //str�Է¹ޱ�
	int lenstr = strlen(str); //str�� ���� ����
	printf("%d", lenstr);
	printf(" %d", check(str)); //1, 0�� �� �ϳ� ���
	return 0;
}

int check(char* p) //ȸ�� ���θ� �����ϴ� �Լ�
{
	int lenp = strlen(p); //p�� ���ݴ��� �迭�� �迭�� ����� �ű�ٰ� strcmp�� ����Ͽ� ���� �迭�� �񱳸� �غ���!
	char str2[31];
	int i;
	for (i = 0; i < lenp; i++) //p�� ���ݴ��� �迭�� �����
	{
		str2[i] = p[lenp - i - 1];
	}
	str2[i] = '\0'; //strcmp�� ���� �۵��� ���� ������ �κп� �� ���� �ֱ�
	if (strcmp(str2, p) == 0)
		return 1;
	else
		return 0;
}