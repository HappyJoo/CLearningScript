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


// input a string with or without a space
#include <stdio.h>
// create a string array
char str[100];

// main function
int main() {

    // input a string
    // [^\n] : the scanset is all characters except \n
    // means that don't count it as the input string unless there's a '\n' which is the enter key in your keyboard.
    // Regular Expression
    scanf("%[^\n]s", str);

    // print the string
    printf("%s\n", str);

    // return
    return 0;
}


// print multiplication table
#include <stdio.h>
// main function
int main() {

    // first loop
    for (int i = 1; i <= 9; i++ ) {

        //second loop
        for ( int j = 1; j <= i; j++) {

            // either 'j == 1' is true or 'printf("\t")' is true
            // the interest point of '||' is that, it's running from left to right
            // so if the front part 'j==1' is true, it won't run the second part
            // so to speak, when j==1, don't print \t
            // and printf is always true
            // after 1, there will be a \t before next line
            // the point of this line is to add a \t between every multiplication expression
            // so of course you can use another way to add it
            // but remember, we don't want the \t you add at the end of line
            j == 1 || printf("\t");

            // print the expression
            printf("%d * %d = %d", j, i, i * j);
        }

        // next line
        printf("\n");
    }

    //return
    return 0;
}
        

// design a tiny random function
// not quite understand this one though
#include <stdio.h>
int main() {
    int n = 5;
    for (int i = 1; i <= 100; i++) {
        printf("%2d ", n);
        if (i % 10 == 0) printf("\n");
        n = (n * 3) % 101;
    }
    return 0;
}


// input 2 int number n & m, then input n int number [few number].
// n <= 10, m <= 10000
// from 1 to m, which number cannot be divided by any number in [few number]
// output them.
// like input first:3 12    input second:4 5 6
// it will output: 1 2 3 7 9 11
#include <stdio.h>

// create an array
int check[1005] = {0};

// main function
int main() {

    // create int
    int n, m, num;

    // first input. remember there's a space between your two number
    scanf("%d%d", &n, &m);

    // loop n times because that's the quantity of number you input
    for (int i = 0; i < n; i++) {

        // input n numbers seperated by space
        scanf("%d", &num);

        // use num=num+num to check if the number from 1 to m
        // can be divided by num or not
        // If it does, check it in the check array
        // and then output it.
        for (int j = num; j <= m; j += num) {
            check[j] = 1;
        }
    }

    // output required number
    for (int i = 1; i <= m; i++) {
        if (check[i] == 1) continue;
        printf("%d ", i);
    }
    return 0;
}


// use sprintf to achieve strlen, strcpy, strcat
#include <stdio.h>
char str1[1000], str2[1000];
int main() {
    scanf("%s%s", str1, str2);
    printf("str1 = %s\tstr2 = %s\n", str1, str2);
    
    // strlen(str1)
    // sprintf will return the digit of the string
    int i = sprintf(str1, "%s", str1); 
    printf("%d\n", i);
    
    // strcpy(str1, str2)
    // input str2 to str1 which is called copy
    sprintf(str1, "%s", str2);
    printf("str1 = %s\tstr2 = %s\n", str1, str2);

    // strcat(str1, str2)
    // concatenation
    sprintf(str1, "%s%s", str1, str2);
    printf("str1 = %s\tstr2 = %s\n", str1, str2);
    return 0;
}


// Output every digit of a string without using strlen,
// or any function that can count the string
#include <stdio.h>
int main() {
    char str[1000];
    scanf("%s", str);

    // The interest part is here.
    // You need to know that the last character in a string,
    // is not THE last character, but a "\0".
    // It means the end of the string.
    // So takes "geek" for example. You can see it has 4 character.
    // But it actually has a "\0" in the end.
    // So it has 5 character.
    // In the for loop, when the condition is 0, it will stop.
    for (int i = 0; str[i]; i++) {
        printf("%c\n", str[i]);
    }
    return 0;
}
