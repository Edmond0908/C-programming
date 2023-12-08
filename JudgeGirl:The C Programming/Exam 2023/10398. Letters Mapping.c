#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
void solve(int key, int ans[26], int used_num[10], int have[26], int cur_used, int alpha_order[9]){
    if(cur_used == 9){
        int tmp = 0;
        for(int i = 0;i < 9;i++){
            tmp += (ans[alpha_order[i]] * have[alpha_order[i]]);
        }
        if(tmp == key){
            for(int i = 1;i <= 9;i++){
                for(int j = 0;j < 9;j++){
                    if(ans[alpha_order[j]] == i){
                        printf("%c ", ('a'+alpha_order[j]));
                    }
                }
            }
            exit(0);
        }
        return;
    }
    for(int i = 0;i < 9;i++){
        if(used_num[i]) continue;
        used_num[i] = 1;
        ans[alpha_order[i]] = cur_used + 1;
        solve(key, ans, used_num, have, cur_used + 1, alpha_order);
        used_num[i] = 0;
    }
}
 
int main(){
 
    int k;
    scanf("%d", &k);
    int have[26] = {0};
    int alpha[9] = {0};
    char input[105];
 
    while(scanf("%s", input) != EOF){
        int len = strlen(input);
        for(int i = 0;i < len;i++){
            have[(int)(input[i] - 'a')] += 1;
        }
    }
 
    int used_num[10] = {0};
    int ans[26] = {0};
 
    int own = 0;
    for(int i = 0;i < 26;i++) {
        if(have[i]){
            alpha[own] = i;
            own++;
        }
    }
    assert(own == 9);
    solve(k, ans, used_num, have, 0, alpha);
 
    return 0;
}