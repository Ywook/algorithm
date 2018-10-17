#include<iostream>
#include<cstdio>

using namespace std;

int n, m, h;
int map[51][51];
int ans= -1;

int cal(int start){
    int y = 1;
    int x = start;
    while(y <= h){
        if(map[y][x-1]){
            x--;
        }else if(map[y][x]){
            x++;
        }
        y++;
    }
    return (x == start) ? 1 : 0;
}
int solve(){
    for(int i = 1; i <= n; i++){
        if(!cal(i)) return 0;
    }
    return 1;
}
void dfs(int y, int x, int depth){
    if(solve()){
        if(ans != -1) ans = min(depth, ans);
        else ans = depth;
        return;
    }
    if (depth >= 3)
    {
        return;
    }

    for(int i = y; i <= h; i++){
        for(int j = 1; j <= n; j++){
            if(!map[i][j] && !map[i][j-1] && !map[i][j+1]){
                map[i][j] = 1;
                dfs(i, 1, depth+1);
                map[i][j] = 0;
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &h);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    dfs(1, 1, 0);
    printf("%d\n",ans);
    //하나 추가할 경우, 두개 추가할경우, 3개추가할경우
}