#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main()
{
	int N, M1, M2;
	int max = 0, min = 101;
	int j = 0, k = 0, idx = 0;
	int first = 1;
	int count = 0;
	char str[20][101];
	char maxstr[101];
	char minstr[101];
	char temp[101];
	char finish1[101] = { '\0' };
	char finish2[101] = { '\0' };
	char realfinish[101] = { '\0' };

	scanf("%d %d %d", &N, &M1, &M2); 
	getchar();
	for (int i = 0; i < N; i++) //���� �� ���ڿ��� ���� ª�� ���ڿ� ���� ���ϱ�(���� 4���� �Ȱ�)
	{
		gets(str[i]);
		if (strlen(str[i]) > max)
		{
			max = strlen(str[i]);
			strcpy(maxstr, str[i]);
		}
		if (strlen(str[i]) < min)
		{
			min = strlen(str[i]);
			strcpy(minstr, str[i]);
		}
	}
	printf("%s\n", maxstr); //���� �� ���ڿ��� ���� ª�� ���ڿ� ���
	printf("%s\n", minstr);
	while (j <= strlen(maxstr)) 
	{
		if (maxstr[j] != ' ' && maxstr[j] != '\0') // M1��° �ܾ� ���ϱ�
		{
			temp[idx++] = maxstr[j]; //������ �ƴϸ� �ϴ� �׳� temp�� ���
		}
		else
		{
			temp[idx] = '\0'; //���� �κ��� �� ���ڷ� �ٲٱ�(���ڿ��� �ܾ�� ���� ��ó�� -> �߰��ǽ����� 1�� ����)
			if (count == M1) //���� M1��° �ܾ���
			{
				strcat(finish1, temp); //finish1�� ���̱� (finish1�� �̹� ��� ���� '\0'ó���Ǿ��ֱ⿡ �׳� strcat�ᵵ ��)
			}
			idx = 0;
			count++;
		}
		j++;
	}
	count = 0;
	j = 0;
	idx = 0;
	while (j <= strlen(minstr)) //����ϰ� M2��° �ܾ� ���ϱ�
	{
		if (minstr[j] != ' ' && minstr[j] != '\0')
		{
			temp[idx++] = minstr[j];
		}
		else
		{
			temp[idx] = '\0';
			if (count == M2)
			{
				strcat(finish2, temp);
			}
			idx = 0;
			count++;
		}
		j++;
	}
	if (strcmp(finish1, finish2) < 0) //���� ������ ���� ���� �ٸ��� ���̱�
	{
		strcat(realfinish, finish1);
		strcat(realfinish, finish2);
	}
	if (strcmp(finish1, finish2) > 0)
	{
		strcat(realfinish, finish2);
		strcat(realfinish, finish1);
	}
	printf("%s", realfinish); //���� ���ڿ� ���
	return 0;
}

/*
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december
*/