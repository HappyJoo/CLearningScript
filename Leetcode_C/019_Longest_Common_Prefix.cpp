
// compare every digit 
char * longestCommonPrefix(char ** s, int strsSize){
    if (strsSize == 0) return "";
    for (int i = 0; i < strlen(s[0]); i++) {
        for (int j = 0; j < strsSize; j++) {
            if (s[0][i] != s[j][i]){
                s[0][i] = '\0';
                break;
            }
        }
    }
    return s[0];
}

