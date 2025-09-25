#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	int N;
	int lenstr;
	int min = 101;
	int minint;
	char A[101][101];

	//N번 동안 
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(A[i]); //참고 : scanf("%s", ~)같은 경우는 공백이 있으면 공백 전까지만 입력받음. bur gets는 공백이 있어도 엔터 입력이 있기 전까지 계속 입력받음.
		//예시 : This is String (Enter입력) 에서 scanf는 This만 저장 but gets는 This is String 다 저장

		lenstr = strlen(A[i]); //gets로 입력받은 문자열 A[i]의 길이를 strlen을 통해 추출
		if (lenstr < min) //길이가 최소인 배열을 찾는 과정
		{
			min = lenstr;
			minint = i;
		}
	}
	printf("%s", A[minint]);
	return 0;
}