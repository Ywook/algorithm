#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n, l, r;
int arr[52][52];
int visit[52][52];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ans = 0;
queue<pair<int, int> > q1, q2;
void bfs(int y, int x){
    int sum = 0;
    int num = 0;
    q1.push(make_pair(y, x));
    q2.push(make_pair(y, x));

    while(!q1.empty()){
        int y = q1.front().first;
        int x = q1.front().second;
        q1.pop();
        sum += arr[y][x];
        visit[y][x] = 0;

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n)
            { 
                int temp = abs(arr[ny][nx] - arr[y][x]);
                if(visit[ny][nx] && temp >= l && temp<=r){
                    q1.push(make_pair(ny,nx));
                    q2.push(make_pair(ny, nx));
                    visit[ny][nx] = 0;
                }
            }
        }
    }
    num = sum / q2.size();

    while(!q2.empty()){
        int y = q2.front().first;
        int x = q2.front().second;
        q2.pop();
        arr[y][x] = num;
    }
    return;
}

int check(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0 ; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                    int temp = abs(arr[ny][nx] - arr[i][j]);

                    if(temp >= l && temp <= r){
                        cnt++;
                        visit[i][j] = visit[ny][nx] = 1;
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    scanf("%d %d %d", &n, &l, &r);
    int flag  = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int cnt = 0;
    while((cnt = check())){
        flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visit[i][j]){
                    if(!flag){
                        flag = 1;
                        ans++;
                    }
                    bfs(i, j);
                }
            }
        }
    }
    printf("%d\n", ans);
}