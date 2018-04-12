#include <iostream>
#include <cstdio>

using namespace std;
int n,m, r, c, d;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int map[51][51];
int ans = 0;
void print()
{
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
        }
    }

    
    while(true){
        int stack = 0;
        map[r][c] = 2;

        int nx = c + dx[(d+3)%4];
        int ny = r + dy[(d+3)%4];
        
        int bx = c - dx[d];
        int by = r - dy[d];

        for(int i = 0; i < 4; i++){
            int tnx= c + dx[i];
            int tny= r + dy[i];

            if(tnx >= m || tnx < 0 || tny >= n || tny < 0){
                stack++;
                continue;
            }
            if(map[tny][tnx] != 0) stack++;
        }

        if(stack == 4){
            if(map[by][bx] == 1){
                break;
            }else{
                r = by;
                c = bx;
                continue;
            }
        }
        d = (d + 3) % 4;

        if (nx >= m || nx < 0 || ny >= n || ny < 0 || map[ny][nx] != 0){
            continue;
        }
        c = nx;
        r = ny;

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 2) ans++;
        }
    }
    cout << ans << endl;
}
