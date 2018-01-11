#include <iostream>

using namespace std;
int dp[100004];
int main(void){
    int n;

    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 1;

    for(int i = 5; i <= n ; i ++){
        dp[i] = i;
        for(int j = 1; j*j <=n; j++){
            if(dp[i] > dp[i-j*j]+1){
                dp[i] =  dp[i-j*j]+1;
            }
        }
    }

    cout << dp[n] <<endl;
}