#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
char map[14][7];
int visit[14][7];
int len = 0;
int bfs(int y, int x, char c){
    int ny, nx;
    queue<pair<int, int> > q;

    q.push(make_pair(y,x));
    int size = 0;
    visit[y][x] = 1;
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        size++;

        for(int i = 0; i< 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny >= 0 && ny < 12 && nx >= 0 && nx < 6){
                if(map[ny][nx] == c && !visit[ny][nx]){
                    visit[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    return size;
}

void dfs(int y, int x, char c){
    map[y][x] = '.';

    for(int i = 0; i <4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >-1 && ny<12 && nx > -1 && nx < 6){
            if(map[ny][nx] == c && visit[ny][nx]){
                dfs(ny,nx, c);
            }
        }
    }
}

int main(){
    for(int i = 0; i < 12; i++) {
        scanf("%s", map[i]);
    }

    int ans = 0;
    int flag = 0;

    while(true){
        flag = 0;
        memset(visit, 0, sizeof(visit));

        for (int i = 0; i < 12; i++)
        {
            int size = 0;
            for (int j = 0; j < 6; j++)
            {
                if (map[i][j] != '.' && !visit[i][j])
                {   
                    size = bfs(i, j, map[i][j]);
                }
                if (size > 3)
                {
                    flag++;
                    dfs(i,j, map[i][j]);
                    size =0;
                }
            }
        }
        if (flag) ans++;
        else break; 
        for(int i = 11; i > 0; i--){
            for(int j = 0; j < 6; j++){
                if(map[i][j] == '.'){
                    for(int k = i-1; k >= 0; k--){
                        if(map[k][j] != '.'){
                            swap(map[i][j], map[k][j]);
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}