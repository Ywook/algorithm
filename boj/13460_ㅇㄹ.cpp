#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;
int n,m;
string arr[11];

queue<pair<int,int> > red_q;
queue<pair<int,int> > blue_q;
//위로 갈 경우는 -1,0;
int visit[11][11][11][11];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = 0;
int r_flag;
void bfs(){
    visit[red_q.front().first][red_q.front().second][blue_q.front().first][blue_q.front().second] = 1;
    while(!red_q.empty()){
        int q_size = red_q.size();

        while(q_size--){
            int x = red_q.front().second; 
            int y = red_q.front().first;
            red_q.pop();

            int b_x = blue_q.front().second;
            int b_y = blue_q.front().first;
            blue_q.pop();
            if(arr[y][x] == 'O') {
                return;
            }
            for(int i = 0; i < 4; i++){
                int n_x, n_y, nb_x, nb_y;
                n_x = x;
                n_y = y;
                nb_x = b_x;
                nb_y = b_y;

                while (arr[n_y + dy[i]][n_x + dx[i]] != '#' && arr[n_y][n_x] != 'O')
                {
                    n_y += dy[i];
                    n_x += dx[i];
                }

                while (arr[nb_y + dy[i]][nb_x + dx[i]] != '#' && arr[nb_y][nb_x]!= 'O')
                {
                    nb_y += dy[i];
                    nb_x += dx[i];
                }

                if((n_x == nb_x) && (n_y == nb_y)){
                    if(arr[n_y][n_x] == 'O'){
                        continue;
                    }
                    if (abs(n_x - x) + abs(n_y - y) > abs(nb_x - b_x) + abs(nb_y - b_y))
                    {

                        n_x -= dx[i];
                        n_y -= dy[i];
                    }else{
                        nb_x -= dx[i];
                        nb_y -= dy[i];
                    }
                }

                if(visit[n_y][n_x][nb_y][nb_x]) continue;
                visit[n_y][n_x][nb_y][nb_x] = 1;
                red_q.push(make_pair(n_y, n_x));
                blue_q.push(make_pair(nb_y, nb_x));
            }
        }
        ans++;
        if(ans > 10){
            ans = -1; 
            return;
        }
    }
    ans = -1;
}
int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'R') red_q.push(make_pair(i,j));
            if(arr[i][j] == 'B') blue_q.push(make_pair(i,j));
        }
    }
    bfs();
    cout<<ans<<endl;
}