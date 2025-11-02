#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

//동적 할당에서 제일 기분 나쁜 문제 중 하나(제 기준)

int main()
{
	char tmp[101];
	char A[101], B[101];
	char** wordA = NULL, ** wordB = NULL;
	int lenA, lenB;
	int countA = 0, countB = 0;
	int idxA = 0, idxB = 0, idx = 0;
	int flag = 0;
	//1. 먼저 A, B두 개의 문자열 입력받기
	gets(A);
	gets(B);
	lenA = strlen(A);
	lenB = strlen(B);

	//2. A, B에서 단어별로 나눠서 저장하고, 동적으로 할당받은 두 개의 2차원 배열(포인터 배열에 연결된 문자 배열, wordA, wordB)에 각각 저장
	for (char* p = A; *p != '\0'; p++)
	{
		if (*p == ' ')
			*p = '\0';
		countA++; //이차원 배열 동적 할당을 하려면 단어 개수가 몇개인지 알아야 함 -> countA, countB사용
	}
	countA++;
	for (char* p = B; *p != '\0'; p++)
	{
		if (*p == ' ')
			*p = '\0';
		countB++;
	}
	countB++;

	wordA = (char**)malloc(countA * sizeof(char*));//2-1 : countA, countB만큼 각각 동적 할당
	wordB = (char**)malloc(countB * sizeof(char*));

	for (char* p = A; p < A + lenA; p++) //2-2 : A, B의 단어들을 각각 담기
	{
		wordA[idxA] = (char*)malloc((strlen(p) + 1) * sizeof(char));
		strcpy(wordA[idxA++], p); 
		p += strlen(p);
	}
	for (char* p = B; p < B + lenB; p++)
	{
		wordB[idxB] = (char*)malloc((strlen(p) + 1) * sizeof(char));
		strcpy(wordB[idxB++], p);
		p += strlen(p);
	}

	//3. 문자열 A에 포함된 두 개의 단어를 합성하여 만들어진 단어가 문자열 B에 포함되어있는지 확인하기
	/*
	* 합성된 단어랑 일치하는지 봐야한다 -> 그러면 합성할 수 있는 모든 경우를 다 따져봐야한다.
	* -> 이중 for문으로 모든 경우를 다 합성해보자. 그리고 그것을 모든 B의 원소들과 비교해보자
	*/ 
	for (int k = 0; k < idxB; k++) //idxA, idxB : wordA, wordB안에 들어있는 단어 개수
	{
		for (int i = 0; i < idxA; i++)
		{
			for (int j = 0; j < idxA; j++)
			{
				flag = 0;
				if (i != j)
				{
					strcpy(tmp, wordA[i]); //3-1 : tmp에 wordA의 단어 두개를 합성하기
					strcat(tmp, wordA[j]);

					if (strcmp(tmp, wordB[k]) == 0) //만약 존재하면
					{
						for (int l = 0; l < idx; l++) //혹시나 기존에 찾았던 것이랑 중복되는 단어인지 확인
						{
							if (strcmp(wordB[l], tmp) == 0)
								flag = 1;
						}
						if (flag == 0) //그렇지도 않으면 중복되는 단어 목록에 추가
							strcpy(wordB[idx++], tmp); 
						/*
						* 근데 왜 wordB에다 저장하나? 다른 tmp같은 이차원 배열을 추가해서 쓰면 안되나? => 그래도 됨. 메모리 좀 더 쓰는 거 말고는 차이가 없음
						* 다만 strcpy(wordB[idx++], tmp); 이런 식으로 써도 되기는 한다. 
						* 이유 : for문의 조건을 잘 보면 wordB의 첫 번째 단어부터 중복되는지 확인을 한다. 그렇다면 가장 먼저 중복인지 판별되는 단어는 첫 번째 단어일 것이다
						* -> 첫 번째 단어는 중복된 단어를 대입할 때쯤이면 이미 확인이 다 끝났다. 따라서 그 자리에 그대로 대입해도 된다.
						*/
					}

				}
			}
		}
	}

	//4. 내림차순으로 정렬(버블 정렬 사용)
	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < idx - 1; j++)
		{
			if (strlen(wordB[j]) < strlen(wordB[j + 1]))
			{
				strcpy(tmp, wordB[j]);
				strcpy(wordB[j], wordB[j + 1]);
				strcpy(wordB[j + 1], tmp);
			}
			else if (strlen(wordB[j]) == strlen(wordB[j + 1]))
			{
				if (strcmp(wordB[j], wordB[j + 1]) > 0)
				{
					strcpy(tmp, wordB[j]);
					strcpy(wordB[j], wordB[j + 1]);
					strcpy(wordB[j + 1], tmp);
				}

			}
		}
	}

	//5. 출력
	for (int i = 0; i < idx; i++)
		printf("%s\n", wordB[i]);

	//6. 해제
	for (int i = 0; i < idxA; i++) {
		free(wordA[i]);
	}
	for (int i = 0; i < idxB; i++) {
		free(wordB[i]);
	}
	free(wordA);
	free(wordB);
	return 0;
}