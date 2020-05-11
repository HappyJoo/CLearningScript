// Chinese leetcode : https://leetcode-cn.com/problems/add-strings/
char * addStrings(char * num1, char * num2){
    short l1 = strlen(num1), l2 = strlen(num2);
    short maxlen = l1 > l2 ? l1 : l2;
    char *res = calloc(maxlen+3, sizeof(char));
    res[maxlen+2] = '\0';
    short carry = 0;
    for(l1--, l2--, maxlen++; l1 >= 0 || l2 >= 0 || carry;) {
        carry += (l1 >= 0 ? num1[l1--] - 48 : 0) + (l2 >= 0 ? num2[l2--] - 48 : 0);
        res[maxlen--] = carry % 10 + 48;
        carry /= 10;
    }
    return &res[maxlen+1];
}