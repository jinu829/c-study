#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int check_row(int** p, int M, int N);

int check_col(int** p, int M, int N);

//문제에 이상한 그림 나왔다고 쫄지 말기!! 결국 M행 N열의 2차원 배열을 쓰라고 문제에서 지시 -> 그대로 하면 된다!

int main()
{
	int M, N;
	int x, y, z;
	int a, b;
	scanf("%d %d", &M, &N);
	int** arr;
	arr = (int**)malloc(M * sizeof(int*)); //1. M행 N열의 2차원 배열을 동적으로 할당받기
	for (int i = 0; i < M; i++)
	{
		arr[i] = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 0; //일단은 다 0으로 초기화 
		}
	}

	for (int i = 0; i < M * N; i++) //2. x, y, z입력받고, 
	{
		scanf("%d %d %d", &x, &y, &z); //2-1 : x, y, z 입력받기
		//printf("%d %d %d\n", x, y, z); 중간점검
		if (x == 0 && y == 0 && z == 0) //2-2 : 만약에 0, 0, 0 입력받으면 중지
			break;
		arr[x][y] = z;
	}
	for (int i = 0; i < M; i++) //3. 만들어진 2차원 배열 출력
	{
		for (int j = 0; j < N; j++) 
		{
			printf(" %d", arr[i][j]); 
		}
		printf("\n");
	}
	a = check_col(arr, M, N); //4, 5 : 이제 행, 열에서 0이 몇 개씩 나오는지 확인해보자!!
	b = check_row(arr, M, N); 
	printf("%d", a > b ? a : b); //a, b중에 더 큰 수 출력(TIP : 이렇게 조건연산자 쓰면 코드가 좀 더 간편해짐)

	for (int i = 0; i < M; i++) { //free는 꼭 main함수에서 써야 합니다!! 실수하지 말기
		free(arr[i]);
	}
	free(arr);
	return 0;
}

int check_col(int** p, int M, int N) //먼저 열부터 시작
{
	int count = 1;
	int flag = 0;
	int max = 0;
	for (int i = 0; i < M; i++) //단순하게 생각해봤을 때, p[i][j]에서 [j]부분이 열이니까, i를 고정해놓고 j부분만 돌리면서 개수 측정하면 되겠네
	{
		for (int j = 0; j < N - 1; j++) //4-1 : 행 고정, 열 변수 1씩 옮기며 연속적인 0개수 측정
		{
			if (p[i][j] == 0)
			{
				flag = 1;
				if (p[i][j + 1] == 0)
				{
					count++;
				}
				else
				{
					count = 1;
				}
			}
			else
				count = 1;
			if (count > max) //4-2 : max값 구하기 위한 코드
			{
				max = count;
			}
		}
		count = 1;
	}
	if (flag == 0) //4-3 만약 0이 하나도 없을 경우를 대비한 코드
		max = 0;
	return max;
}

int check_row(int** p, int M, int N) //열도 똑같, 위 행 코드에서 이번에는 [j]부분을 고정하고, [i]부분을 옮기면 된다.
{
	int count = 1;
	int flag = 0;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			if (p[j][i] == 0)
			{
				flag = 1;
				if (p[j + 1][i] == 0)
				{
					count++;
				}
				else
				{
					count = 1;
				}
			}
			else
				count = 1;
			if (count > max)
			{
				max = count;
			}
		}
		count = 1;
	}
	if (flag == 0)
		max = 0;

	return max;
}