#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;
int n, k;
int dx[3] = {2, -1, 1};
int ans;
bool visit[100002];
void bfs(){
    if(n == k){
        ans = 0;
        return;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));

    while(!q.empty()){
        int x = q.front().first;
        int sec = q.front().second;
        q.pop();

        if(x == k){
            ans = sec;
            return;
        }
        for(int i = 0; i < 3; i++){
            int nx;
            if(i == 0) nx = x * dx[i];
            else nx = x + dx[i];

            if(nx >= 0 && nx <= 100000){
                if(!visit[nx]){
                    visit[nx] = true;
                    
                    if(i == 0 )q.push(make_pair(nx, sec));
                    else q.push(make_pair(nx, sec+1));
                }
            }

        }



    }
}

int main(){
    scanf("%d %d", &n, &k);
    bfs();
    printf("%d\n", ans);

}