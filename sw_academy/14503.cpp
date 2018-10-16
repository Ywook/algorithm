#include<cstdio>
#include<iostream>

using namespace std;

int n,m;
int map[52][52];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int r, c, d;
int ans = 0;

int check(int ny, int nx){
    if (ny < 0 && ny >= n && nx < 0 && nx >= m)
    {
        return false;
    }
    return true;
}
int main(){
    int ny, nx, by, bx;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);

    int stack;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
        }
    }

    while(true){
        stack = 0;
        map[r][c] = 2;
        ny = r + dy[(d + 3) % 4];
        nx = c + dx[(d + 3) % 4];

        by = r - dy[d];
        bx = c - dx[d];

        for(int i = 0; i < 4; i++){
            int tny = r + dy[i];
            int tnx = c + dx[i];

            if(!check(tny, tnx)){
                stack++;
                continue;
            }
            
            if(map[tny][tnx] != 0) stack++;
        }

        if(stack == 4){
            if(!check(by, bx) || map[by][bx] == 1) break;
            else{
                r = by;
                c = bx;
                continue;
            }
        }
        d = (d+3)%4;
        if(check(ny, nx) && map[ny][nx]==0){
            r = ny;
            c = nx;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=m;j++){
            if(map[i][j] == 2) ans++;
        }
    }
    printf("%d\n", ans);
}