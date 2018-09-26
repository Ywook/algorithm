#include<iostream>
#include<cstdio>

using namespace std;
int r, c;

int map[102][102];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int cheese(){
    int cnt = 0;
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c;j++){
            if(map[i][j] == 1) cnt++;
            else map[i][j] = 0;
        }
    }
    return cnt;
}

void dfs(int y, int x){
    int ny, nx;
    map[y][x] = -1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny > 0 && ny <= r && nx > 0 && nx <= c){
            if(map[ny][nx] > 0) map[ny][nx] = -1;
            else if(map[ny][nx] == 0) dfs(ny,nx);
        }
    }
}

int main(){
    scanf("%d %d",&r, &c);

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            scanf("%d", &map[i][j]);
        }
    }
    int ans = 0;
    int cheese_cnt;
    int prev=1;
    while((cheese_cnt = cheese())){
        dfs(1, 1);
        ans++;
        prev = cheese_cnt;
    }
    printf("%d\n", ans);
    printf("%d\n", prev);
    return 0;
}