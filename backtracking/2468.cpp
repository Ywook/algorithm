#include<iostream>
#include<cstdio>

using namespace std;

int n, rain_max;
int map[102][102];
int visit[102][102];
int ans;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void dfs(int y, int x, int height){
    for(int i = 0; i < 4 ;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx > -1 && nx <n && ny > -1 && ny < n){
            if(map[ny][nx] > height){
                if (!visit[ny][nx])
                {
                    visit[ny][nx] = 1;
                    dfs(ny,nx, height);
                }
            }
        }
    }
}
void solve(int y){
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] > y && !visit[i][j]){ 
                visit[i][j] = 1;
                dfs(i, j, y);
                num++;
            }
        }
    }
    ans = max(ans, num);
}
int main(){
    scanf("%d", &n);

    for(int i = 0; i < n ; i ++){
        for(int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
            rain_max = max(rain_max, map[i][j]);
        }
    }   

    for(int i = 0; i <= rain_max; i++){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visit[i][j] = 0;
            }
        }

        solve(i);
    }
    printf("%d\n", ans);
}