#include <stdio.h>
 
int min(int a,int b){
    return a < b ? a:b;
}
int solve(int a,int b,int c,int d){
    return (a - c) * (a - c) + (b - d) * (b - d);
}
 
int main() {
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    while(scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != EOF){
        int d1 = solve(x1,y1,x4,y4);
        int d2 = solve(x2,y2,x4,y4);
        int d3 = solve(x3,y3,x4,y4);
        int ans = min(d1, min(d2, d3));
        int count = 0;
        count += (ans == d1);
        count += (ans == d2);
        count += (ans == d3);
        if(count == 3) printf("0 ");
        else if(count == 1){
            if(ans == d1) printf("1 ");
            else if(ans == d2) printf("2 ");
            else printf("3 ");
        }else{
            if(ans != d1) printf("6 ");
            else if(ans != d2) printf("5 ");
            else printf("4 ");
        }
    }
 
    return 0;
}