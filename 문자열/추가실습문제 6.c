#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void StringAdd(char arr[], char ch, int index);

int Convertor(char x);

int main()
{

	/*
	   ������ ������ �����ϸ�
	   ���� �� �ִ� �� ���� ��Ȳ
	   1. ¦ + ¦
	   2. Ȧ + Ȧ
	   3. Ȧ + ¦
	   4. ¦ + Ȧ
	   �ٵ� 3, 4���� �������� �ƹ� ���� ���� �ʾƵ� �ȴ� �����Ƿ�
	   �츮�� 1, 2���� �Ű澲�� �ȴ�.
	*/

	char str[20] = { '\0' };
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < len - 1; i++)
	{
		if (Convertor(str[i]) % 2 == 0) //1�� ��Ȳ -> ���̿� * �ɱ�
		{
			if (Convertor(str[i + 1]) % 2 == 0)
			{
				StringAdd(str, '*', i + 1);
				len++;
				i++;
			}
		}
		if (Convertor(str[i]) % 2 != 0) //2�� ��Ȳ -> ���̿� + �ɱ�
		{
			if (Convertor(str[i + 1]) % 2 != 0)
			{
				StringAdd(str, '+', i + 1);
				len++;
				i++;
			}
		}
	}
	printf("%s", str);

	return 0;
}

void StringAdd(char arr[], char ch, int index) 
{
	for (int i = strlen(arr) + 1; i > index; i--) //�� ������ġ�� int i = strlen(arr) + 1 �ϱ�? i = strlen(arr)�� �ƴ϶�?
	{
		arr[i] = arr[i - 1]; //�ε�����° ���Һ��� �� ĭ�� �ڷ� �̷��
	}
	arr[index] = ch; //�ε��� �κп� '+'÷��
}

int Convertor(char x)
{
	return atoi(&x); //atoi���� �ƽ�Ű �ڵ带 �ᵵ ����
}