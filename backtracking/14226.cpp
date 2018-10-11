#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;
int s;
int visit[1002];
int ans = 100000;
int board = -1;
void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(1,0));
    visit[1] = 1;
    int next_n;
    while(!q.empty()){
        int n = q.front().first;
        int sec = q.front().second;
        q.pop();

        if(n == s){
            ans = min(ans,sec);
        }
        for(int i = 0; i < 2; i++){
            if(i == 1) next_n = n*2;
            else next_n = n-1;

            if(next_n > 0 && next_n < 2*s){
                if(!visit[next_n]){
                    visit[next_n] = 1;
                    if(i == 1) q.push(make_pair(next_n, sec+2));
                    else q.push(make_pair(next_n, sec+1));
                }
            }
        }

    }
}
int main(){
    scanf("%d", &s);

    bfs();
    printf("%d\n", ans);
}