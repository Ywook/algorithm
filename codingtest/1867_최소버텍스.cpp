#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
vector<int> g[501];
int visit[501], b[501];

int dfs(int r){
    if(visit[r]) return 0;
    visit[r] = 1;

    for(int next : g[r]){
        if(!b[next] || dfs(b[next])){
            b[next] = r;
            return 1;
        }
    }
    return 0;
} 
int main(){ 
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < k; i++){
        int row, col;
        scanf("%d %d", &row, &col);
        g[row].push_back(col);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        memset(visit, 0,sizeof(visit));
        ans+=dfs(i);
    }
    cout<<ans<<endl;
}