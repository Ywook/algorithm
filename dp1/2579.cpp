#include <iostream>

using namespace std;

int arr[305];
long long dp[3][305];
int main(void){
    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    dp[0][1] = arr[1];
    dp[1][1] = arr[1];

    dp[0][2] = arr[2]; 
    dp[1][2] = arr[1] + arr[2];
    dp[2][2] = arr[1];

    for(int i = 3; i <= n; i++){
        dp[0][i] = max(dp[0][i-2]+arr[i], dp[1][i-2] + arr[i]);

        dp[1][i] = dp[0][i-1] + arr[i];
        dp[2][i] = max(dp[1][i-1] + arr[i-1], dp[0][i-1] + arr[i-1]);
    }
    cout<<max(dp[0][n], dp[1][n])<<endl;

}