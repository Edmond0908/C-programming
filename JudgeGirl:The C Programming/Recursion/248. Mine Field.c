#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool ingrid(int x, int y){
    return (x >= 0 && x < 9 && y >= 0 && y < 9);
}
void solve(int index, int dx[8], int dy[8], int have_to_clear, int g[9][9], int ans[9][9]){
    // end the recursio here
    if(have_to_clear == 0){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                printf("%d%c", ans[i][j], " \n"[j == 8]);
            }
        }
        exit(0);
    }

    if(index == -1) return;
    int x = index / 9;
    int y = index % 9;
    // the place that will never be changed hasn't been cleared then this isn't the solution
    if(x < 7){
        for(int i = 0;i < 9;i++){
            if(g[x - 2][i]) return;
        }
    }
    // check if the neibors have 0's
    int check = 1;
    for(int i = 0;i < 8;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(ingrid(xx, yy) && g[xx][yy] == 0) {
            check = 0;
            break;
        }
    }
    // put 1 first 
    if(g[x][y] && check){
        int changed_grid[8][2];
        int number_of_grid_being_changed = 0;
        g[x][y] --;
        ans[x][y] = 1;
        for(int i = 0;i < 8;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(!ingrid(xx, yy)) continue;
            g[xx][yy]--;
            changed_grid[number_of_grid_being_changed][0] = xx;
            changed_grid[number_of_grid_being_changed][1] = yy;
            number_of_grid_being_changed++;
        }
        solve(index - 1, dx, dy, have_to_clear - 1 - number_of_grid_being_changed, g, ans);
        // initialize to the previous state
        g[x][y] ++;
        for(int i = 0;i < number_of_grid_being_changed;i++){
            int xx = changed_grid[i][0];
            int yy = changed_grid[i][1];
            g[xx][yy] ++;
        }
    }
    // put 0
    ans[x][y] = 0;
    solve(index - 1, dx, dy, have_to_clear, g, ans);
}

int main(){

    int g[9][9];
    int ans[9][9];
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int have_to_clear = 0;
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            scanf("%d", &g[i][j]);
            have_to_clear += g[i][j];
        }
    }
    solve(80, dx, dy, have_to_clear, g, ans);

    return 0;
}