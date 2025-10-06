#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int main()
{
	/* 먼저 두 입력받은 문자열을 단어별로 나눠서 이차원 배열에 저장
	   그 후 처음 입력받은 문자열(A)를 저장한 이차원 배열(wordA)의 단어를 하나씩 훑으면서
	   중복이라면 B를 저장한 이차원 배열(wordB)에 있는 단어를 옮긴 뒤 
	   B의 다음 단어로 넘어가기
	*/

	char A[101], B[101], tmp[251];
	char wordA[101][101], wordB[101][101];
	gets(A); //문자열 A, B입력받기
	gets(B);
	char idxA = 0, idxB = 0, idx = 0;
	int lenA = strlen(A), lenB = strlen(B);

	for (char* p = A; *p != '\0'; p++) //문자열 A, B각각 단어 단위로 이차원 배열에 옮기기
	{
		if (*p == ' ')
			*p = '\0';
	}
	for (char* p = B; *p != '\0'; p++)
	{
		if (*p == ' ')
			*p = '\0';
	}

	for (char* p = A; p < A + lenA; p++) //문자열 A, B각각 단어 단위로 이차원 배열에 옮기기
	{
		strcpy(wordA[idxA++], p);
		p += strlen(p);
	}
	for (char* p = B; p < B + lenB; p++)
	{
		strcpy(wordB[idxB++], p);
		p += strlen(p);
	}

	for (int i = 0; i < idxA; i++) //먼저 중복인지 확인(단, 처음 부분은 건너뛰기)
	{
		for (int j = 0; j < idxA; j++)
		{
			if (strcmp(wordA[i], wordA[j]) == 0)
			{
				if (j < i) //
				{
					strcpy(wordA[i], wordB[idx++]); //중복된 부분에 B의 단어 넣기 + B의 index한칸 뒤로 이동(다음 단어로)
					break; 
				}
			}
		}
	}

	strcpy(tmp, wordA[0]); //문자열A에서 중복 단어 없앤 배열을 단어별로 하나씩 tmp에 담기
	strcat(tmp, " ");
	// 처음에는 널 문자가 없으므로 strcpy먼저 하기
	for (int i = 1; i < idxA; i++)
	{
		strcat(tmp, wordA[i]);
		strcat(tmp, " ");
	}
	printf("%s", tmp);
	return 0;
}