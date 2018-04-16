#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visit[52][52];
queue<pair<int,int>> waterQ;
queue<pair<int,int>> q;
int s_y, s_x, e_y, e_x, r,c;
int ans = 0;
string s[51];

void bfs(){
    int water_size = waterQ.size();
    while(water_size--){
        int w_x= waterQ.front().first;
        int w_y= waterQ.front().second;
        waterQ.pop();

        for(int i = 0; i < 4; i++){
            int nx = w_x + dx[i];
            int ny = w_y + dy[i];

            if(0 <= ny && ny < r && 0 <= nx && nx < c && s[ny][nx] == '.'){
                waterQ.push(make_pair(nx,ny));
                s[ny][nx] = '*';
            }
        }
    }
    int que_size = q.size();
    if(!que_size){
        cout<<"KAKTUS"<<endl;
        return;
    }

    while(que_size--){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == e_x && y == e_y) {
            cout<<ans<<endl;
            return;
        }
        for(int i =0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= ny && ny < r && 0 <= nx && nx < c && (s[ny][nx]=='.'|| s[ny][nx] =='D'))
            {
                if (visit[ny][nx])
                    continue;
                q.push(make_pair(nx,ny));
                visit[ny][nx] = 1;
            }
        }
    }
    ans++;
    bfs();
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i = 0; i <r; i++){
        cin>>s[i];
        for (int j = 0; j < c; j++)
        {
            if (s[i][j] == 'D')
            {
                e_y = i;
                e_x = j;
            }
            else if (s[i][j] == 'S')
            {
                s_y = i;
                s_x = j;
                visit[i][j] = 1;
                q.push(make_pair(j, i));
            }
            else if (s[i][j] == '*')
            {
                waterQ.push(make_pair(j, i));
            }
        }
    }

    bfs();
    return 0;
}