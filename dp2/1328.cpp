#include <iostream>
#include <cstdio>
#define mod 1000000007
using namespace std;
long long dp[104][104][104];
int main(void){
    int l, r, n;

    scanf("%d", &n); 
    scanf("%d", &l);
    scanf("%d", &r);

    dp[1][1][1] = 1ll;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= l; j++){
            for(int k = 1; k <= r; k++){
                dp[i][j][k] = (dp[i-1][j-1][k] + dp[i-1][j][k-1]+dp[i-1][j][k]*(i-2))%mod;
                
            }
        }
    }
    cout<<dp[n][l][r]<<endl;
}