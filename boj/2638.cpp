#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;

int map[103][103];
int ans = 0;
int ch_cnt = 0;

int solve(){
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(map[i][j] == 1 || map[i][j] == 2){
                map[i][j] = 1;
                cnt++;
            }else map[i][j] = 0;
        }
    }
    return cnt;
}

void dfs(int y, int x){
    map[y][x] = -1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > 0 && ny <= n && nx > 0 && nx <=m){
            if(map[ny][nx] >= 1) map[ny][nx]++;
            else if(map[ny][nx] == 0) dfs(ny,nx);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) ch_cnt++;
        }
    }

    while(solve()){
        ans++;
        dfs(1,1);
    }
    cout<<ans<<endl;
    return 0;
}