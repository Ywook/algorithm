#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int a[104][104];
int d[104][104];
int check[104][104];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
queue<pair<int,int>> q;

void dfs(int x, int y, int cnt){
    q.push(make_pair(x,y));
    check[x][y] = 1;
    a[x][y] = cnt;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx <n && 0 <= ny && ny < n && a[nx][ny] == 1 && check[nx][ny] == 0){
            dfs(nx,ny,cnt);
        }
    }
}

int main(void){
    int t;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0) d[i][j]= -1;
        }
    } 
    int cnt = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            if(check[i][j] == 0 && a[i][j]==1){
                dfs(i,j,cnt++);
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
        
            if(0 <= nx && nx < n && 0 <= ny && ny < n && check[nx][ny] == 0){
                check[nx][ny] = 1;
                a[nx][ny] = a[x][y];
                d[nx][ny] = d[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    int ans = 30000;
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j <n ; j++){
            for(int k = 0; k < 4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];

                if(0<= nx && nx < n && 0 <= ny && ny < n){
                    if(a[i][j] != a[nx][ny]){
                        ans = min(ans,d[i][j]+d[nx][ny]);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}