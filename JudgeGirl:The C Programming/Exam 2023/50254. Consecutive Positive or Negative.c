#include <stdio.h>
 
int main() {
 
    int n;
    scanf("%d", &n);
    int check = (n > 0);
    int tmp = 1;
    while(scanf("%d", &n) != EOF){
        if(check != (n > 0)){
            printf("%d ", (-1+2*check)*tmp);
            check = !check;
            tmp = 1;
        }else tmp++;
    }
    printf("%d", (-1+2*check)*tmp);
 
    return 0;
}