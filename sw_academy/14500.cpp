#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int n, m;
int map[502][502];
int visit[502][502];
int ans = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
//아래 위 왼쪽 오른쪽
bool check(int y, int x){
    if(y > -1 && y < n && x > -1 && x < m){
        return true;
    }
    return false;
}

void solve2(int y, int x, int sum){
    //하나만 빼고 
    //상하 좌우 중에 하나만 빼고 가자
    int ny, nx;
    for(int i = 0; i < 4;i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(check(ny,nx)){
            sum += map[ny][nx];
        }
    }

    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(check(ny,nx)){
            ans = max(ans, sum - map[ny][nx]);
        }else{
            ans = max(ans, sum);
        }
    }

}
void solve(int y, int x, int depth, int sum){
    int ny, nx;
    if(depth == 4){
        ans = max(sum, ans);
        return;
    }
    for(int i = 0; i <4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(check(ny,nx) && visit[ny][nx] == 0){
            visit[ny][nx] = 1;
            solve(ny,nx, depth+1, sum + map[ny][nx]);
            visit[ny][nx] = 0;
        }
    }
}
int main(){
    scanf("%d %d",&n, &m);

    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&map[i][j]);
        }
    }

    for(int i = 0; i< n; i++){
        for(int j= 0; j < m;j++){
            visit[i][j] = 1;
            solve(i,j,1, map[i][j]);
            solve2(i, j, map[i][j]);
            visit[i][j] = 0;

        }
    }
    printf("%d\n", ans);
}