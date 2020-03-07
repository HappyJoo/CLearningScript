#include<stdio.h>
#define MAX_N 1000

// For a better understand, I print a lot. Like, a lot!
int q[MAX_N + 5], head, tail;
void interval_max_number(int *a, int n, int m) {
    head = tail = 0;

    // Print for better understand.
    printf("a=[");
    for (int i = 0; i < n; i++) {
        if (i!=n-1) {
            printf("%d,", a[i]);
        } else printf("%d]\n",a[i]);
    }

    for (int i = 0; i < n; i++) {
            printf("i=%d----a[i]=%d,", i, a[i]); // Print for better understand.
        
        // a[i] 入队，将违反单调性的从队列 q 中踢出
        while (head < tail && a[q[tail - 1]] < a[i]) {
            printf("%d<%d,",a[q[tail]], a[i]); // Print for better understand.
            tail--;
            printf("t=%d,q[t--]=%d,", tail,q[tail]); // Print for better understand.
        }
        q[tail++] = i; // i 入队
            printf("t++=%d,q[t-1]=%d,", tail, q[tail-1]); // Print for better understand.

        // 判断队列头部元素是否出了窗口范围
        if (i - m == q[head]) {
            printf("h=%d,q[h]=%d,",head,q[head]); // Print for better understand.
            head++;
        }

        // Print for better understand.
        printf("q=[");
        for (int i = 0; i < tail; i++) {
            if (i!=tail-1) {
                printf("%d,", a[q[i]]);
            } else printf("%d],",a[q[i]]);
        }

        // 输出区间内最大值
        if (i + 1 >= m) {
            printf("interval(%d, %d)", i - m + 1, i);
            printf(" = %d", a[q[head]]);
        }

        printf("\n");
    }
    return ;
}

int main() {
    int a[8] = {1,3,-1,-3,5,3,6,7};
    int m = 3, n = 8;
    interval_max_number(a, n, m);
    return 0;
}
