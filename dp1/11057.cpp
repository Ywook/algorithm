#include <iostream>

using namespace std;

long dp[1004][13];
int main(){
    int n;

    cin>>n;
    for(int i = 0 ; i < 10; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            for(int k = j; k < 10; k++){
                dp[i][j] = (dp[i][j] + dp[i-1][k])%10007;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        dp[n][10] = (dp[n][10]+dp[n][i])%10007;
    }
    cout<<dp[n][10]<<endl;
}