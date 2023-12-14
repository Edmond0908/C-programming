#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

typedef struct Node{
    int val;
    struct Node *left, *right;
}Node;
typedef struct list{
    Node* ptr;
    int len;
}list;
int list_len(Node* node){
    int len = 0;
    while(node != NULL){
        len++;
        node = node -> left;
    }
    return len;
}
int first_len(int n){
    return (n + 1) / 2;
}
int second_len(int n){
    return n / 2;
}
Node* pass(Node* node, int n){
    Node* ptr = node;
    for(int i = 0;i < n - 1;i++) ptr = ptr -> left;
    Node* tmp = ptr -> left;
    ptr -> left = NULL;
    return tmp;
}
void cut(list List, list *first, list *second){
    list tmp = {NULL, 0};
    if(List.ptr == NULL){
        *first = tmp;
        *second = tmp;
        return;
    }
    first -> ptr = List.ptr;
    first -> len = first_len(List.len);
    second -> ptr = pass(first -> ptr, first -> len);
    second -> len = second_len(List.len);
}
Node* solve(list list1, list list2){
    if(list1.ptr == NULL) return list2.ptr;
    if(list2.ptr == NULL) return list1.ptr;

    Node* root;
    if(list1.ptr -> val < list2.ptr -> val){
        root = list1.ptr;
        list1.ptr = list1.ptr -> left;
        list1.len--;
    }else{
        root = list2.ptr;
        list2.ptr = list2.ptr -> left;
        list2.len--;
    }
    list list1_f, list1_s;
    list list2_f, list2_s;
    cut(list1, &list1_f, &list1_s);
    cut(list2, &list2_f, &list2_s);
    root -> left = solve(list1_f, list2_f);
    root -> right = solve(list1_s, list2_s);
    return root;
} 
Node* BuildTree(Node* list1, Node* list2){
    int len1 = list_len(list1);
    int len2 = list_len(list2);
    list list_1 = {list1, len1};
    list list_2 = {list2, len2};
    return solve(list_1, list_2); 
}
void tree_print(Node* root){
    if(root == NULL) return;
    printf("%d ", root->val);
    tree_print(root->left);
    tree_print(root->right);
}
 
int main(){

    int i, n, m, num;
    Node l1[MAXN], l2[MAXN];

    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
            scanf("%d", &num);
            l1[i].val = num;
            l1[i].left = &l1[i+1];
            l1[i].right = NULL;
    }
    l1[n-1].left = NULL;
    Node *root1 = &l1[0];
    for(i = 0; i < m; i++){
            scanf("%d", &num);
            l2[i].val = num;
            l2[i].left = &l2[i+1];
            l2[i].right = NULL;
    }
    l2[m-1].left = NULL;
    Node *root2 = &l2[0];

    Node *ans = BuildTree(root1, root2);
    tree_print(ans);
    printf("\n");

    return 0;
}