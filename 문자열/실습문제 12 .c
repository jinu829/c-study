#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
    /*
    str1�� ���ڿ� ���� ������ ������ str�� ���� �ϳ��ϳ��� �ݺ������� �����鼭 
    �� ��° ���ڿ�(str2)�� ���ڿ��� ��ġ�ϴ� �κ��� �ִ��� ����, ��ġ�ϴ� �κ��� ������ ī��Ʈ

    �̹� Ƚ�� ��꿡 ���� ���ڴ� �ٽ� ������� �����Ƿ�, ��ġ�ϴ� �κ��� �ִٸ� 
    �� ��ġ�ϴ� �κи�ŭ�� �ǳʶپ�� ��.
    */
    char str1[81] = { '\0' }; 
    char str2[81] = { '\0' };

    gets(str1); //str1�� str2�Է¹ޱ�
    scanf("%s", str2);

    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int i = 0;
    int cnt = 0;
    int flag = 0;

    while (str1[i] != '\0') { //str1���ڿ� ���� ������
        if (str1[i] == '\0') break;
        cnt = 0; //Ƚ�� �ʱ�ȭ
        for (int j = 0; j < str2_len; j++) { //str[i]�κк��� str2�� ���̵��� ��� ���ڰ� ������ üũ
            if (str1[i + j] == str2[j]) {
                cnt++;
            }
        }
        if (cnt == str2_len) {
            flag++; //���� ���� ������ ���� str2�� ���̿� �Ȱ��ٸ� ���� �Ȱ��� ���̴� ī��Ʈ
            i = i + str2_len; //��ġ�ϴ� �κи�ŭ �ǳʶٱ�
        }
        else {
            i++;
        }
    }

    printf("%d", flag);

    return 0;
}

