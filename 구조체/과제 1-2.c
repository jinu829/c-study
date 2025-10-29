#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct taxi_info { //�������� ������ ��� ����ü ����
	char start[11];
	char target[11];
	double distance;
	int t_time;
	char late_night;
	int tot;
}TAXI;

TAXI* sel_max(TAXI* p, int N, char* s, char* d);

int main()
{
	TAXI p[20], * maxTAXI = NULL;
	int N;
	char s[11], d[11];
	scanf("%d", &N); //1. ���� N�Է¹ޱ�
	getchar();
	for (int i = 0; i < N; i++) //2. N���� �����, ������, �̵��Ÿ�, ��ü�ð�, �ɾ߿��࿩�� ������ �Է¹޾� ����ü�� �����ϱ�
	{
		scanf("%s %s %lf %d %c", p[i].start, p[i].target, &p[i].distance, &p[i].t_time, &p[i].late_night); //���ڿ� �Է¹��� ���� &�Ⱥ��δ�
		getchar(); //getchar()����� ����!!
	}

	for (int i = 0; i < N; i++) //3. ��� ���
		/*
		   1. �ɾ����� �ְ����� �����ϰ�
		   2. �Ÿ��� 2km���� �� ���� �ƴ��� ����
		   3. ��� ���(��� ����� ������ �����ִµ��� ���󰡱�)
		*/
	{
		if (p[i].late_night == 'N')
		{
			if (p[i].distance <= 2)
			{
				p[i].tot = 3800 + (p[i].t_time / 30) * 100;
			}
			if (p[i].distance > 2)
			{
				p[i].tot = (((p[i].distance - 2) * 1000) / 100) * 100 + 3800 + (p[i].t_time / 30) * 100;
			} 
		}
		if (p[i].late_night == 'Y')
		{
			if (p[i].distance <= 2)
			{
				p[i].tot = 4800 + (p[i].t_time / 30) * 120;
			}
			if (p[i].distance > 2)
			{
				p[i].tot = (((p[i].distance - 2) * 1000) / 100) * 120 + 4800 + (p[i].t_time / 30) * 120;
			}
		}
	}

	scanf("%s %s", s, d); //4. ������� ������ ���� �Է¹޾Ƽ�, �ݾ��� ���� ū ��� ã��

	maxTAXI = sel_max(p, N, s, d); /*�Ű������� �� �־�� ���� ����
	TAXI����ü �迭 ���� �ּ� -> p, N�� -> N, �����, ������ ���ڿ� ���� �ּ� -> s, d
								   */

	printf("%.2f %d %c %d", maxTAXI->distance, maxTAXI->t_time, maxTAXI->late_night, maxTAXI->tot);

	return 0;
}

TAXI* sel_max(TAXI* p, int N, char* s, char* d)
{
	int max = 0;
	TAXI* maxTAXI = NULL;
	for (TAXI* q = p; q < p + N; q++) //4-1 ����ü �迭 ���Ҹ� �ϳ��ϳ��� ���ƺ��鼭 ���غ��ô�
	{
		if (strcmp(q->start, s) == 0 && strcmp(q->target, d) == 0) //���� ����ü ���Ҷ� s, d�� �����, �������� ���ٸ�
		{
			if (q->tot > max) //���� �ݾ��� ���� ũ�ٸ�
			{
				max = q->tot;
				maxTAXI = q; //�ش� ����ü ���� �ּ� ������ �ֱ�
			}
		}
	}
	return maxTAXI; //ã�� ���� ��ȯ
}