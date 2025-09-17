#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int input(int* p); // �Լ� ����

int* sel_next(int* p, int N, int M);

int number(int* p, int* q);

int main(void)
{
	int arr[100];
	int N;
	int M;
	int* last = NULL;
	int total;
	N = input(arr); // �迭 ������ ������ N�� �Է�
	scanf("%d", &M); //M�Է¹ޱ�
	last = sel_next(arr, N, M); // sel_next�Լ��� �̿��Ͽ� ������ ������ ������ last�� �Է¹ޱ�
	total = number(arr + M, last); // �迭 ���ҵ��� ���Ͽ� total�� �����ϱ�
	printf("%d", total); //total���
	return 0;
}

int input(int* p)
{
	int count = 0;
	for (int* i = p; i < p + 100; i++)
	{
		scanf("%d", i);
		if (*i == -1)
			break;
		count++;
	}
	return count;
}

int* sel_next(int* p, int N, int M)
{
	for (int* q = p + M; q < p + N; q++)
	{
		if (*(q + 1) < *q) // ���� q+1�� ���� q���� �۴ٸ�(������ ����)  q�� ��ġ ��ȯ
			return q;
	}
	return p + N - 1; //���� -1������ ��� �����ϸ�, ������ ������ �ּ� ��ȯ
}

int number(int* p, int* q)
{
	int total = 0; //���� �� ���� ���� ���� ����

	for (int* i = p; i <= q; i++)
	{
		total *= 10;
		total += *i;
	}
	return total;
}
