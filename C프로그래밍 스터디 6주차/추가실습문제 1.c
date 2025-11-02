#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

//학교 ppt에 나와있던 동적 할당 이용해서 2차원 배열 할당하기 부분을 잘 공부해와야 풀 수 있는 문제

int main()
{
	int N;
	char X[100];
	char **Y;
	char tmp[100]; 
	int count = 0;
	int max = 0;
	int maxint = 0;
	int flag = 0;
	scanf("%d", &N);
	getchar(); //밑에 gets있으니까 getchar()써주고
	gets(X);
	//printf("%s\n", X); 중간점검
	Y = (char**)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++) //1. 문제에서 하란 대로 먼저 정적 배열(tmp)할당 받고 문자형 포인터 배열 Y에 연결하기 -> 그러기 위해 먼저 Y를 이차원 배열로 선언하고(22번 줄) Y[i]를 각각 tmp길이에 따라 할당한 후 tmp복붙
	{
		gets(tmp);
		Y[i] = (char*)malloc((strlen(tmp) + 1) * sizeof(char));
		strcpy(Y[i], tmp);
		//printf("%s\n", Y[i]);
	}

	for (int i = 0; i < N; i++) //2. 이제 각각의 문장들(Y[i])마다 문자열 X의 개수가 몇개인지 알아봅시다.
	{
		//printf("%d\n", strlen(Y[i])); 중간점검
		for (int j = 0; j < strlen(Y[i]);) //2-1 : X랑 똑같은 문자열이 몇개인지 세기(TMI : Y[i] + j -> Y[i]문자열의 j번째 문자)
		{
			if (strncmp((Y[i] + j), X, strlen(X)) == 0) //strncmp사용하면 편하다!!
			{
				count++; 
				j += strlen(X);
			}
			else
				j++;
		}
		//printf("%d\n", count); 중간점검
		if (count > max) //2-2 : 가장 큰 값이 무엇인지 알아보기 위한 코드
		{
			max = count;
			maxint = i;
			flag = 1;
		}
		count = 0;
	}

	if (flag == 0) //2-3 : 배열 X에 저장된 문자열이 Y에 저장된 각 문자열에 한 번도 나타나지 않는 경우
		printf("NONE");
	else
		printf("%s", Y[maxint]);
	for (int i = 0; i < N; i++) //3. 동적 할당 모두 해제
		free(Y[i]);
	free(Y);
	return 0;
}

