#include<iostream>
#include<cstdio>

using namespace std;
int a[502][502];
int dp[502][502];
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &a[i][j]);
        }
    }
    dp[1][1] = a[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1){
                dp[i][j] = a[i][j] + dp[i-1][j];
            }else if(i == j){
                dp[i][j] = a[i][j] + dp[i-1][j-1];
            }else{
                dp[i][j] = max(a[i][j] + dp[i - 1][j], a[i][j] + dp[i - 1][j - 1]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}