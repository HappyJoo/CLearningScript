1...
#include <stdio.h>

int main() {
    int a, *p = &a;
here:   char *q = reinterpret_cast<char*>(&a);
    //char *q = (char *)&a;
    printf("%p %p\n", p, q);
    printf("%p %p\n", p+1, q+1);
    return 0;
}


2... lesson 12 JKSJ
#include <stdio.h>

int arr[100];
int print_loop(int k, int n, int total_k) {
    if (k == 0) {
        for (int i = total_k; i >= 1; i--) {
            if (i != total_k) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        arr[k] = i;
        print_loop(k - 1, n, total_k);
    }
    return ;
}

int main() {
    print_loop(5,5,5);
    return 0;
}


3... lesson 14 JKSJ

#include <stdio.h>

// 打印一个素因子，并且在中间输出 * 乘号
void print_num(int num, int *flag) {
    if (*flag == 1) printf(" * ");
    printf("%d", num);
    *flag = 1;
    return ;
}

int main() {
    int n, i = 2, flag = 0, raw_n;
    scanf("%d", &n);
    raw_n = n;
    // 循环终止条件，循环到 n 的平方根结束
    while (i * i <= n) {
        //①：只要 n 可以被 i 整除，就认为 i 是 n 的一个素因子
        while (n % i == 0) {
            print_num(i, &flag);
            n /= i;
        }
        i += 1;
    }
    //②：如果最后 n 不等于 1，就说明 n 是最后一个素数
    if (n != 1) print_num(n, &flag);
    printf(" = %d\n", raw_n);
    return 0;
}
Explain one and two.


4... lesson 15 JKSJ

int g_cnt[MAX_N + 5];
void init_g_cnt() {
    // 1 的因数数量就是 1 个
    g_cnt[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        int n = i, cnt = 0, p = prime[i];
        // 得到数字 n 中，包含 cnt 个最小素因子 p
        while (n % p == 0) {
            cnt += 1;
            n /= p;
        }
        // 此时数字 n 和最小素数 p 部分，就是互素的
        g_cnt[i] = g_cnt[n] * (cnt + 1);   
    }
    return ;
}