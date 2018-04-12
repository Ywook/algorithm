#include <iostream>
#include <cstdio>

using namespace std;

int t[17];
int p[17];
int dp[17];
int ans = 0;
int sum = 0;

int n;

void dfs(int index){
    for(int i = index; i <= n;i++){
        if(i + t[i] <= n + 1){
            sum += p[i];
            ans = max(sum,ans);
            dfs(i + t[i]);
            sum -= p[i];
        }
    }
}
int main(){
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }

    for(int i = 1; i <=n; i++){
        if(i + t[i] <= n + 1){
            sum += p[i];
            ans = max(sum, ans);
            dfs(i+t[i]);
            sum -= p[i];
        }
    }
    cout<<ans<<endl;
    //dp 방식
 /*   for(int i = n; i  > 0; i--){
        if(dp[i] == 0) dp[i] = dp[i+1];
        if(i + t[i] > n) continue;
        dp[i] = dp[i+ t[i]] + p[i];
        ans = max(dp[i], ans);
    }
    cout<<ans<<endl;
    return 0;*/
}