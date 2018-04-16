#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, k;

int dx[3] = {2,-1,1};
vector<int> visit(100001,-1);
bool check[100004];

int bfs(){
    if(n==k) {
        return 0;
    }
    queue<int> q;
    q.push(n);
    visit[n] = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        check[x] = true;
        if(x == k){
            return visit[k];
        }

        for(int i = 0; i < 3; i++){
            int nx;
            if(i == 0) nx = x * dx[i];
            else nx = x + dx[i];
            
            if(nx < 0 || nx > 100001){
                continue;
            }
            if(visit[nx] == -1|| visit[nx] > visit[x]+1){
                visit[nx] = visit[x] + 1;
                q.push(nx);
             }
        }
    }
    return visit[k];
}
int main(){
    scanf("%d %d", &n, &k);

    cout<<bfs()<<endl;
    return 0;
}