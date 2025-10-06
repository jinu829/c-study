#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

/*
   문제 간단 정리

   문제에 나와 있는 조건대로 그때그때 N의 크기에 따라 A, B를 변형한 후, 
   그때그때 A를 변형했다면 B와 맞는지, B를 변형했다면 A와 맞는지 체크하기
*/

int main()
{
	char A[101], B[101], tmp[101];
	int idx = 0;
	int count;
	int N;
	int flag = 0;
	gets(A);
	gets(B);
	for (N = 1; N <= 10; N++) //먼저 A변형
	{
		idx = 0;
		for (char* p = A; p < A + strlen(A); p++) //만약 원소가 대문자라면
		{
			if (*p >= 'A' && *p <= 'Z')
			{
				tmp[idx++] = *p + N;
			}
			else if (*p >= 'a' && *p <= 'z') //만약 원소가 소문자라면
			{
				tmp[idx++] = *p - N;
			}
			else if (*p >= '0' && *p <= '9') //(중요!!)만약 원소가 숫자라면
			{
				count = atoi(p); //먼저 문자열 숫자 정수로 만들어주고
				if (*(p + 1) >= '0' && *(p + 1) <= '9') 
					//숫자가 0보다 크도 27보다 작다 -> 두 자리수일 가능성이 있다
					//-> 만약 두 자리수라면 두 숫자를 합쳐서 하나의 수로 생각해야 한다.
					//근데 atoi특징이 숫자가 연속해서 나오면 그 숫자들을 다 합쳐서 한 번에 정수로 바꾼다
					//ex)A = "12aa"라면 atoi(A) = 12
				{
					p++; //따라서 그냥 p만 1더 키워 주면 된다.
				}
				for (int i = 0; i < N; i++) //그러고 숫자 크기만큼 대문자 N번 반복해서 출력
				{
					tmp[idx++] = 'A' + count - 1;
				}
			}
			else //그 외 문자인 경우
				tmp[idx++] = ' ';
		}
		tmp[idx] = '\0';
		//printf("%s\n", tmp); -> tmp 중간점검(중간점검 습관화 하기!)
		if (strcmp(tmp, B) == 0) //만약 변형한 문자열이 B와 같다면
		{
			printf("1");
			flag = 1; //flag를 통해서 같은 상황이 있다는 것을 알리기
			break;
		}
	}
	idx = 0; //B를 변형해보기 위해 idx초기화

	for (N = 1; N <= 10; N++) //그다음 B변형(방법은 A변형할 때와 동일)
	{
		idx = 0;
		for (char* p = B; p < B + strlen(B); p++)
		{
			if (*p >= 'A' && *p <= 'Z')
			{
				tmp[idx++] = *p + N;
			}
			else if (*p >= 'a' && *p <= 'z')
				tmp[idx++] = *p - N;
			else if (*p >= '0' && *p <= '9')
			{
				count = atoi(p);
				if (*(p + 1) >= '0' && *(p + 1) <= '9')
				{
					p++;
				}
				for (int i = 0; i < N; i++)
				{
					tmp[idx++] = 'A' + count - 1;
				}
			}
			else
				tmp[idx++] = ' ';
		}
		tmp[idx] = '\0';
		//printf("%s\n", tmp);
		if (strcmp(tmp, A) == 0)
		{
			printf("2");
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("0");
	return 0;
}

