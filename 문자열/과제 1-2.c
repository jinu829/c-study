#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

/*
   ���� ���� ����

   ������ ���� �ִ� ���Ǵ�� �׶��׶� N�� ũ�⿡ ���� A, B�� ������ ��, 
   �׶��׶� A�� �����ߴٸ� B�� �´���, B�� �����ߴٸ� A�� �´��� üũ�ϱ�
*/

int main()
{
	char A[101], B[101], tmp[101];
	int idx = 0;
	int count;
	int N;
	int flag = 0;
	gets(A);
	gets(B);
	for (N = 1; N <= 10; N++) //���� A����
	{
		idx = 0;
		for (char* p = A; p < A + strlen(A); p++) //���� ���Ұ� �빮�ڶ��
		{
			if (*p >= 'A' && *p <= 'Z')
			{
				tmp[idx++] = *p + N;
			}
			else if (*p >= 'a' && *p <= 'z') //���� ���Ұ� �ҹ��ڶ��
			{
				tmp[idx++] = *p - N;
			}
			else if (*p >= '0' && *p <= '9') //(�߿�!!)���� ���Ұ� ���ڶ��
			{
				count = atoi(p); //���� ���ڿ� ���� ������ ������ְ�
				if (*(p + 1) >= '0' && *(p + 1) <= '9') 
					//���ڰ� 0���� ũ�� 27���� �۴� -> �� �ڸ����� ���ɼ��� �ִ�
					//-> ���� �� �ڸ������ �� ���ڸ� ���ļ� �ϳ��� ���� �����ؾ� �Ѵ�.
					//�ٵ� atoiƯ¡�� ���ڰ� �����ؼ� ������ �� ���ڵ��� �� ���ļ� �� ���� ������ �ٲ۴�
					//ex)A = "12aa"��� atoi(A) = 12
				{
					p++; //���� �׳� p�� 1�� Ű�� �ָ� �ȴ�.
				}
				for (int i = 0; i < N; i++) //�׷��� ���� ũ�⸸ŭ �빮�� N�� �ݺ��ؼ� ���
				{
					tmp[idx++] = 'A' + count - 1;
				}
			}
			else //�� �� ������ ���
				tmp[idx++] = ' ';
		}
		tmp[idx] = '\0';
		//printf("%s\n", tmp); -> tmp �߰�����(�߰����� ����ȭ �ϱ�!)
		if (strcmp(tmp, B) == 0) //���� ������ ���ڿ��� B�� ���ٸ�
		{
			printf("1");
			flag = 1; //flag�� ���ؼ� ���� ��Ȳ�� �ִٴ� ���� �˸���
			break;
		}
	}
	idx = 0; //B�� �����غ��� ���� idx�ʱ�ȭ

	for (N = 1; N <= 10; N++) //�״��� B����(����� A������ ���� ����)
	{
		idx = 0;
		for (char* p = B; p < B + strlen(B); p++)
		{
			if (*p >= 'A' && *p <= 'Z')
			{
				tmp[idx++] = *p + N;
			}
			else if (*p >= 'a' && *p <= 'z')
				tmp[idx++] = *p - N;
			else if (*p >= '0' && *p <= '9')
			{
				count = atoi(p);
				if (*(p + 1) >= '0' && *(p + 1) <= '9')
				{
					p++;
				}
				for (int i = 0; i < N; i++)
				{
					tmp[idx++] = 'A' + count - 1;
				}
			}
			else
				tmp[idx++] = ' ';
		}
		tmp[idx] = '\0';
		//printf("%s\n", tmp);
		if (strcmp(tmp, A) == 0)
		{
			printf("2");
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("0");
	return 0;
}

