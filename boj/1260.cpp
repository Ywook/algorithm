#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

bool check[1024];
vector<int> a[1024];

void dfs(int x){
    check[x] = true;
    printf("%d ", x);

    for(int i=0;i < a[x].size() ;i++){
        int tmp = a[x][i];
        if(check[tmp] == false){
            dfs(tmp);
        }
    }
}

void bfs(int x){
    queue<int> q;
    check[x] = true;
    q.push(x);
    
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        printf("%d ",tmp);
        for(int i = 0 ; i < a[tmp].size(); i++){
            int next = a[tmp][i];
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    int n,m,s, u, v;

    queue<int> q;

    scanf("%d %d %d", &n,&m,&s);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }
    
    dfs(s);
    memset(check, false, sizeof(check));
    printf("\n");
    bfs(s);
}