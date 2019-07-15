#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int n, m, v;
int map[1002][1002];
int check[1002];

queue<int> q;

void dfs(int x){
    check[x] = 1;
    printf("%d ", x);
    for (int i = 1; i <=n; i++) {
        if (map[x][i] == 1 && check[i] == 0) dfs(i);
    }
}

void bfs(int x) {
    check[x] = 1;
    q.push(x);
//    printf("%d ", x);

    while (!q.empty()) {
        x = q.front(); q.pop();
        printf("%d ", x);
        for (int i = 1; i <= n; i++) {
            if (map[x][i] == 1 && check[i] == 0) {
                //printf("%d ", i);
                q.push(i);
                check[i] = 1;
            }
        }
    }
}


int main(){
    scanf("%d %d %d", &n, &m, &v);   

    for(int i = 0;  i < m ; i++){
        int a1, a2;
        scanf("%d %d", &a1, &a2);
        map[a1][a2] = 1;
        map[a2][a1] = 1;
    }
    dfs(v); cout<<endl;
    memset(check, 0, sizeof(check));
    bfs(v); printf("\n");
    return 0;
}