#include<iostream>
#include<queue>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char map[1002][1001];

int check_f[1002][1002];
int check_p[1002][1002];
int w, h;
queue<pair<int, int> > q, pq;

int main(){
    int test, ok;
    cin>>test;
    while(test--){
        cin>>w>>h;
        int y, x, ans;
        ans = 0;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                check_f[i][j] = 0;
                check_p[i][j] = 0;
                cin>>map[i][j];
                if(map[i][j] == '*'){
                    check_f[i][j] = 1;
                    q.push(make_pair(i,j));
                }else if(map[i][j] == '@'){
                    pq.push(make_pair(i,j));
                    check_p[i][j] = 1;
                }
            }
        }
        ok = 0;
        while(1){
            int q_size = q.size();
            while(q_size){
                int f_y = q.front().first;
                int f_x = q.front().second;
                q.pop();
                q_size--;
                for(int i = 0; i < 4; i++){
                    int f_ny = f_y + dy[i];
                    int f_nx = f_x + dx[i];

                    if(f_ny > 0 && f_ny <= h && f_nx > 0 && f_nx <= w){
                        if(map[f_ny][f_nx] != '#' && check_f[f_ny][f_nx] == 0){
                            check_f[f_ny][f_nx] = 1;
                            map[f_ny][f_nx] = '*';
                            q.push(make_pair(f_ny, f_nx));
                        }
                    }
                }
            }

            int pq_size = pq.size();
            while(pq_size){
                int y = pq.front().first;
                int x = pq.front().second;
                pq.pop();
                pq_size--;

                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(ny > 0 && ny <= h && nx > 0 && nx <= w){
                        if(map[ny][nx] == '.' && check_p[ny][nx] == 0){
                            check_p[ny][nx] = 1;
                            pq.push(make_pair(ny,nx));
                        }
                    }else{
                        ok = 1;
                        break;
                    }
                }
            }
            ans++;
            if(pq.empty() || ok) break;
        }
        if(ok){
            cout<<ans<<endl;
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
        while(!q.empty()){
            q.pop();
        }
        while(!pq.empty()){
            pq.pop();
        }
    }
}