#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int k, w, h;

int dx[12] = {-1, 1, 0, 0, 2, 2, -2, -2, 1, 1, -1, -1};
int dy[12] = {0, 0, -1, 1, 1, -1, 1, -2, 2, -2, 2, -2};
int map[202][202];
int visit[202][202][32];
int bfs(int y, int x){
    int ny, nx, i, cnt, h_cnt;
    queue<pair<pair<int, int>, pair<int,int> > > q;
    visit[y][x][0] = 1;
    q.push(make_pair(make_pair(0, 0), make_pair(y,x)));

    while(!q.empty()){
        cnt = q.front().first.first;
        h_cnt = q.front().first.second;
        y = q.front().second.first;
        x = q.front().second.second;
        q.pop();

        if(y == h-1 && x == w-1){
            return cnt;
        }
        for(i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];

            if(nx >= 0 && nx < w && ny >= 0 && ny < h && map[ny][nx] == 0){
                if(!visit[ny][nx][h_cnt]){
                    visit[ny][nx][h_cnt] = 1;
                    q.push(make_pair(make_pair(cnt + 1, h_cnt), make_pair(ny, nx)));
                }
            }
        }
        if(h_cnt < k){
            for(i = 4; i < 12; i++){
                ny = y + dy[i];
                nx = x + dx[i];

                if (nx >= 0 && nx < w && ny >= 0 && ny < h && map[ny][nx] == 0)
                {
                    if (!visit[ny][nx][h_cnt + 1])
                    {
                        visit[ny][nx][h_cnt + 1] = 1;
                        q.push(make_pair(make_pair(cnt + 1, h_cnt + 1), make_pair(ny, nx)));
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d %d %d", &k, &w, &h);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            // scanf("%d", &map[i][j]);
            cin>>map[i][j];
       }
    }
    printf("%d\n",bfs(0, 0));
    //0,0 에서 -> w-1, h-1 까지 도착하는 최소 값;

}