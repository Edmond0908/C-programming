#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_path(int n, int path[]){
    for(int i = 0;i < n;i++) printf("%d ", path[i]);
    printf("\n");
}
void print(struct node *root, int cur, int path[]){
    path[cur] = root -> data;
    int ck = 1;
    if(root -> left){
        print(root -> left, cur + 1, path);
        ck = 0;
    }
    if(root -> right){
        print(root -> right, cur + 1, path);
        ck = 0;
    }
    if(ck) print_path(cur + 1, path);
}
void print_all_paths(struct node *root){
    int path[1001];
    print(root, 0, path);
}

struct node *insert_bs_tree(struct node *root, int data){
    struct node *current;
    if (root == NULL){
        current = (struct node *)malloc(sizeof(struct node));
        assert(current != NULL);
        current->data = data;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
 
    if (data < root->data)
        root->left = insert_bs_tree(root->left, data);
    else
        root->right = insert_bs_tree(root->right, data);
    return root;
}

 
int main(void){
    int n;
    struct node *root = NULL;
 
    while (scanf("%d", &n) != EOF)
        root = insert_bs_tree(root, n);
 
    print_all_paths(root);
}