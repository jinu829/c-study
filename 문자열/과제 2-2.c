#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int main()
{
	char str[201], tmp[201], word[200][201], tmp2[201];
	gets(str);
	gets(tmp);
	int len = strlen(str);
	int idx = 0;
	int flag = 0;


	for (char* p = str; *p != '\0'; p++) //str�� �ܾ� �����ؼ� word�� ����
	{
		if (*p == ' ')
			*p = '\0';
	}
	for (char* p = str; p < str + len; p++)
	{
		strcpy(word[idx++], p);
		p += strlen(p);
	}

	for (int i = 0; i < idx; i++) //�ϴ� word[i]�� ������ �ܾ�� �� ����ϱ�
	{
		printf("%s\n", word[i]);
		if (strcmp(word[i], tmp) == 0) //���� �� ��° �Է��� �ܾ�(tmp)�� �ߺ��� �ܾ �ִٸ�
		{
			flag = 1; //flag = 1;�� �ߺ��� �ܾ �ִٴ� �� �˸���
		}
	}
	if (flag == 0) //���� �ߺ��� �ܾ ���ٸ�
	{
		printf("%s\n", tmp); //tmp�� ���

		strcpy(word[idx++], tmp); //tmp�� word�迭�� �ֱ�(������ �Ʒ�����)
	}

	for (int i = 0; i < idx; i++) //�ܾ� ������ �����ϱ�(������)
	{
		for (int j = 0; j < idx - 1; j++)
		{
			if (strcmp(word[j], word[j + 1]) > 0)
			{
				strcpy(tmp, word[j]); //�߿�!! �ܾ� �����ϴ� �ڵ�
				strcpy(word[j], word[j + 1]);
				strcpy(word[j + 1], tmp);
			}
		}
	}

	strcpy(tmp2, word[0]); //��� : ó������ �� ���ڰ� �����Ƿ� strcpy���� �ϱ�
	strcat(tmp2, " ");
	for (int i = 1; i < idx; i++)
	{
		strcat(tmp2, word[i]);
		strcat(tmp2, " ");
	}
	printf("%s", tmp2);
	return 0;
}

