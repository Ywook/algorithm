#include <iostream>
#include <cstdio>

using namespace std;
int a[1004];
int dp[1004];
int main(){
    int n;
    int ans = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < n; j++){
            if(a[i] < a[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j]+1;
            }
        }
        ans = max(dp[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}