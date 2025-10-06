#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996) 

int main() {
    char A[101] = { '\0' }; 
    char B[11] = { '\0' }; 
    char C[11] = { '\0' }; 
    char temp[200];
    int N, M, i;

    gets(A); // 문자열 A, B, C 입력
    gets(B); 
    gets(C); 

    N = strlen(B);
    M = strlen(C);

    for (i = 0; A[i]; ) // A값 변하므로 계산 안됨
    {
        if (strncmp(A + i, B, N) == 0) // 일단 같은 부분 나올 때까지 i올리기
        {
            strcpy(temp, A); // 일단 카피
            strcpy(temp + i, C); // temp에 C의 부분 넣기
            strcat(temp, A + i + N); // temp에 C부분 넣고 그 뒤 부분 넣기
            strcpy(A, temp);
            i = i + M; // 삽입 단어 다음 문자로 이동하기
        }
        else
            i++; //아니라면 똑같은 단어 나올 때까지 i추가
    }
    printf("%s", A); // 출력



    return 0;
}