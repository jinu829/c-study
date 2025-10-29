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
	scanf("%d", &N); //1. 정수 N입력받고, read_data함수 사용해서 과목 성적들, 이름 입력받기
	read_data(st, N); 
	read_data(st2, N);
	sort_score(st, N);//2. 평균 점수가 높은 학생부터 낮은 학생 순서로 정렬
	sort_score(st2, N);
	//printf("%s %d %d %d\n", st->name, st->kor, st->eng, st->math); 중간점검 : 꼭 할 필요는 없으나 생각날 때마다 하는 거 추천
	tmp = select_out(st, st2, N); //3. 중간값끼리 비교 후 더 큰 배열 찾고, 그 배열에 있는 원소들 출력하기
	for (struct student* q = tmp; q < tmp + N; q++)
	{
		printf("%s %d %d %d %.1f\n", q->name, q->kor, q->eng, q->math, q->avg);
	}
	return 0;
}

void read_data(st* p, int N)
{
	for (st* q = p; q < p + N; q++) //늘 하던 데로 입력받으면 됨, getchar만 주의!!
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
	for (int i = 0; i < N; i++) //정렬 코드(여기서는 버블 정렬 사용)
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
	int middle = N / 2; //정렬된 배열에서 중간값 위치 = 전체 개수 / 2번 인덱스 (예를 들어 배열의 개수가 5이면 5/2 = 2번째 항이 중간값)
	if ((q + middle)->avg > (p + middle)->avg)
		return q;
	if ((q + middle)->avg < (p + middle)->avg)
		return p;
}