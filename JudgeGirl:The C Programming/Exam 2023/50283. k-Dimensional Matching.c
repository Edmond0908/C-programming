#include <stdio.h>
#define MAXN 100
#define MAXK 100
#define MAX_Path 50

void dfs(int u, int k, int* cur_num_of_path, int cur_node, int visit[MAXN],
        int g[MAXN][MAXN], int own[MAXN], int path[MAXK][MAX_Path], int path_tmp[MAX_Path]){

    visit[u] = 1;
    path_tmp[cur_node] = u;
    if(cur_node == k - 1){
        for(int i = 0;i < k;i++){
            path[*cur_num_of_path][i] = path_tmp[i];
        }
        *cur_num_of_path = *cur_num_of_path + 1;
    }
    for(int i = 0;i < own[u];i++){
        if(visit[g[u][i]]) continue;
        dfs(g[u][i], k, cur_num_of_path, cur_node, visit, g, own, path, path_tmp);
    }
    visit[u] = 0;
}

int main(){
    int k, n, edges;
    int g[MAXN][MAXN];
    int own[MAXN];
    int visit[MAXN];
    scanf("%d %d %d", &k, &n, &edges);
    for(int i = 0;i < n;i++){
        own[i] = 0;
        visit[i] = 0;
        for(int j = 0;j < n;j++){
            g[i][j] = 0;
        }
    }
    for(int i = 0;i < edges;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][own[u]++] = v;
    }
    int ans_p[MAXK][MAX_Path];
    int ans = 0;
    int number_of_path = 0;
    for(int i = 0;i < n / k;i++){
        int path[MAXK][MAX_Path];
        int path_tmp[MAX_Path];
        dfs(i, k, &number_of_path, 0, visit, g, own,path, path_tmp);
    }
}