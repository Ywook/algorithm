#include <iostream>
#include <cstdio>

using namespace std;

int a[502][502];
int dp[502][502];
int dx[4] = {0,0, -1, 1};
int dy[4] = {-1,1, 0, 0};
int n;
int ans = 0;


void dfs(int x, int y){
    int value = 0;
    for(int i = 0; i < 4; i++){
        int nx = dx[i]+ x;
        int ny = dy[i] + y;

        if(0 < nx && nx <= n && 0 < ny && ny <= n){
            if(a[ny][nx] < a[y][x]){
                if (dp[ny][nx] == 0)
                {
                    dfs(nx, ny);
                }

                if(dp[ny][nx] > value){
                    value = dp[ny][nx];
                }
            }
        }
    }
    dp[y][x] = value + 1;
    ans = max(ans, dp[y][x]);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=n; j++){
            if(dp[i][j] == 0){
                dfs(j,i);
            }
        }
    }
    cout<<ans<<endl;
}