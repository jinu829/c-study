#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
    /*
    str1의 문자열 끝에 도달할 때까지 str의 문자 하나하나를 반복문으로 훑으면서 
    두 번째 문자열(str2)의 문자열과 일치하는 부분이 있는지 보고, 일치하는 부분이 있으면 카운트

    이미 횟수 계산에 사용된 문자는 다시 사용하지 않으므로, 일치하는 부분이 있다면 
    그 일치하는 부분만큼은 건너뛰어야 함.
    */
    char str1[81] = { '\0' }; 
    char str2[81] = { '\0' };

    gets(str1); //str1과 str2입력받기
    scanf("%s", str2);

    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int i = 0;
    int cnt = 0;
    int flag = 0;

    while (str1[i] != '\0') { //str1문자열 범위 내에서
        if (str1[i] == '\0') break;
        cnt = 0; //횟수 초기화
        for (int j = 0; j < str2_len; j++) { //str[i]부분부터 str2의 길이동안 모든 문자가 같은지 체크
            if (str1[i + j] == str2[j]) {
                cnt++;
            }
        }
        if (cnt == str2_len) {
            flag++; //만약 같은 문자의 수가 str2의 길이와 똑같다면 둘이 똑같은 것이니 카운트
            i = i + str2_len; //일치하는 부분만큼 건너뛰기
        }
        else {
            i++;
        }
    }

    printf("%d", flag);

    return 0;
}

