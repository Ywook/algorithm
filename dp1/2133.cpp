#include <iostream>
using namespace std;
long long dp[35];
int main(void){
    int n;

    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;

    for(int i = 6 ; i<= n; i++){
        if(i%2 != 0) continue;
        dp[i] = 3*dp[i-2];
        for(int j = i-4; j >= 0 ; j-=2){
            dp[i] += dp[j]*2;
        }
    }
    cout<<dp[n]<<endl;
} 