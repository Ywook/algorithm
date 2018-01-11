#include <iostream>

using namespace std;

int arr[10004];
long long dp[10004][3];

int main(void){
    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][0] = max(dp[i][0], dp[i-1][2]);

        dp[i][1] = max(dp[i-1][0] + arr[i], dp[i-2][2] + arr[i]);

        dp[i][2] = dp[i-1][1] + arr[i]; 
    }

    for(int i = 0; i < 3; i++){
        dp[n][0] = max(dp[n][0], dp[n][i]);
    }

    cout << dp[n][0] <<endl;
}