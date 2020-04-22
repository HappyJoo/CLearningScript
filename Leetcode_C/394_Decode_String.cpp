
// Solution 1 Recursion
#define STR_LEN 5000
char * decodeStringCore(char *s, char **e) {
    char *ret = (char*)malloc(sizeof(char) * STR_LEN);
    char *buf, *end = NULL;
    int count = 0, idx = 0;

    while(*s != '\0') {
        if (isalpha(*s)) {
            ret[idx++] = *s;
        } else if (isdigit(*s)) {
            count = 10 * count + *s - '0';
        } else if (*s == '[') {
            buf = decodeStringCore(s + 1, &end);
            while (count) {
                strcpy(ret + idx, buf);
                idx += strlen(buf);
                count--;
            }
            s = end;
        } else if (*s == ']') {
            *e = s;
            ret[idx] = '\0';
            return ret;
        }
        s++;
    }
    ret[idx] = '\0';
    return ret;
}

char * decodeString(char * s){
    char *end = NULL;
    return decodeStringCore(s, &end);
}


// Solution 2 Stack

char * decodeString(char * s){
    int size = 5000, top = -1, len = strlen(s);
    char *stack = (char*)malloc(size * sizeof(char));

    for(int i = 0; i < len; i++)
    {
        // Add everything to 'stack' from 's' until there's a ']'.
        if(s[i] != ']')
            stack[++top] = s[i];
        else {
            int tempsize = 50, temptop = -1;

            // 'temp' is for storing string in [].
            char *temp = (char*)malloc(tempsize * sizeof(char));
            while(stack[top] != '[')
            {
                // Remember there's "==", not "=" !!!!!!!!
                if(temptop == tempsize - 1)
                    temp = realloc(temp, tempsize+=1 * sizeof(char));
                temp[++temptop] = stack[top--];
            }

            /*  'strint' stores the number before [].
                Move 'top' to the digit before number.
                Then 'k = top + 1' is starting from the number digit.
                Remember here, to put number digits to 'strint',
                it has to start from left to right.
                I tried from right to left but i failed.
                Like '123', it has to be '1', then '2', then '3'.
                If you want to add '3' first, I don't know, might be difficult.
            */
            char strint[10];
            int p = --top, j = 0; // 'top' is '[' now. Need to decrese one.
            while(top != -1 && stack[top] >='0' && stack[top] <= '9') top--;
            for(int k = top + 1;k <= p;)
                strint[j++] = stack[k++];
                
            /*  Need to end 'strint'. 
                For example. "3[a20[bc]]"
                'strint' will be 20 at first round.
                Then it should be 3 at the second round.
                However since you didn't put an end after '3',
                it becomes 30 instead. */
            strint[p - top] = '\0'; 

            // Move 'temp' to 'stack'.
            for(int k = 0; k < atoi(strint); k++)
            {
                int r = temptop;
                while(r != -1)
                    stack[++top] = temp[r--];
            }
            free(temp);
        }
    }
    char *ans = realloc(stack, (top+2)*sizeof(char));
    ans[++top] = '\0';
    return ans;
}

// Solution 3 stack but with hand-write stack. REALLY LONG!!
typedef struct {
    char *preStr;
    int num;
} Node;

Node g_stack[100];
int g_top = 0;

char *g_retChar = NULL;

void StackInit()
{
    g_top = -1;
}

void StackAdd(int num, char *s)
{
    g_top++;
    if (strlen(s) == 0) {
        g_stack[g_top].preStr = NULL;
    } else {
        g_stack[g_top].preStr = malloc(strlen(s) + 1);
        strcpy(g_stack[g_top].preStr, s);
    }
    g_stack[g_top].num = num;
}

Node* GetStackNode()
{
    if (g_top == -1) {
        return NULL;
    }
    return g_stack + g_top;
}

void StackPop()
{
    free(g_stack[g_top].preStr);
    g_top--;
}

int GetNumProc(char* s, int *num)
{
    int i = 0;
    int ret = 0;
    char locNum[10];
    while (s[i] >= '0' && s[i] <= '9') {
        locNum[i] = s[i];
        i++;
    }
    locNum[i] = '\0';
    *num = atoi(locNum);
    return strlen(locNum);
}

int InitRetProc(char* s)
{
    int i = 0;
    while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
        i++;
    }
    strncat(g_retChar, s, i);
    // memcpy(g_retChar, s, i);
    // g_retChar[i] = '\0';
    return i;
}

void ClearRetProc()
{
    g_retChar[0] = '\0';
}

int UpdateRetProc()
{
    Node* tmpNode = GetStackNode();
    char tmp[10000];
    int idx = 0;
    if (tmpNode->preStr != NULL) {
        strcpy(tmp, tmpNode->preStr);
        idx += strlen(tmpNode->preStr);
    }

    for (int i = 0; i < tmpNode->num; i++) {
        idx += sprintf (tmp + idx, "%s", g_retChar);
    }
    strcpy(g_retChar, tmp); 
    return 0;
}

char * decodeString(char * s){
    int i = 0;
    int locNum = 0;
    int stepLen = 0;
    g_retChar = malloc(100000);
    g_retChar[0] = '\0';
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            stepLen = GetNumProc(s + i, &locNum);
        } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))  {
            stepLen = InitRetProc(s + i);
        } else if (s[i] == '[') {
            StackAdd(locNum, g_retChar);
            ClearRetProc();
            stepLen = 1;
        } else if (s[i] == ']') {
            UpdateRetProc();
            StackPop();
            stepLen = 1;
        } else {
            break;
        }
        i += stepLen;
    }
    return g_retChar;
}