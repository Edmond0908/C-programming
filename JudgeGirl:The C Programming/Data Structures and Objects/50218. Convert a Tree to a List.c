#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "treeToList.h"

List rootList(TreeNode *root){
    List list;
    list.head = list.tail = root;
    list.head -> right = list.tail -> right = NULL;
    return list;
}

List merge_list(List a, List b){
    if(a.head == NULL) return b;
    if(b.head == NULL) return a;
    List tmp;
    tmp.head = a.head;
    a.tail -> left = b.head;
    tmp.tail = b.tail;
    return tmp;
}
List treeToListFunc(TreeNode * root){
    if(root == NULL){ List tmp = {NULL, NULL}; return tmp;}
    List left = treeToListFunc(root -> left);
    List right = treeToListFunc(root -> right);
    if((root -> value) % 2){
        return merge_list(rootList(root), merge_list(right, left));
    }
    return merge_list(rootList(root), merge_list(left, right));
}
TreeNode *buildTree(int **values, TreeNode **roots) {
    int val;
    scanf("%d", &val);
    if(val == 0) return NULL;
    **values = val;
    TreeNode *now = *roots;
    (*values)++; (*roots)++;
    now -> value = val;
    now -> left  = buildTree(values, roots);
    now -> right = buildTree(values, roots);
    return now;
}
 
int main() {
    int size;
    scanf("%d\n", &size);
    TreeNode * root = (TreeNode*)calloc(size, sizeof(TreeNode));
 
    int valueRecord[size];
    int *vptr = valueRecord;
    TreeNode *nptr = root;
 
    root = buildTree(&vptr, &nptr);
 
    List ans = treeToListFunc(root);
 
    TreeNode * node = ans.head;
    TreeNode * firstAddr = &root[0];
    TreeNode * lastAddr = &root[size];
    for(; node != NULL; node = node -> left) {
        if (node -> right != NULL) {
            printf("Right node should be null\n");
            break;
        }
        if (firstAddr > node || lastAddr <= node) {
            printf("Memory address out of bound\n");
            break;
        }
        int counter = node - firstAddr;
        if (node -> value != valueRecord[counter]) {
            printf("You can't modify the value in the given treeNode\n");
            break;
        }
        printf("%d ", node -> value);
    }
 
     free(root);
    return 0;
}