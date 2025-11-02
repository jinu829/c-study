#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

//동적 할당 문제들 중 최고 난이도(개인적인 의견), 다른 문제들은 동적 할당이 조미료 느낌이었다면, 이 문제는 동적 할당 자체만으로도 어려움

struct subject {
	char* name;
	double score; 
};

struct student {
	char* name;  
	char id[5];  
	int numSubject;
	struct subject* psub;  
	double avg; 
};

int main()
{
	int N, K;
	int maxint;
	double max = 0;
	int len;
	int idx = 0;
	char tmp[101];
	scanf("%d", &N);
	getchar(); //다음으로 받는 게 gets -> getchar()쓰기

	//N을 입력 받고, 각 학생의 정보를 N개의 공백이 있는 문자열로 입력 받아야 함.
	struct student* st;
	struct student tmp2;
	st = (struct student*)malloc(N * sizeof(struct student)); //1. 구조체 포인터에 N크기의 배열 동적 할당하고, 문자열(tmp)입력받은 후 각 정보를 구조체 원소에 저장
	for (int i = 0; i < N; i++)
	{!
		gets(tmp); //각 학생의 정보가 있는 문자열
		len = strlen(tmp);
		st[i].numSubject = 0;
		st[i].avg = 0;
		for (char* p = tmp; *p != '\0'; p++) //1-1. 각 정보는 단어별로(띄어쓰기로 구분)나뉘어져 있음 -> 단어별로 우선 나눌 준비
		{
			if (*p == ' ')
				*p = '\0';
		}

		for (char* p = tmp; p < tmp + len;)
		{
			//1-2. 먼저 student 구조체의 name받기
			st[i].name = (char*)malloc((strlen(p) + 1) * sizeof(char)); //동적 할당
			strcpy(st[i].name, p);
			p = p + strlen(p) + 1;
			//1-3. 그다음 id받기
			strcpy(st[i].id, p);
			p = p + strlen(p) + 1;
			//1-4. 이제부터 과목 이름, 성적 순으로 계속 받기
			for (char* q = p; q < tmp + len;) //1-4-1. 그러기 위해서 먼저 numSubject를 알아서 과목 개수를 알기
			{
				st[i].numSubject++;
				q += strlen(q) + 1;
				q += strlen(q) + 1;
			}
			//1-5. 과목 개수를 알았으니 그 과목 수만큼 (과목 이름, 점수) 순으로 받자
			st[i].psub = (struct subject*)malloc(st[i].numSubject * sizeof(struct subject)); //numSubject먼저 구한 이유? psub 동적 할당 하기 위해서!!
			for (int j = 0; j < st[i].numSubject; j++)
			{
				st[i].psub[j].name = (char*)malloc((strlen(p) + 1) * sizeof(char)); //1-5-1. psub의 name도 동적할당 해야 된다!!! 주의
				strcpy(st[i].psub[j].name, p); //먼저 과목 이름 넣고
				p += (strlen(p) + 1);
				st[i].psub[j].score = atof(p); //과목 점수 넣고(atof(p) -> p에 있는 값을 실수로 변환해줌)
				p += (strlen(p) + 1);
			}
		}

		//1-6. 이제 과목 점수 다 구했으니 평균 구하기
		for (int j = 0; j < st[i].numSubject; j++)
		{
			st[i].avg += st[i].psub[j].score;
		}
		st[i].avg /= (double)st[i].numSubject;
	}

	for (int i = 0; i < N; i++) //이제 평균 점수가 가장 높은 학생부터 내림차순으로 정렬
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (st[j].avg < st[j + 1].avg)
			{
				tmp2 = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp2;
			}
			if (st[j].avg == st[j + 1].avg)
			{
				if (atoi(st[j].id) > atoi(st[j + 1].id))
				{
					tmp2 = st[j];
					st[j] = st[j + 1];
					st[j + 1] = tmp2;
				}
			}
		}
	}

	scanf("%d", &K); //K번째 학생 정보 출력
	for (int i = 0; i < st[K - 1].numSubject; i++)
	{
		if (st[K - 1].psub[i].score > max)
		{
			max = st[K - 1].psub[i].score;
			maxint = i;
		}
	}
	printf("%s %s %.2f %s %.2f", st[K - 1].name, st[K - 1].id, st[K - 1].avg, st[K - 1].psub[maxint].name, max);

	return 0;
}