#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}node;

node* make_node(int val, node* l, node* r){
    node* tmp = (node*)malloc(sizeof(node));
    tmp -> value = val;
    tmp -> left = l;
    tmp -> right = r;
    return tmp;
}
void print(node* root, int ck){
    if(root == NULL) return;
    printf("%d\n", root -> value);
    if(ck){
        print(root -> right, !ck);
        printf("%d\n", root -> value);
        print(root -> left, !ck);
    }else{
        print(root -> left, !ck);
        printf("%d\n", root -> value);
        print(root -> right, !ck);
    }
}
int char2num(char s[]){
    int len = strlen(s);
    int ret = 0;
    for(int i = 0;i < len;i++){
        ret *= 10;
        ret += (s[i] - '0');
    }
    return ret;
}
int main(){
    char s[4001];
    node* a[1000];
    scanf("%s", s);
    int len = strlen(s);
    int own = 0;
    for(int i = 0;i < len;i++){
        if(s[i] == ',') continue;
        if(s[i] == '(') continue;
        if(s[i] == ')'){
            a[own - 2] = make_node(a[own - 2] -> value + a[own - 1] -> value, a[own - 2], a[own - 1]);
            own--;
        }else{
            char tmp[5];
            int j = i;
            for(;j < len;j++){
                if(!isdigit(s[j])) break;
                tmp[j - i] = s[j];
                tmp[j - i + 1] = 0;
            }
            i = j - 1;
            int num = char2num(tmp);
            a[own] = make_node(num, NULL, NULL);
            own++;
        }
    }
    print(a[0], 0);

    return 0;
}