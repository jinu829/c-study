#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int main()
{
	/* ���� �� �Է¹��� ���ڿ��� �ܾ�� ������ ������ �迭�� ����
	   �� �� ó�� �Է¹��� ���ڿ�(A)�� ������ ������ �迭(wordA)�� �ܾ �ϳ��� �����鼭
	   �ߺ��̶�� B�� ������ ������ �迭(wordB)�� �ִ� �ܾ �ű� �� 
	   B�� ���� �ܾ�� �Ѿ��
	*/

	char A[101], B[101], tmp[251];
	char wordA[101][101], wordB[101][101];
	gets(A); //���ڿ� A, B�Է¹ޱ�
	gets(B);
	char idxA = 0, idxB = 0, idx = 0;
	int lenA = strlen(A), lenB = strlen(B);

	for (char* p = A; *p != '\0'; p++) //���ڿ� A, B���� �ܾ� ������ ������ �迭�� �ű��
	{
		if (*p == ' ')
			*p = '\0';
	}
	for (char* p = B; *p != '\0'; p++)
	{
		if (*p == ' ')
			*p = '\0';
	}

	for (char* p = A; p < A + lenA; p++) //���ڿ� A, B���� �ܾ� ������ ������ �迭�� �ű��
	{
		strcpy(wordA[idxA++], p);
		p += strlen(p);
	}
	for (char* p = B; p < B + lenB; p++)
	{
		strcpy(wordB[idxB++], p);
		p += strlen(p);
	}

	for (int i = 0; i < idxA; i++) //���� �ߺ����� Ȯ��(��, ó�� �κ��� �ǳʶٱ�)
	{
		for (int j = 0; j < idxA; j++)
		{
			if (strcmp(wordA[i], wordA[j]) == 0)
			{
				if (j < i) //
				{
					strcpy(wordA[i], wordB[idx++]); //�ߺ��� �κп� B�� �ܾ� �ֱ� + B�� index��ĭ �ڷ� �̵�(���� �ܾ��)
					break; 
				}
			}
		}
	}

	strcpy(tmp, wordA[0]); //���ڿ�A���� �ߺ� �ܾ� ���� �迭�� �ܾ�� �ϳ��� tmp�� ���
	strcat(tmp, " ");
	// ó������ �� ���ڰ� �����Ƿ� strcpy���� �ϱ�
	for (int i = 1; i < idxA; i++)
	{
		strcat(tmp, wordA[i]);
		strcat(tmp, " ");
	}
	printf("%s", tmp);
	return 0;
}