// Highly recommend:https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Euler's_sieve
// The Sieve of Euler is more efficient than Sieve of Eratosthenes.
// It only flags the prime once, saving a lot of time.
// But of course it's a little bit difficult to understand.

// Time Complexity: O(n) 
// Space Complexity: ? (Shoulb be bigger than Sieve of Eratosthenes)


#include <stdio.h>
#define MAXN 1000

bool isprime[MAXN];
int prime[MAXN];

int main() {
    int k = 0;
    for(int i = 2; i <= MAXN; i++){
        
        // If it's prime, put it into prime[].
        if(!isprime[i]) prime[k++] = i;

        // It's been proved by Euler that when 'i % prime[j] == 0',
        // you can break the inner loop.
        // 'j' smaller than the amount of recorded prime.
        // 'i * prime[j]'
        for(int j = 0; j < k && i * prime[j] <= MAXN; j++){
            isprime[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
   }

    int sum;
    // So all the 0 in prime will be prime. Meanwhile, 1 means true, 0 means false.
    for (int n = 1; n <= MAXN; n++) {
        if (!isprime[n]) {
            printf("%d ",n);
            sum += n;
        }
    }
    printf("-->Sum = %d\n", sum);
   return k;
}