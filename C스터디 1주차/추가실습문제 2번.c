#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

void input(int* p, int M); // �Լ� ����

int* sel_max(int* p, int M);

void output(int* p, int N);

int main(void)
{
	int in[100], out[100], * max, i, N, M; //���� ����
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		input(in, M); //M���� ���� �Է��ϱ�
		max = sel_max(in, M); //�ߺ� Ƚ���� �ִ��� ���� �� ù ��° ������ �ּҸ� max�� �����ϱ�
		out[i] = *max; //���� �ּҸ� out[i]�� ����
	}
	output(out, N);
	return 0;
}

void input(int* p, int M) // input�Լ� ����
{
	for (int* q = p; q < p + M; q++) //*p�� ����Ű�� �ּҺ��� M���� ���� �Է��ϱ�
	{
		scanf("%d", q);
	}
}

int* sel_max(int* p, int M)
{
	int max = 0; //�ߺ� Ƚ���� �ִ������� Ȯ���ϴ� ����
	int* maxint = NULL; //�ߺ� Ƚ���� �ִ��� ������ �ּҸ� ���� ����
	int count = 0; // �ߺ� Ƚ���� ���� ����

	for (int* q = p; q < p + M; q++) //�ߺ��� ���� ������ ���� �Լ�
	{
		count = 0;
		for (int* i = p; i < p + M; i++)
		{
			if (*i == *q)
			{
				count++;
				if (count > max) //���� count>max��� -> �ߺ�Ƚ���� ���� �ִ뺸�� �� ���ٸ�
				{
					max = count;
					maxint = q;
				}
			}
		}
	}
	return maxint;
}

void output(int* p, int N) //output�Լ�
{
	for (int* q = p; q < p + N; q++) //N���� ���� ���
	{
		printf(" %d", *q);
	}
}
