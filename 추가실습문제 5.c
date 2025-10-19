#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct person {
	char name[11];
	char birth[11];
	int first;
	int second;
	double total;
};

void swap(struct person* p, struct person* q);

int main()
{
	int N, M;
	struct person p[100];
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf("%s %s %d %d", p[i].name, p[i].birth, &p[i].first, &p[i].second); // 이거 getchar안써도 돼?
		p[i].total = p[i].first * 0.8 + p[i].second * 0.2;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (p[j].total < p[j + 1].total)
			{
				swap(p + j, p + j + 1); //p[j]같은거는 주소를 표현하는 것이 아니므로 포인터 형태의 인자에 못넣는다!!
			}
			else if (p[j].total == p[j + 1].total)
			{
				if (p[j].first < p[j + 1].first)
				{
					swap(p + j, p + j + 1);
				}
				else if (p[j].first == p[j + 1].first)
				{
					if (atoi(p[j].birth) < atoi(p[j + 1].birth))
					{
						swap(p + j, p + j + 1);
					}
					else if (atoi(p[j].birth) == atoi(p[j + 1].birth))
					{
						if (atoi(p[j].birth + 5) < atoi(p[j + 1].birth + 5))
						{
							swap(p + j, p + j + 1);
						}
						else if (atoi(p[j].birth + 5) == atoi(p[j + 1].birth + 5))
						{
							if (atoi(p[j].birth + 8) < atoi(p[j + 1].birth + 8))
							{
								swap(p + j, p + j + 1);
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		printf("%s %.1f\n", p[i].name, p[i].total);
	}
	return 0;
}

void swap(struct person* p, struct person* q)
{
	struct person tmp;
	tmp = *q;
	*q = *p;
	*p = tmp;
}