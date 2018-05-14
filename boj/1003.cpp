#include<iostream>
#include<cstdio>

using namespace std;
int dp[41][2];
int main(){
    int t;
    scanf("%d", &t);
    dp[0][0] = 1;
    dp[0][1] = 0;
    
    dp[1][0] = 0;
    dp[1][1] = 1;

    dp[2][0] = 1;
    dp[2][1] = 1;

    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 3; i <= n; i++){
            dp[i][0] = dp[i-1][0] + dp[i-2][0];
            dp[i][1] = dp[i-1][1] + dp[i-2][1];
            
        }
        cout<<dp[n][0]<<" "<<dp[n][1]<<endl;
    }
    return 0;
}