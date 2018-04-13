#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
int visit[22];
int a[22][22];
int n;
int ans = 1000000000;

void solve(){
    vector<int> team_A, team_B;
    team_A.push_back(0);
    team_B.push_back(0);
    for(int i = 1; i <=n; i++){
        if(visit[i]) team_A.push_back(i);
        else team_B.push_back(i);
    }
    int res_A, res_B;
    res_A = res_B = 0;
    for(int i = 1; i <= n/2; i++){
        for(int j = i + 1; j <= n/2; j++){
            res_A += a[team_A[i]][team_A[j]];
            res_A += a[team_A[j]][team_A[i]];

            res_B += a[team_B[i]][team_B[j]];
            res_B += a[team_B[j]][team_B[i]];
        }
    }
    ans = min(ans, abs(res_A - res_B));
}
void dfs(int index, int depth){
    if(depth == n/2){
        solve();
        return;
    }
    for(int i = index + 1; i <= n; i++){
        if(!visit[i]){
            visit[i] = 1;
            dfs(i, depth+1);
            visit[i] = 0;
        }
    }
    return;
}
int main(){
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    dfs(0, 0);
    cout<<ans<<endl;
}