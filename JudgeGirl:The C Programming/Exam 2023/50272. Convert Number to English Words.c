#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>]
 
void print(int a,int b,int c,int t){
    char* dig[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    char* dig1[10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char* big[7] ={"","thousand","million","billion","trillion","quadrillion","quintillion"};
    char* dig2[10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if(a==0&&b==0){
        printf("%s %s ",dig[c], big[t]);
    }else if(a==0&&b==1){
        printf("%s %s ",dig1[c], big[t]);
    }else if(a==0&&b!=1){
        printf("%s-%s %s ",dig2[b], dig[c], big[t]);
    }else if(b==1){
        printf("%s hundred %s %s ",dig[a],dig1[c],big[t]);
    }else{
        printf("%s hundred %s-%s %s ", dig[a], dig2[b], dig[c], big[t]);
    }
}
int main(){
 
 
    char number[25];
    scanf("%s", number);
    int len = strlen(number);
    int num[25];
    num[0] = num[1] = num[2] = 0;
    int a[3]={0,2,1};
    int k = a[len%3];
    for(int i = 0;i<len;i++) num[i+k] = number[i] - '0';
 
    int t = (len+k-1) /3;
    for(int i = 0;i<len+k;i+=3){
        print(num[i],num[i+1],num[i+2],t);
        t--;
    }
 
    return 0;
}