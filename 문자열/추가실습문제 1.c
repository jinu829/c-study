#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	char str[101];
	char words[100][101];
	int len;
	int idx = 0;
	gets(str);
	len = strlen(str);
	// !!!!�߿�!!!! �ܾ�� �и��ؼ� ������ �迭�� �ִ� ��
	for (char* p = str; *p != '\0'; p++) // �ܾ�� ����� �и� : ���� �κ��� ���� �ι��ڷ� �ٲٱ�(������ ���� for����)
	{
		if (*p == ' ')
			*p = '\0';
	}

	for (char* p = str; p < str + len; p++)
	{
		strcpy(words[idx++], p); //�ι��ڷ� ������ �ٲ�⿡ strcpy�� �� �ܾ �̾Ƽ� word�� ���� (strcpy�� �� ���ڱ��� ����)
		p += strlen(p);//���� �ܾ��� �������� ����
	}

	for (int i = 0; i < idx; i++) // ���� �ܾ�� word�� ����������, ������ ������ ���� ���� �ܾ ����ؾ���
	{ //���⼭�� word�迭�� �ִ� �ܾ���� ���������� ������������ �迭�Ͽ� �ذ�

		for (int j = 0; j < idx - 1; j++)
		{
			if (strcmp(words[j], words[j + 1]) > 0) //strcmp�̿�(strcmp�� �� �ܾ ���������� �� ������ ��� ��ȯ)
			{
				strcpy(str, words[j]); // words[j]�� words[j + 1]�� ���ڿ��� ���� ����Ī�ϴ� �ڵ�(���� �� ����)
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], str);
			}
		}
	}
	printf("%s", words[0]); //���� �� ���� �տ� �� �ܾ� ���
	return 0;
}
