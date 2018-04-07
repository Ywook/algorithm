#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int r,c;
string s[1001];

queue<pair<int,int>> fire;
queue<pair<int,int>> que;
int ans = 0;
int visit[1001][1001];
void bfs(){
    int fire_size = fire.size();
    while (fire_size--)
    {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < c && 0 <= ny && ny < r && s[ny][nx] == '.')
            {
                s[ny][nx] = 'F';
                fire.push(make_pair(nx, ny));
            }
        }
    }

    int que_size = que.size();
    ans++;
    if (que_size == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    while(que_size--){
        int x = que.front().first; int y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= c || ny < 0 || ny >= r){
                cout<<ans<<endl;
                return;
            }
            if(0 <= nx && nx < c && 0<= ny && ny < r && s[ny][nx] == '.'){
                if(visit[ny][nx] == 1){
                    continue;
                }
                que.push(make_pair(nx,ny));
                visit[ny][nx] = 1;
            }
        }
    }

    bfs();
    return;
}
int main(){
    scanf("%d %d", &r, &c);

    for(int i =0; i < r; i++){
        cin>>s[i];
        for(int j = 0; j < c; j++){
            if(s[i][j] == 'J'){
                que.push(make_pair(j,i));
                visit[j][i] = 1;
            }else if(s[i][j] == 'F'){
                fire.push(make_pair(j,i));
            }
        }
    }
    bfs();
}