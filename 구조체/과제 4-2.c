#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct parking_info {
	int carnumber;
	int customernumber;
	char gift;
	char YorN;
	int type;
	int minute;
	double charge;
};

void input(struct parking_info* p, int N);

void compute(struct parking_info* p);

void display(struct parking_info* p, int N);

void parking_info_sort(struct parking_info* p, int N);

int main()
{
	int N;
	int Dtotal = 0, Stotal = 0, total = 0;
	struct parking_info park[100];
	scanf("%d", &N);
	input(park, N); //1. input함수 통해서 문제에서 요구한 데이터들 받기
	for (struct parking_info* q = park; q < park + N; q++)
	{
		compute(q); //2. 대여비용 계산
		//printf("%d\n", q->carnumber);
	}
	parking_info_sort(park, N); //3. 
	display(park, N);
	for (struct parking_info* q = park; q < park + N; q++)
	{
		if (q->gift == 'S')
		{
			Stotal += q->charge;
			total += q->charge;
		}
		if (q->gift == 'D')
		{
			Dtotal += q->charge;
			total += q->charge;
		}
	}
	printf("%d %d %d", Dtotal, Stotal, total);
	return 0;
}

void input(struct parking_info* p, int N)
{
	for (struct parking_info* q = p; q < p + N; q++)
	{
		scanf("%d %d %c", &q->carnumber, &q->customernumber, &q->gift);
		getchar();
		if (q->gift == 'S')
		{
			scanf("%c %d %d", &q->YorN, &q->type, &q->minute);
		}
		if (q->gift == 'D')
		{
			scanf("%d", &q->minute);
		}
	}

}

void compute(struct parking_info* p)
/*
	1. 상품이 D인가? S인가?
	2. S라면, 신규 가입인가? 가입되어있는건가?
	3. 4시간을 넘었는가, 넘지 않았는가?
	4. 
*/
{
	struct parking_info* q = p;
	q->charge = 0;
	if (q->gift == 'S')
	{
		if (q->YorN == 'Y')
		{
			if (q->minute > 240)
			{
				q->charge += ((q->minute - 240) / 10) * 200;
			}
		}
		if (q->YorN == 'N')
		{
			if (q->type == 7)
				q->charge += 30000;
			if (q->type == 30)
				q->charge += 100000;
			if (q->type == 180)
				q->charge += 500000;
			if (q->minute > 240)
			{
				q->charge += ((q->minute - 240) / 10) * 200;
			}
		}
	}
	if (q->gift == 'D')
	{
		q->charge += 5000;
		if (q->minute > 240)
		{
			q->charge += ((q->minute - 240) / 10) * 200;
		}
	}
}

void display(struct parking_info* p, int N)
{
	for (struct parking_info* q = p; q < p + N; q++)
	{
		printf("%d %d %c %.0f\n", q->carnumber, q->customernumber, q->gift, q->charge);
	}
}

void parking_info_sort(struct parking_info* p, int N)
{
	struct parking_info tmp;
	for (int i = 0; i < N; i++)
	{
		for (struct parking_info* q = p; q < p + N - 1; q++)
		{
			if (q->gift == 'S' && (q + 1)->gift == 'D')
			{
				tmp = *q;
				*q = *(q + 1);
				*(q + 1) = tmp;
			}
			if (q->gift == 'S' && (q + 1)->gift == 'S')
			{
				if (q->carnumber > (q + 1)->carnumber)
				{
					tmp = *q;
					*q = *(q + 1);
					*(q + 1) = tmp;
				}
			}
			if (q->gift == 'D' && (q + 1)->gift == 'D')
			{
				if (q->carnumber > (q + 1)->carnumber)
				{
					tmp = *q;
					*q = *(q + 1);
					*(q + 1) = tmp;
				}
			}
		}
	}
}