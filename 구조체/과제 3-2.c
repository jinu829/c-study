#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct hotel_info { 
	char name[31];
	int grade;
	double critic;
	double distance;
	char breakfast;
}HOTEL;

int in_hotel_info(struct hotel_info* p);

void out_hotel_info(struct hotel_info* p, int N, int G, double D);

int main()
{
	HOTEL hotel[100];
	int count;
	int G;
	double D;
	count = in_hotel_info(hotel); //1. ȣ���� �������� �Է¹ް�, ȣ���� ���� count
	scanf("%d %lf", &G, &D);
	out_hotel_info(hotel, count, G, D); //2. ȣ�� ����ü �迭(����ü �迭�� ù ��° �ּ�), ����, ���ϴ� ȣ�� ���, ȣ�ڱ����� �Ÿ��� �Է¹ް�, ���� ���� �� ���� ���� ȣ���� ���� ����ϱ�
	return 0;
}

int in_hotel_info(struct hotel_info* p)
{
	int count = 0;
	for (HOTEL* q = p; q < p + 100; q++)
	{
		scanf("%s", q->name);
		if (strcmp(q->name, "0") == 0)
			break;
		scanf("%d %lf %lf %c", &q->grade, &q->critic, &q->distance, &q->breakfast);
		getchar();
		count++;
	}
	return count;
}

void out_hotel_info(struct hotel_info* p, int N, int G, double D)
{
	double max = -1;
	HOTEL tmp[100];
	HOTEL tmp2;
	int idx = 0;
	for (HOTEL* q = p; q < p + N; q++)
	{
		if (q->grade >= G && q->distance <= D) //2-1 : ���� G��� �̻��̰� �Ÿ��� D������ ȣ�ڵ鸸 �߷��� �� ����ü �迭�� �ֱ�
		{
			tmp[idx++] = *q;
		}
	}
	for (int i = 0; i < idx; i++)//2-2 : G��� �̻��̰� �Ÿ��� D ������ ȣ���� ������� ����ϱ� ����, ���� ȣ�ڵ� ����
	{
		for (HOTEL* q = tmp; q < tmp + idx - 1; q++) 
		{
			if (q->critic < (q + 1)->critic)
			{
				tmp2 = *q;
				*(q) = *(q + 1);
				*(q + 1) = tmp2;
			}
			if (q->critic == (q + 1)->critic)
			{
				if (strcmp(q, q + 1) > 0) //���ǵ� ���� -> ���� ������� �ϱ� ���� �߰� ���� ����
				{
					tmp2 = *q;
					*(q) = *(q + 1);
					*(q + 1) = tmp2;
				}
			}
		}
	}
	for (HOTEL* q = tmp; q < tmp + idx; q++)
	{
		printf("%s %d %.1f %.1f %c\n", q->name, q->grade, q->critic, q->distance, q->breakfast);
	}
}