#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int ans[2];
int n;

int visit[102];

int a[12][12];
int map[12][12];

int dy[4] = {1,1, -1, -1};
int dx[4] = {-1, 1, -1, 1};

int check(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        int next = ny * n + nx;

        while(ny > 0 && ny <= n && nx > 0 && nx <=n){
            if(visit[next]){
                return 0;
            }
            ny += dy[i];
            nx += dx[i];
            next = ny * n + nx;
        }
    }
    return 1;
}

void dfs(int depth, int cnt, int color){
    ans[color] = max(ans[color], cnt);
    for(int i = depth; i < n*n; i++){
        int y = i / n;
        int x = i % n;
        
        if(map[y][x]!= color) continue;

        if(a[y][x] == 1){
            if(check(y,x)){
                visit[i] = 1;
                dfs(i+1, cnt+1, color);
            }
        }
        
    }
    visit[depth] = 0;
}

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i< n; i++){
        for(int j = 0; j<n;j++){
            scanf("%d", &a[i][j]);
            if(i%2 == 0){
                if(j%2 == 0){
                    map[i][j] = 1;
                }
            }else{
                if(j%2 != 0){
                    map[i][j] = 1;
                }
            }
        }
    }
    dfs(1, 0, 1);
    dfs(1,0, 0);
    printf("%d\n", ans[0] + ans[1]);

}