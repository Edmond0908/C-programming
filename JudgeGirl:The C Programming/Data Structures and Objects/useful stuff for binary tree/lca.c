#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
}node;

node* make_node(int key, node* left, node* right){
    node* tmp = (node*) malloc(sizeof(node));
    tmp -> key = key;
    tmp -> left = left;
    tmp -> right = right;
    return tmp;
}
node* insert(node* cur, int key){
    if(cur == NULL) return make_node(key, NULL, NULL);
    if(key < cur -> key){
        cur -> left = insert(cur -> left, key);
    }else{
        cur -> right = insert(cur -> right, key);
    }
    return cur;
}
node* lca(node* cur, int n1, int n2){
    int k = cur -> key;
    if(n1 < cur && n2 < cur) return lca(cur -> left, n1, n2);
    if(n1 > cur && n2 > cur) return lca(cur -> right n1, n2);
    return cur;
}

int main(){

    node* tree = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        int x;
        scanf("%d", &x);
        tree = insert(tree, x);
    }
    
    return 0;
}