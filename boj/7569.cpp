#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;
int m, n, h, flag;

int dh[2] = {-1, 1};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a[102][102][102];
int visit[102][102][102];
queue<pair<int, pair<int, int> > > q, q2;
int main(){
    scanf("%d %d %d", &m, &n, &h);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                scanf("%d", &a[i][j][k]);
                if(a[i][j][k] == 1){
                    q.push(make_pair(i, make_pair(j, k)));
                    visit[i][j][k] = 1;
                }
            }
        }
    }
    int ans = -1;
    int q_size = q.size();
    while(q_size > 0){
        while (!q.empty())
        {
            int height = q.front().first;
            int y = q.front().second.first;
            int x = q.front().second.second;
            q.pop();
            a[height][y][x] = 1;

            for (int i = 0; i < 2; i++)
            {
                int nh = height + dh[i];
                if(nh >= 0 && nh < h){
                    if(a[nh][y][x] == 0 && visit[nh][y][x] == 0){
                        visit[nh][y][x] = 1;
                        q2.push(make_pair(nh, make_pair(y, x)));
                    }
                }
            }

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                    if(a[height][ny][nx] == 0 && visit[height][ny][nx] == 0){
                        visit[height][ny][nx] = 1;
                        q2.push(make_pair(height, make_pair(ny,nx)));
                    }
                }
            }
        }
        q_size = q2.size();
        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
        ans++;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if(a[i][j][k] == 0){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) break;
    }

    if(flag) cout<<-1<<endl;
    else cout<<ans<<endl;
}