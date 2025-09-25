#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
    char str1[40], str2[20];
    int length1 = 0, length2 = 0, insert = 0;
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%d", &insert);
    // 첫 번째 문자열의 특정 위치에 문자열 삽입하기 -> 첫 번째 문자열의 삽입 위치 뒤의 문자들을 두 번째 문자열의 길이만큼
    // 뒤로 보낸 후 삽입 위치에 두 번째 문자열을 하나씩 넣으면 끝!

    while (str1[length1] != '\0') { //str1의 길이 구하기
        length1++;
    }
    while (str2[length2] != '\0') { //str2의 길이 구하기
        length2++;
    }
    for (int i = length1; i >= insert; i--) { //맨 뒤 문자부터 하나씩 두 번째 문자열(str2)의 길이만큼 뒤로 빼기
        str1[i + length2] = str1[i];
    }
    for (int i = 0; i < length2; i++) { //비어있는 삽입 위치부터 차례로 하나씩 str2의 원소 대입
        str1[insert + i] = str2[i];
    }
    printf("%s", str1);
    return 0;
}