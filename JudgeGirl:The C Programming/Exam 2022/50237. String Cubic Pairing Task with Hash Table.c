#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
typedef struct HashTable{
    char string[6];
    int location;
    int current;
}HashTable;
 
int max(int a,int b){
    return a>b?a:b;
}
int find(HashTable hash[10000][10],char t[6],int key,int len){
    int ret;
 
    for(int i=0;i<10;i++){
        if(hash[key][i].string[0]=='-') ret=i;
        else{
            int check=1;
            for(int j=0;j<len;j++){
                if(hash[key][i].string[j]!=t[j]) check=0;
            }
            if(check) return i;
        }
    }
    return -(ret+1);
}
void solve(int i,int j,int cur,int n,HashTable hash[10000][10],char s[100][100][100][6]){
    if(cur>=n-max(i,j)) return;
    int key=0;
    int len=0;
    while(s[cur][i][j][len++]!=0);
    //printf("checking len: %d\n",len);
    for(int l=0;l<len-1;l++){
        key+=s[cur][i][j][l]-'a'+1;
        key*=29;
    }
    key+=s[cur][i][j][len-1]-'a'+1;
    key=key%(n*n);
    int f=find(hash,s[cur][i][j],key,len);
    if(f<0){
        f=-(f+1);
        for(int l=0;l<len;l++) hash[key][f].string[l]=s[cur][i][j][l];
        hash[key][f].string[len]=0;
        hash[key][f].location=i*n+j;
        hash[key][f].current=cur;
    }else{
        printf("%s\n",hash[key][f].string);
        int index=hash[key][f].location;
        int x=index/n;
        int y=index%n;
 
        int k=hash[key][f].current+1;
        hash[key][f].string[0]='-';
        solve(x,y,k,n,hash,s);
        solve(i,j,cur+1,n,hash,s);
    }
}
 
int main(){
 
    int n;
    scanf("%d",&n);
 
    HashTable hash[10000][10];
    char s[100][100][100][6];
    int own[100][100]={0};
 
    for(int t=0;t<n;t++){
        for(int i=0;i<=t;i++){
            for(int j=0;j<=t;j++){
                scanf("%s",s[own[i][j]][i][j]);
                int len=strlen(s[own[i][j]][i][j]);
                s[own[i][j]][i][j][len]=0;
                own[i][j]++;
            }
        }
    }
 
    for(int i=0;i<n*n;i++){
        for(int j=0;j<10;j++){
            hash[i][j].string[0]='-';
        }
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            solve(i,j,0,n,hash,s);
        }
    }
 
    return 0;
}