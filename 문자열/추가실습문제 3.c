#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main()
{
	char str[201];
	char word[20][201]; //������ �迭 ����
	int idx = 0;
	int len;
	char tmp[201];
	gets(str);

	len = strlen(str); //str�� ���̸� �̸� len�̶� ������ �־�α�
	// �ܾ�� �и��ؼ� ������ �迭�� �ֱ�(��Ծ��ٸ� �߰��ǽ�����1 �ٽ� �����ϱ�)
	for (char* p = str; *p != '\0'; p++)
	{
		if (*p == ' ')
			*p = '\0';
	}
	

	for (char* p = str; p < str + len;) 
	{
		strcpy(word[idx++], p); 
		printf("%s\n", word[idx - 1]); //���� �ܾ� ���
		p += (strlen(p) + 1); 
	}


	for (int i = 0; i < idx; i++) //���� ���������� ����
	{
		for (int j = 0; j < idx - 1; j++)
		{
			if (strcmp(word[j], word[j + 1]) > 0) //���� �ڿ� �� ���������� �� �����ٸ�
			{
				strcpy(tmp, word[j]); //�յ� �ܾ� ����Ī
				strcpy(word[j], word[j + 1]);
				strcpy(word[j + 1], tmp);
			}
		}
	}
	for (int i = 0; i < idx; i++) //������ �ܾ� ������� ���
	{
		printf("%s ", word[i]);
	}
	return 0;
}