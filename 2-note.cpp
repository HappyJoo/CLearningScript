// 1. Find the sum of all numbers up to 1000 in multiples of 3 or 5.
#include <stdio.h>

//There are three integer variables representing all multiples of 3 
//and sum3 up to 1000, all multiples of 5 and sum5, 
//and all multiples of 15 and sum15. And finally, 
//sum3 plus sum5 minus sum15 is the sum of multiples of 3 or 5.
int main() {
    // Arithmetic sequence summation formula: ((a0 + an) * n) / 2
    // '999 / 3 * 3' means 'an', the last number. 
    // '999 / 3' means 'n', how many multiples in there.
    int sum3 = (3 + 999 / 3 * 3) * (999 / 3) / 2;
    int sum5 = (5 + 999 / 5 * 5) * (999 / 5) / 2;
    int sum15 = (15 + 999 / 15 * 15) * (999 / 15) / 2;
    printf("%d\n", sum3 + sum5 - sum15);
    return 0;
}