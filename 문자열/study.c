#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void)
{
	char str1[100] = "Hello";
	char str2[100] = "World";
	char str3[100];

	printf("%d\n", strlen(str1));

	strcpy(str3, str1); //str3�� str1����
	printf("%s\n", str3);

	strcat(str3, " "); // ���� ���̱�
	strcat(str3, str2); //�ڿ� str2���̱�
	printf("%s\n", str3);

	strcpy(str1, str2); //�� ó�� �����̵忡�� ������ ���ڿ��� �ٲٴ� ���
	if (strcmp(str1, str2) == 0) //str1�� str2�� ���⿡ 0�� ��ȯ
		printf("they are same\n");

	strcpy(str3, "30"); //str3�� ù��° ĭ�� ���ڿ� 30 ����
	printf("%d", atoi(str3)); //���� 30���
	//strcpy, strcat�� ���ڿ� ����, ���̱� �� �ڵ����� '\0'���ڸ� �ٿ��ش�.
}


