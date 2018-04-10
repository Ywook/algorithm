#include <cstdio>
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int ans = 0;
int n, k, l;
int map[102][102];
queue<pair<int,char> > q;
deque<pair<int, int> > body;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void map_print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<map[i][j] << " ";
        }
        cout<<endl;
    }
}
int main(){

    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
        int row, col;
        scanf("%d %d", &row, &col);
        map[row-1][col-1] = 1;
    }

    scanf("%d", &l);
    for(int i = 0; i < l; i++){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        q.push(make_pair(x,c));
    }

    int d = 0;
    int head_x = 0;
    int head_y = 0;
    map[head_y][head_x] = 2;
    body.push_front(make_pair(0,0));
    while(1){
        int x = q.front().first; char c = q.front().second;
        if(x == ans){
            q.pop();
            if(c == 'L'){
                d--;
                if(d < 0) d = 3;
            }else{
                d++;
                if(d > 3) d = 0; 
            }
        }
        ans++;
        int nx = head_x + dx[d];
        int ny = head_y + dy[d];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n){ //ㄷㅏ음 경우가 벾에 부딪치는경우
            break;
        }
        if(map[ny][nx] == 2){ //몸에 부딪치는 경우
            break;
        }else if(map[ny][nx] == 1){ //사과인 경우!
            body.push_front(make_pair(ny,nx));
            map[ny][nx] = 2;
        }else{
            map[ny][nx] = 2;
            body.push_front(make_pair(ny,nx));
            int b_y = body.back().first;
            int b_x = body.back().second;
            map[b_y][b_x] = 0;
            body.pop_back();
        }
        head_x = nx;
        head_y = ny;
    }
    cout<<ans<<endl;
    return 0;
}
