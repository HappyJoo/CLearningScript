// Strongly Recommend:https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// In wikepedia, it has an amazing GIF that showes how the Sieve of Eratosthenes is done!!

// Time Complexity: O(nloglogn) 
// Space Complexity: O(n)
#include <stdio.h>
#define MAXN 1000

int prime[MAXN + 5] = {}; // Initialize. Plus 5 is just an habit picked up from my teacher.
int main() {
    for (int i = 2; i * i <= MAXN; i++){
        if (prime[i]) continue; // If it's 1 means we set it to composite already.
        
        // Start from i * 2, and add i every time.
        for (int j = i * 2; j <= MAXN; j += i) {
            prime[j] = 1; // If it's not prime, flag it as 1.
        }
    }

    int sum;
    // So all the 0 in prime will be prime. Meanwhile, 1 means true, 0 means false.
    for (int n = 1; n <= MAXN; n++) {
        if (!prime[n]) {
            printf("%d ",n);
            sum += n;
        }
    }
    printf("-->Sum = %d\n", sum);
}