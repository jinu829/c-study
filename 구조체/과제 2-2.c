#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct student {
	char name[21];
	int kor;
	int eng;
	int math;
	double avg;
}st;

void read_data(st* p, int N);

void sort_score(st* p, int N);

st* select_out(st* p, st* q, int N);

int main()
{
	int N;
	st st2[49];
	st st[49];
	struct student* tmp = NULL;
	scanf("%d", &N); //1. ���� N�Է¹ް�, read_data�Լ� ����ؼ� ���� ������, �̸� �Է¹ޱ�
	read_data(st, N); 
	read_data(st2, N);
	sort_score(st, N);//2. ��� ������ ���� �л����� ���� �л� ������ ����
	sort_score(st2, N);
	//printf("%s %d %d %d\n", st->name, st->kor, st->eng, st->math); �߰����� : �� �� �ʿ�� ������ ������ ������ �ϴ� �� ��õ
	tmp = select_out(st, st2, N); //3. �߰������� �� �� �� ū �迭 ã��, �� �迭�� �ִ� ���ҵ� ����ϱ�
	for (struct student* q = tmp; q < tmp + N; q++)
	{
		printf("%s %d %d %d %.1f\n", q->name, q->kor, q->eng, q->math, q->avg);
	}
	return 0;
}

void read_data(st* p, int N)
{
	for (st* q = p; q < p + N; q++) //�� �ϴ� ���� �Է¹����� ��, getchar�� ����!!
	{ 
		scanf("%s %d %d %d", q->name, &q->kor, &q->eng, &q->math);
		//printf("%s %d %d %d\n", q->name, q->kor, q->eng, q->math);
		getchar();
		q->avg = (double)((q->kor + q->eng + q->math) / 3.00);
	}

}

void sort_score(st* p, int N)
{
	struct student tmp;
	for (int i = 0; i < N; i++) //���� �ڵ�(���⼭�� ���� ���� ���)
	{
		for (st* q = p; q < p + N - 1; q++)
		{
			if (q->avg < (q + 1)->avg)
			{
				tmp = *q;
				*q = *(q + 1);
				*(q + 1) = tmp;
			}
			if (q->avg == (q + 1)->avg)
			{
				if (q->kor < (q + 1)->kor)
				{
					tmp = *q;
					*q = *(q + 1);
					*(q + 1) = tmp;
				}
				if (q->kor == (q + 1)->kor)
				{
					if (q->eng < (q + 1)->eng)
					{
						tmp = *q;
						*q = *(q + 1);
						*(q + 1) = tmp;
					}
				}
			}
		}
	}
}

st* select_out(st* p, st* q, int N)
{
	int middle = N / 2; //���ĵ� �迭���� �߰��� ��ġ = ��ü ���� / 2�� �ε��� (���� ��� �迭�� ������ 5�̸� 5/2 = 2��° ���� �߰���)
	if ((q + middle)->avg > (p + middle)->avg)
		return q;
	if ((q + middle)->avg < (p + middle)->avg)
		return p;
}