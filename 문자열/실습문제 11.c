#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	char str1[81];
	char str2[11];
	gets(str1); //str1, str2�Է¹ޱ�
	gets(str2);
	int lenstr1 = strlen(str1); //���ڿ� ���� �����ϱ�
	int lenstr2 = strlen(str2); 
	int standard = 0;
	int flag = 0;
	printf("%d", lenstr1); //ù ��° ���ڿ� ���� ���

	for (int i = 0; i < lenstr1; i++) //str2�� str1�� ���ԵǴ°�? �ƴѰ�?
	{
		for (int j = i; j < i + lenstr2; j++) //�̰� ���� ����?
		{
			if (str1[j] != str2[j - i])
				standard++;
		}
		if (standard == 0) //
		{
			printf(" 1");
			flag = 1;
			break;
		}
		standard = 0;
	}
	if (flag == 0)
	{
		printf(" 0");
	}
	return 0;
}
