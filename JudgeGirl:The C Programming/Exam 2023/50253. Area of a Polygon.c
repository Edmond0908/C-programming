#include <stdio.h>
 
int main() {
    int n;
    scanf("%d", &n);
    int X, Y;
    int ans = 0;
    scanf("%d%d", &X, &Y);
    int x1, y1, x2, y2;
    x1 = X, y1 = Y;
    for(int i = 0;i < n - 1;i++){
        scanf("%d%d", &x2, &y2);
        ans += (x1*y2)-(x2*y1);
        x1 = x2, y1 = y2;
    }
    ans += (Y * x1) - (X * y1);
    printf("%d", ans);
 
    return 0;
}