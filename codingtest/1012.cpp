#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int g[51][51];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int m, n, k;

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    g[y][x] = 0;
    while(!q.empty()){
        int x1 = q.front().first; int y1 = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {   
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            
            if(nx >= 0 && nx <m && ny >= 0 && ny < n){
                if(g[ny][nx] == 1){
                    q.push(make_pair(nx,ny));
                    g[ny][nx] = 0;
                }
            }
        }
    }
}
int main(){
    int t, ans, tx, ty;
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d %d %d", &m,&n,&k);

        for(int i = 0 ; i < k; i++){
            scanf("%d %d", &tx, &ty);
            g[ty][tx] = 1; 
        }

        for(int i = 0; i < n ;i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 1){
                    bfs(j,i);
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        
    }
    return 0;
}