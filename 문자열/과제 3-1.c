#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996) 

int main() {
    char A[101] = { '\0' }; 
    char B[11] = { '\0' }; 
    char C[11] = { '\0' }; 
    char temp[200];
    int N, M, i;

    gets(A); // ���ڿ� A, B, C �Է�
    gets(B); 
    gets(C); 

    N = strlen(B);
    M = strlen(C);

    for (i = 0; A[i]; ) // A�� ���ϹǷ� ��� �ȵ�
    {
        if (strncmp(A + i, B, N) == 0) // �ϴ� ���� �κ� ���� ������ i�ø���
        {
            strcpy(temp, A); // �ϴ� ī��
            strcpy(temp + i, C); // temp�� C�� �κ� �ֱ�
            strcat(temp, A + i + N); // temp�� C�κ� �ְ� �� �� �κ� �ֱ�
            strcpy(A, temp);
            i = i + M; // ���� �ܾ� ���� ���ڷ� �̵��ϱ�
        }
        else
            i++; //�ƴ϶�� �Ȱ��� �ܾ� ���� ������ i�߰�
    }
    printf("%s", A); // ���



    return 0;
}