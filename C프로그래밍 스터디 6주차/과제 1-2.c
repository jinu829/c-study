#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//동적할당은 대부분의 문제들에서 문자열, 구조체, 포인터를 얼마나 잘 알고있냐가 더 중요합니다!! 특히 문자열 부분을 잘 배웠는지 다시 한 번 점검해봅시다.

struct st {
	char* str;
	int cnt1;
	int cnt2;
	int num;
	int pos;
	int result;
};

int main()
{
	int N;
	char tmp[101];
	int len;
	struct st* st;
	struct st tmp2;
	scanf("%d", &N); 
	getchar(); //다음 입력이 gets -> getchar()빼먹지 말기
	st = (struct st*)malloc(N * sizeof(struct st)); //1. 구조체 포인터 선언 후 N크기의 구조체 배열 동적할당, str 동적할당 후 문자열 할당하기
	for (int i = 0; i < N; i++)
	{
		st[i].cnt1 = 0;
		st[i].cnt2 = 0;
		gets(tmp);
		st[i].str = (char*)malloc((strlen(tmp) + 1) * sizeof(char)); //1-1 : 정적 배열에 먼저 문자열 받고 그 길이 + 1만큼 동적 할당, 그 후 str에 복사
		strcpy(st[i].str, tmp);
		st[i].cnt2 = strlen(st[i].str);

		//2. 자음의 수 세기
		for (int j = 0; j < strlen(st[i].str); j++)
		{
			if (!(st[i].str[j] == 'a' || st[i].str[j] == 'e' || st[i].str[j] == 'i' || st[i].str[j] == 'o' || st[i].str[j] == 'u' || st[i].str[j] == 'A' || st[i].str[j] == 'E' || st[i].str[j] == 'I' || st[i].str[j] == 'O' || st[i].str[j] == 'U' || (st[i].str[j] >= '0' && st[i].str[j] <= '9'))) //2-1 : 숫자, 영어 중 자음 영어만 추려내는 조건 코드
			{
				st[i].cnt1++;
			}
			else if (st[i].str[j] >= '0' && st[i].str[j] <= '9') //2-2 : 만약 숫자라면
			{
				st[i].num = st[i].str[j] - '0';
				st[i].pos = j + 1;
			}
		}
		//printf("%d %d %d %d\n", st[i].cnt1, st[i].cnt2, st[i].num, st[i].pos);
		st[i].result = st[i].cnt1 * st[i].cnt2 * st[i].num * st[i].pos; //값 다 구한 후 result에 저장
	}

	for (int i = 0; i < N; i++) //3. result가 가장 큰 순서대로 내림차순(모든 곱셈의 결과가 같은 경우 '입력된 순서대로' 정렬 -> 버블 정렬 사용하는게 편함)
	{
		for (struct st* p = st; p < st + N - 1; p++)
		{
			if (p->result < (p + 1)->result)
			{
				tmp2 = *p;
				*p = *(p + 1);
				*(p + 1) = tmp2;
			}
		}
	}
	for (int i = 0; i < N; i++) //출력
	{
		printf("%s\n", st[i].str);
		//printf("%d\n", st[i].result);
	}
	for (int i = 0; i < N; i++) //4. 해제
		free(st[i].str);
	free(st);
	return 0;
}
