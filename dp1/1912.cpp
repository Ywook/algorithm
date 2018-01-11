#include <iostream>

using namespace std;

long arr[100004];
long dp[100004][100004];

int main(int argx, char const *argv[]){
    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n ; i++){
        dp[i][i] = arr[i];
        for(int j = i+1; j <=n ; j++){
            dp[i][j] = dp[i][j-1] + arr[j];
        }
        dp[i][0] = dp[i][i];
        for(int k = i; k <= n; k++){
            dp[i][0] = max(dp[i][0],dp[i][k]);
        }
    }

    for(int i = 1; i <= n; i++){
        dp[1][0] = max(dp[1][0], dp[i][0]);
    }
    
    cout << dp[1][0] << endl;
    
    return 0;
}                                   