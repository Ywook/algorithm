#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[102][102];
int d[102][102];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%1d", &map[i][j]);
            d[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;

    q.push(make_pair(1,1));
    d[1][1] = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx > 0 && nx <= n && ny > 0 && ny <=m){
                if(d[ny][nx] == -1){
                    if(map[ny][nx] == 0){
                        d[ny][nx] = d[y][x];
                        q.push(make_pair(ny,nx));
                    }else{
                        d[ny][nx] = 1 + d[y][x];
                        q2.push(make_pair(ny,nx));
                    }
                }
            }
        }
        if(q.empty()){
            q = q2;
            q2 = queue<pair<int, int>>();
        }

    }
    printf("%d\n", d[m][n]);
    return 0;
}