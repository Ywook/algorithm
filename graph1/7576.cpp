#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
int check[1004][1004];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(void){
    int m, n, t, ans;
    queue<pair<int, int>> q, q2;
    scanf("%d %d", &m, &n);

    for(int i = 0; i < n; i++){
        v.push_back(vector<int>());
        for(int j = 0 ; j < m ; j++){
            scanf("%d", &t);
            v[i].push_back(t);
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }
    int x, y, q_x, q_y;
    ans = 0;
    while(!q.empty()){
        while(!q.empty()){
            x = q.front().first; y = q.front().second; q.pop();
            for(int i = 0 ; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && v[nx][ny] == 0){
                    v[nx][ny] = 1;
                    q2.push(make_pair(nx, ny));
                }
            }
        }
        while(!q2.empty()){
            q_x = q2.front().first; q_y = q2.front().second; q2.pop();
            q.push(make_pair(q_x,q_y));
        }
        ans++;
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j]==0) {
                cout<<"-1"<<endl;
                return 0;
            } 
        }
    }
    cout<<(ans-1)<<endl;
}