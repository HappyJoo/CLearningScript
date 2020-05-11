#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * multiply(char * num1, char * num2)
{
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int totalLength = length1 + length2;                     //获取相乘后字符串的总有效位数
    
    int charIndex = 0;                                       //定义负责索引字段
    int valueIndex = 0;
    
    int *value = (int*)calloc(totalLength, sizeof(int));
    
    char *result = (char*)calloc(totalLength + 1, sizeof(char));
    
    for(int i = length1  - 1; i >= 0; i--)
    {
        for(int j = length2 - 1; j >= 0; j--)
        {
            value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            printf("i:%d, j:%d, i+j:%d,\n",i,j,i+j);
        }
    }
    
    for(int i= totalLength - 1; i > 0; i--)                 //获取每个位置上面的数字并处理进位
    {
        value[i - 1] += value[i] / 10;
        value[i] %= 10;
    }
    
    while(value[valueIndex] == 0 && valueIndex < totalLength -1 ) 
    {
        valueIndex++;                                        //忽略掉前面多余的0，但是最高位也就是唯一的一位0不能忽略
    }
    while(valueIndex < totalLength)
    {
        result[charIndex++] = value[valueIndex++] + '0';
    }
    
    result[charIndex] = '\0';                                //默认补上字符串的终止符
    
    return result;
}

int main() {
    char c1[10] = "21";
    char c2[10] = "12";
    multiply(c1,c2);
    return 0;
}