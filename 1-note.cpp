// This is not a file for gcc, but you can select dome of the code to another file to complie.


// Output digit of a number. 
// You enter a number and it tells you how many digits it has.
#include <stdio.h>
    
int main() {
    // create int n
    int n;

    // get a number and put it into n
    scanf("%d", &n);

    // the second printf will run first. 
    // the string part in the second 'printf' will output first.
    // then after it finished, it returns a number that representing how many digit the string it has.
    // you can try adding some character to the second 'printf' and see how many digit it gives you.
    printf(" has %d digits\n", printf("%d", n));

    // create a string array
    char output[50];

    // since the printf can return digit number.
    // so I guess sprintf can return a digit number as well.
    int ret = sprintf(output, "%d", n);

    // you can use this sentence to check. It combine row27 he row33 to one scirpt.
    // printf("%d\n", sprintf(output, "%d", n));
    
    // print the string
    printf("%d\n", ret);

    // return 0
    return 0;
}
