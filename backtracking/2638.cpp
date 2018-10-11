#include<iostream>
#include<cstdio>

using namespace std;
int r, c;
int map[102][102];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int cheese_cnt(){
    int cnt = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if(map[i][j] == 1 || map[i][j] == 2){
                cnt++;
                map[i][j] = 1;
            }else{
                map[i][j] = 0;
            }
        }
    }
    return cnt;
}

void dfs(int y, int x){
    map[y][x] = -1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx > 0 && nx <= c && ny > 0 && ny <= r){
            if(map[ny][nx] == 2){ map[ny][nx] = -2;
            }else if(map[ny][nx] == 1) map[ny][nx]++;
            else if(map[ny][nx] == 0) dfs(ny,nx);
            
        }
    }
}
int main(){
    scanf("%d %d", &r, &c);

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            scanf("%d", &map[i][j]);
        }
    }
    int ans = 0;
    while(cheese_cnt()){
        dfs(1, 1);
        ans++;
    }
    cout<<ans<<endl;
}