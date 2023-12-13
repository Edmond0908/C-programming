#include <stdio.h>
#include <stdlib.h>
#define MAXN 16384

int MAXLENGTH;
typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}Node;

Node* make_node(int value, Node* left, Node* right){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp -> value = value;
    tmp -> left = left;
    tmp -> right = right;
    return tmp;
}
Node* make_list(int l, int r, int a[]){
    if(r < l) return NULL;
    return make_node(a[r], make_list(l, r - 1, a), NULL);
}
int cmp(const void* a, const void* b){
    int tmp1 = *(int*)a;
    int tmp2 = *(int*)b;
    if(tmp1 == tmp2) return 0;
    if(tmp1 < tmp2) return 1;
    return -1;
}
int find_k(int l, int r, int a[]){
    if(r - l + 1 < MAXLENGTH) return -1;
    int tmp[16384];
    for(int i = 0;i < r - l + 1;i++) tmp[i] = a[i + l];
    qsort(tmp, r - l + 1, sizeof(int), cmp);
    for(int i = l;i <= r;i++){
        if(a[i] == tmp[MAXLENGTH - 1]) return i;
    }
}
Node* solve(int l, int r, int a[]){
    int find = find_k(l, r, a);
    if(find == -1) return make_list(l, r, a);
    return make_node(a[find], solve(l, find - 1, a), solve(find + 1, r, a));
}
Node* ConstructTree(int sequence[], int N){
    return (solve(0, N - 1, sequence));
}

int sequence[MAXN];

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
    scanf("%d%d", &N, &MAXLENGTH);
    for (int i=0; i<N; i++)
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}