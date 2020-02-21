#include <stdio.h>

/*
The goal is calculate 2 to the 1000. But we have to use array.
We create an array. The first element will be the number of digits of the final result.
And from the second element (num[1]), the result is in reverse order.
Meaning like '2 to the 10' is [4 4 2 0 1], which is 1024 and having 4 digits.
It's more convenient to write the problem in reverse order.
In positive order will be very complicate which I don't know how to write yet.
*/

int main() {
    // Since our goal is to calculate 2 to the 1000,
    // we can just initialize the array with 1.
    // 'num[0]' means the digit of the result.
    int num[1000] = {1,1};

    // Loop start. 1000 times.
    for (int i = 1; i <= 1000; i++) {

        // Multiply every digit with 2 except 'p[0]'.
        for (int j = 1; j <= num[0]; j++) num[j] *= 2;

        // If bigger than 10, get its remainder and next digit plus 1 .
        // For example:
        // 2 to the 9: [3 2 1 5] --> [3 4 2 10] --> [4 4 2 0 1] which is 2 to the 10.
        for (int k = 1; k <= num[0]; k++) {

            // Do nothing if it's less then 10.
            if (num[k] < 10) continue;

            // Only compare if it's the last digit of the result.
            // And it will not "++" forever since there is a "num[k] < 10" before.
            if (k == num[0]) num[0]++;
            
            // If the digit is bigger than 10,
            // it will get its remainder,
            // and the next digit will plus one.
            num[k + 1] += 1;
            num[k] %= 10;
        }
    }

    // The digit number of the result.
    printf("%d ", num[0]);

    // Don't know how to not print those zeroes yet.
    for (int n = 500; n >= 1 ; n--) {
        printf("%d", num[n]);
    }

    printf("\n");
    return 0;
}