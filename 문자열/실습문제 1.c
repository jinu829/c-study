#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	char arr[20];
	int i;
	scanf("%s", arr);
	for (i = 0; i < 20; i++)
	{
		if (arr[i] == NULL) //%s�� �޴� ��� ���ڿ��� ���� ���̹Ƿ� �ڵ����� �� �ڿ� NULL���ڰ� �����ȴ� -> ���� NULL���ڰ� ���´ٸ� ���ڿ��� ���� ���̴�!
		{
			break;
		}
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			printf("%c", arr[i]);
		}
	}
	return 0;
}