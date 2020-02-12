#include <stdio.h>
#include <stdarg.h>

void my_scanf(char const *str, ...) {
    // num for addtion before space' '
    // flag = 0 means the number is positive, 1 means it's negative.
    int num = 0, flag = 0;
    
    // *p for saving input int memory address
    int *p = NULL;

    // initialize using va_list
    va_list valist;
    // start from the first parameter
    va_start(valist, str);

    // I guess this is the second parameter
    p = va_arg(valist, int*);
    
    // '1' - '0' == 1  it's not a subtraction between this two string
    // but the subtration of their ASCII value
    // (here is 49 for '1' minus 48 for '0')
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            if (flag == 1) {
                num = -num;
                flag = 0;
            } 
            *p = num;

            if (str[i+1] == '-') {
                flag = 1;
                i++; // Once here, once in for loop
            }

            // get next int address
            p = va_arg(valist, int*);
            
            // reset num so it can be used again
            num = 0;
        } else {
            num = num * 10 + (str[i] - '0');
        }
    }
    if (flag == 1) num = -num;
    *p = num;
    
    // delete the memory created for valist
    va_end(valist);


    return ;
    
}

// don't know how to write this program to be used directly in the console yet. Can only be input from the script here.
int main() {
    int n,m,l,j;
    my_scanf("199", &n);
    printf("n = %d\n", n);
    
    my_scanf("19 38 1", &n, &m, &l);
    printf("n = %d\tm = %d\n %d", n, m, l);
    return 0;
}


