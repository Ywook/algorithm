#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>

using namespace std;
int n, m;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int visit[1002][1002][2];
int map[1002][1002];
vector<pair<int, int> > v;

int bfs(){
    int ans = -1;
    queue<pair<pair<int,int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0,1), make_pair(1,1)));
    // visit[1][1][1] = 1; //1은 벽을 부 순 경우
    visit[1][1][0] = 1; //0은 벽을 안부순 경우

    while(!q.empty()){
        int stat = q.front().first.first;
        int cnt = q.front().first.second;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if(y == n && x == m){
            if(ans == -1) ans = cnt;
            else ans = min(ans, cnt);
        }
        // cout<<y <<"  "<< x <<endl;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny > 0 && ny <= n && nx > 0 && nx <= m)
            {
                if(stat == 0){
                    if(!map[ny][nx] && !visit[ny][nx][0]){
                        q.push(make_pair(make_pair(0,cnt+1),make_pair(ny,nx)));
                        visit[ny][nx][0] = 1;
                    }else if(map[ny][nx]){
                        q.push(make_pair(make_pair(1, cnt+1), make_pair(ny,nx)));
                        visit[ny][nx][1] = 1;
                    }
                }else{
                    if(!map[ny][nx] && !visit[ny][nx][1]){
                        q.push(make_pair(make_pair(1, cnt+1), make_pair(ny,nx)));
                        visit[ny][nx][1] = 1;
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &map[i][j]);
            if(map[i][j] == 1){
                v.push_back(make_pair(i,j));
            }
        }
    }
    printf("%d\n", bfs());
}
