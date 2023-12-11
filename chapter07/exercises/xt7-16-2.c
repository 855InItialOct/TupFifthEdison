#include <stdio.h>

int hexToDecimal(char hex[]) {
    int decimal = 0;
    int base = 1;
    int i = 0;
    
    // 确定十六进制数的长度
    while (hex[i] != '\0') {
        i++;
    }
    i--;
    
    // 从最后一位开始，逐位转换为十进制
    while (i >= 0) {
        // 如果是数字字符，则转换为对应的数字
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        }
        // 如果是字母字符，则转换为对应的数字
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        }
        // 如果是小写字母字符，则转换为对应的数字
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * base;
        }
        
        base *= 16; // 更新基数
        i--; // 移动到下一位
    }
    
    return decimal;
}

int main() {
    char hex[100];
    
    printf("请输入一个十六进制数：");
    scanf("%s", hex);
    
    int decimal = hexToDecimal(hex);
    
    printf("相应的十进制数为：%d\n", decimal);
    
    return 0;
}