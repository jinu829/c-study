#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
    char str1[40], str2[20];
    int length1 = 0, length2 = 0, insert = 0;
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &insert);
    // ù ��° ���ڿ��� Ư�� ��ġ�� ���ڿ� �����ϱ� -> ù ��° ���ڿ��� ���� ��ġ ���� ���ڵ��� �� ��° ���ڿ��� ���̸�ŭ
    // �ڷ� ���� �� ���� ��ġ�� �� ��° ���ڿ��� �ϳ��� ������ ��!

    while (str1[length1] != '\0') { //str1�� ���� ���ϱ�
        length1++;
    }
    while (str2[length2] != '\0') { //str2�� ���� ���ϱ�
        length2++;
    }
    for (int i = length1; i >= insert; i--) { //�� �� ���ں��� �ϳ��� �� ��° ���ڿ�(str2)�� ���̸�ŭ �ڷ� ����
        str1[i + length2] = str1[i];
    }
    for (int i = 0; i < length2; i++) { //����ִ� ���� ��ġ���� ���ʷ� �ϳ��� str2�� ���� ����
        str1[insert + i] = str2[i];
    }
    printf("%s", str1);
    return 0;
}