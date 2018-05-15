#include<iostream>
#include<cstdio>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> rule[1002];
int d[1002];
int dp[1002];

int dfs(int w){
    if(dp[w]){
        return dp[w];
    }
    int ans = 0;
    int s = rule[w].size();
    while(s--){
        int tmp = dfs(rule[w].back());
        ans = max(ans, tmp);
        rule[w].pop_back();
    }
    dp[w] = ans + d[w];
    return dp[w];
}
int main(){
    int t;
    //시작 노드를 찾아야한다!
    scanf("%d", &t);

    while(t--){
        int n, k, w;
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++){
            d[i] = 0;
            dp[i] = 0;
            scanf("%d", &d[i]);
        }
        for(int i = 0; i < k; i++){
            int x,y;
            scanf("%d %d", &x, &y); //시작노드를 찾아보자. 차수가 0인 노드를 찾으면 해결할 수 있다.
            rule[y].push_back(x);
        }
        scanf("%d", &w);
        int res = dfs(w);
        cout<<res<<endl;        
        
        for(int i = 1; i <= n; i++){
            rule[i].clear();
        }
    }
}
