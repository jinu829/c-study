#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int passengerN(int n);

void rebooking(int* ar);

int changeseat(int* ar);

int main()
{
	int N;
	int ar[21] = { '\0' }; // = { '\0' }�̰� �� �� �ɱ��?
	scanf("%d", &N);

	for (int* i = ar; i < ar + N; i++) //�°� �� �Է�
	{
		scanf("%d", i); 
	}
	if (passengerN(N) == -1) // ���� �°� ���� �����ϴٸ�
		printf("-1");
	else // �°� ���� ����ϴٸ�
	{
		printf("0\n"); //0���

		rebooking(ar); //�ߺ� Ȯ�� �ϰ�, �ٲٰ�

		for (int* i = ar; i < ar + N; i++) // ���
		{
			printf("%d ", *i);
		}
	}

	return 0;
}

int passengerN(int n) 
{
	if (n >= 5)
		return 0;
	else
		return -1;
}

void rebooking(int* ar) 
{
	for (int* i = ar; *i != '\0'; i++) 
	{
		for (int* j = ar; *j != '\0'; j++) //�ߺ����� Ȯ���ϰ�, ���� �ߺ��̴�? �ٲٱ�(changeseat�Լ� ȣ��)
		{
			if (*i == *j)
			{
				if (i != j) //�ߺ��� �� �� ù ��°�� �ƴ� ���� �ٲ�� �ϱ� ������ ���ǹ� �ۼ�
				{
					*j = changeseat(ar); //j�� �ߺ��Ǽ� ������ �κ� : changeseat���� �ٲ� �� ����
				}
			}
		}
	}
}

int changeseat(int* ar) //�迭�� ���� �� �� ���� ���� �� : 1���� �����ؼ� �ߺ��� ���� ������ 1 �߰��ϰ�, �ݺ��ϰ�... ����� �ݺ��ϸ� ���ϴ� ���� �����ڳ�?
{ 
	int count = 1;
	for (int* i = ar; *i != '\0'; i++)
	{
		for (int* j = ar; *j != '\0'; j++)
		{
			if (*j == count)
				count++;
		}
	}
	return count; //j���� ���ԵǴ� ��
}