#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void findLongestWords(const char *str) {
    int maxLength = 0;
    int currentLength = 0;
    int wordCount = 0;
    const char *longestWords[100]; // 假设最多有100个最长单词

    const char *currentWord = NULL;

    while (*str) {
        if (isalpha(*str)) {
            if (currentLength == 0) {
                currentWord = str;
            }
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                wordCount = 1;
                longestWords[0] = currentWord;
            } else if (currentLength == maxLength) {
                longestWords[wordCount] = currentWord;
                wordCount++;
            }
            currentLength = 0;
        }
        str++;
    }
    
    printf("最长的单词长度为： %d\n", maxLength);
    printf("最长的单词数量为： %d\n", wordCount);
    printf("最长的单词是： ");
    for (int i = 0; i < wordCount; i++) {
        for (int j = 0; j < maxLength; j++) {
            printf("%c", longestWords[i][j]);
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    char str[1000];

    printf("请输入一行字符：");
    fgets(str, sizeof(str), stdin);

    findLongestWords(str);

    return 0;
}