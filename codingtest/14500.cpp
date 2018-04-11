#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n,m;
int map[502][502];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int visit[502][502];

int temp;
int ans = 0;

void dfs(int y, int x, int depth){
    if(depth == 4){

        ans = max(ans, temp);
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visit[ny][nx] == 1) continue;

        temp += map[ny][nx];
        visit[ny][nx] = 1;
        dfs(ny,nx, depth + 1);
        temp -= map[ny][nx];
        visit[ny][nx] = 0;
    }
}

int bfs(int y, int x){
    int sum = map[y][x];
    int res = 0;

    for(int i = 0; i < 4; i++){
        int ny = y +dy[i];
        int nx = x +dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m )
            continue;
        sum += map[ny][nx];
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        int temp;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m){
            temp = sum;
        }else{
            temp = sum - map[ny][nx];
        }
        res = max(temp, res);
    }
    return res;  
}
int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp = map[i][j];
            visit[i][j] = 1;
            dfs(i,j, 1);
            visit[i][j] = 0;
            ans = max(ans, bfs(i,j));
        }
    }
    cout<<ans<<endl;
}