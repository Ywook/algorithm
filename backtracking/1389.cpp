#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int map[102][102];
int n, m;
int visit[102];
int depth[102];
int ans = 1000000000;
void bfs(int st){
    queue<int> q;
    visit[st] = 1;
    q.push(st);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(visit[i] == 0 && map[cur][i] == 1){
                q.push(i);
                visit[i] = 1;
                depth[i] = depth[cur] + 1;
            }
        }
    }

}
int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        map[t1][t2] = 1;
        map[t2][t1] = 1;

    }
    int ans2 = 1;
    for(int i = 1; i <= n; i++){
        bfs(i);
        int temp = 0;
        for(int i =1; i<= n; i++){
            temp += depth[i];
            visit[i] = 0;
            depth[i] = 0;
        }
        if(temp < ans){
            ans = temp;
            ans2 = i;
        }
    }
    printf("%d\n", ans2);

}