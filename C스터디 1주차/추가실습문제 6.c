#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int input(int* p);

int* sel_next(int* p);

int number(int* p, int* q);

int main(void)
{
	int arr[100];
	int N;
	int M;
	int* last = NULL;
	int total;
	N = input(arr);
	for (int* q = arr; q < arr + N; ) //ó������ �����ؼ� �����ϴٰ� �����ϴ� �κ� ��ȯ, ��ȯ�� �κк��� ����, �����ϴٰ� �����ϴ� �κ� ��ȯ....... -1 ���� ������
	{
		if (q == arr + N - 1)
			break;
		last = sel_next(q); //������ �ּҸ� sel_next�Լ��� ����
		total = number(q, last); //number�Լ� �̿��ؼ� �� ���ڷ� �����
		printf("%d\n", total);
		q = last; //��ȯ�� �κк��� ����
	}
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

int* sel_next(int* p) //ù��° ���� �ι�° ����  1. �����ϸ� - ���Ұ� ���� ������, 2. �����ϸ�, ������ ���� ������
{
	int flag;
	int* q;
	if (*p > *(p + 1)) //���� ù��° ���ڿ� �� ��° ���ڰ� �����ϴ���, �����ϴ����� ���߰ڴ�!
		flag = 0;
	if (*p < *(p + 1))
		flag = 1;
	if (flag == 0) //�����ϴ� ���
	{
		for (q = p; *q != -1; q++) //���Ұ� ������ �������� �ݺ�, ���Ұ� ������ ���� �ּ� ��ȯ
		{
			if (*q < *(q + 1))
				return q;
		}
		return q - 1; //���� -1�κб��� ���Ұ� ������ �ʴ´ٸ�, -1 �ٷ� ���� �ּҸ� ��ȯ
	}
	if (flag == 1) // �����ϴ� ���
	{
		for (q = p; *q != -1; q++) //������ ������ �������� �ݺ�, ������ ������ ���� �ּ� ��ȯ
		{
			if (*q > *(q + 1)) 
				return q;
		}
		return q - 1; //���� -1�κб��� ������ ������ �ʴ´ٸ�, -1 �ٷ� ���� �ּҸ� ��ȯ
	}
}

int number(int* p, int* q)
{
	int total = 0;
	for (int* i = p; i <= q; i++)
	{
		total *= 10;
		total += *i;
	}
	return total;
}