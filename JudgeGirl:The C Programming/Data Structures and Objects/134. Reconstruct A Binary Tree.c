#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right; 
}node;

node* make_node(int key, node* left, node* right){
    node* tmp = (node*)malloc(sizeof(node));
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
    if(cur == NULL) return NULL;
    if(cur -> key == n1 || cur -> key == n2){
        return cur;
    }
    node* left_lca = lca(cur -> left, n1, n2);
    node* right_lca = lca(cur -> right, n1, n2);
    if(left_lca && right_lca) return cur;
    if(left_lca) return left_lca;
    return right_lca;
}
void dfs(node* cur, int par, int height[1005]){
    if(cur == NULL) return;
    int u = cur -> key;
    height[u] = height[par] + 1;
    dfs(cur -> left, u, height);
    dfs(cur -> right, u, height);
}
void print(node* cur){
    if(cur == NULL) return;
    printf("%d\n", cur -> key);
    print(cur -> left);
    print(cur -> right);
}

int main(){

    node* root = 0;
    int n, m;
    scanf("%d", &n);
    int data[1005][2];
    int height[1005] = {0};
    int index[1005] = {0};

    for(int i = 0;i < n;i++){
        scanf("%d%d", &data[i][0], &data[i][1]);
    }


    //dicrete the data
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - 1 - i;j++){
            if(data[j][0] > data[j+1][0]){
                int tmp[2];
                tmp[0] = data[j][0];
                tmp[1] = data[j][1];
                data[j][0] = data[j+1][0];
                data[j][1] = data[j+1][1];
                data[j+1][0] = tmp[0];
                data[j+1][1] = tmp[1];
            }
        }
    }
    for(int i = 0;i < n;i++){
        index[i] = data[i][0];
        data[i][0] = i;
    }

    //sorting
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - 1 - i;j++){
            if(data[j][1] > data[j+1][1]){
                int tmp[2];
                tmp[0] = data[j][0];
                tmp[1] = data[j][1];
                data[j][0] = data[j+1][0];
                data[j][1] = data[j+1][1];
                data[j+1][0] = tmp[0];
                data[j+1][1] = tmp[1];
            }
        }
    }

    //discrete the data
    for(int i = 0;i < n;i++){
        root = insert(root, data[i][0]);
    }
    
    height[0] = 0;
    dfs(root, 0, height);

    scanf("%d", &m);
    for(int i = 0;i < m;i++){
        int k1, k2;
        int n1, n2;
        scanf("%d%d", &k1, &k2);
        for(int i = 0;i < n;i++){
            if(index[i] == k1) n1 = i;
            if(index[i] == k2) n2 = i;
        }
        node* LCA = lca(root, n1, n2);
        int u = LCA -> key;
        printf("%d\n", height[n1] + height[n2] - 2 * height[u]);
    }
    
    return 0;
}