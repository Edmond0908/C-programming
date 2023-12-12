#include <stdio.h>
#include <stdlib.h>

#define MAXN 16384
 
int T[MAXN];
typedef struct Node{
    int value;
    struct Node *left, *right;
} Node;

Node* make_node(int value, Node* left, Node* right){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp -> value = value;
    tmp -> left = left;
    tmp -> right = right;
    return tmp;
}
int find_mid(int l, int r, int T[]){
    if(r - l < 2) return -1;
    for(int i = l;i <= r;i++){
        long long tmp1 = 0;
        long long tmp2 = 0;
        for(int j = i - 1;j >= l;j--){
            tmp1 += (i - j) * T[j];
        }
        for(int j = i + 1;j <= r;j++){
            tmp2 += (j - i) * T[j];
        }
        if(tmp1 == tmp2) return i;
    }
    return -1;
}
Node *make_list(int l, int r, int T[]){
    if(r < l) return NULL;
    return make_node(T[r], make_list(l, r - 1, T), NULL);
}
Node *solve(int l, int r, int T[]){
    int mid = find_mid(l, r, T);
    if(mid == -1){
        return make_list(l, r, T);
    }
    return make_node(T[mid], solve(l, mid - 1, T), solve(mid + 1, r, T));
}
Node *ConstructTree(int T[], int N){
    return (solve(0, N - 1, T));
}

void PrintTree( Node *root ){
    if (root == NULL)
        return;
 
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &T[i]);
 
    Node *tree = ConstructTree(T, N );
 
    PrintTree( tree );
    return 0;
}