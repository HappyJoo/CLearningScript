#include <stdio.h>
#define MAX_N 1000
#define max(a, b) ((a) > (b) ? (a) : (b))
int s[MAX_N + 5], top;
int l[MAX_N + 5], r[MAX_N + 5];
int max_matrix_area(int *h, int n) {
    h[0] = h[n + 1] = -1;
    top = -1, s[++top] = 0;
    // Find the smaller rectangle on the LEFT.
    for (int i = 1; i <= n; i++) {
        /* 
          Imaging in the bucket, there's already some ractangles(top >= 0).
          They are stacked up like papers.
          You already have one ractangle 'h[i]' in your RIGHT hand.
          So you pick up the top one from the bucket in your LEFT hand, (Since it's a stack bucket)
          you compare it with the one in your right hand with mighty 'h[s[top]] >= h[i]'.
          Actually, 's[top]' just stores subscript of the ractangle.
          So 'h[s[top]]' is the true ractangle.
          If the left one is greater than 'h[i]', throw it away and keep looking.
          Until you get what you want, store it, the subscript to 'l[i]'.
          And since the current 'h[i]' is greater than the top one in the bucket.
          You store it in the top with 's[++top] = i'. 
        */

        /* Short explanation
        top >= 0          ---- There's value in the "stack" s.
        h[s[top]] >= h[i] ---- The top one is greater than the current one h[i].
        --top             ---- Throw the top one away.        
        */
        while (top >= 0 && h[s[top]] >= h[i]) --top;

        // AFTER throw all the big one from the stack:
        l[i] = s[top]; // Store the top one to l[].
        s[++top] = i; // Get the new top one.
    }
    // Find the smaller rectangle on the RIGHT.
    // Same as the LEFT version, just switch direction.
    top = -1, s[++top] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top >= 0 && h[s[top]] >= h[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    // Find the largest rectangle. 
    // 'ans' will always be the biggest one.
    // (r[i] - l[i] - 1) * h[i]) ---- The area.
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (r[i] - l[i] - 1) * h[i]);
    }
    return ans;
}

int main() {
    int n = 6;
    int h[100] = {2,1,5,6,2,3};
    int ans = max_matrix_area(h, n);
    printf("%d\n", ans);
}