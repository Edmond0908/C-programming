#include <stdio.h>
#include <stdbool.h>

bool ingrid(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
void solve(int x, int y, int n, int m, int g[17][17], 
            int *ans, int cur_ans, int dx[8], int dy[8]){
    
    int available = 0;
    x += (y)/m;
    y %= m;
    for(int i = x;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i == x && j < y) continue;
            available += (g[i][j] == 0);
        }
    }
    if(*ans < cur_ans) *ans = cur_ans;
    if(available + cur_ans <= *ans) return;

    // stop the recursion here
    if(x == n || available <= 0){
        if(*ans < cur_ans) *ans = cur_ans;
        return;
    }
    // if the current place is not legal to put a knight on, then just go to the next one
    if(g[x][y]){
        solve(x, y + 1, n, m, g, ans, cur_ans, dx, dy);
        return;
    }
    // don't put and go
    solve(x, y + 1, n, m, g, ans, cur_ans, dx, dy);

    // put and go
    int new_places_being_attackted[8][2];
    int places = 0;
    g[x][y] = 1;
    for(int i = 0;i < 8;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(!ingrid(xx, yy, n, m) || g[xx][yy]) continue;
        g[xx][yy] = 1;
        new_places_being_attackted[places][0] = xx;
        new_places_being_attackted[places][1] = yy;
        places++;
    }
    solve(x, y + 1, n, m, g, ans, cur_ans + 1, dx, dy);
    // initialize to the previous state
    g[x][y] = 0;
    for(int i = 0;i < places;i++){
        int xx = new_places_being_attackted[i][0];
        int yy = new_places_being_attackted[i][1];
        g[xx][yy] = 0;
    }
}

int main(){

    int n, m, x, y;
    int g[17][17];
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    scanf("%d%d", &n, &m);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            g[i][j] = 0;
        }
    }
    while(scanf("%d%d", &x, &y) != EOF){
        g[x][y] = 1;
    }
    int ans = 0;
    solve(0, 0, n, m, g, &ans, 0, dx, dy);
    printf("%d", ans);

    return 0;
}