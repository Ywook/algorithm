#include <iostream>
#include <cstdio>
#include <queue>

#define min(x,y) ((x) > (y)) ? (y):(x) 
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a[104][104];
int d[104][104];
int main(void){
    int n, m;
    queue<pair<int, int>> q;
        scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    q.push(make_pair(0, 0));
    d[0][0] = 1;
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int mx = nx + dx[i];
            int my = ny + dy[i];

            if(0 <= mx && mx < n && 0 <= ny && ny < m){
                if(a[mx][my] == 1 && d[mx][my] == 0){
                    d[mx][my] = d[nx][ny] + 1;
                    q.push(make_pair(mx, my));
                }
            }
        }
    }
    cout<<d[n-1][m-1]<<endl;
}
