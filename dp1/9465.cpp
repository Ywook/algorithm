#include <iostream>

using namespace std;
int arr[100004][2];
long long dp[100004][3];
int main(void){
    int n, test_case;

    cin >> test_case;

    while(test_case--){
        cin >> n;
        
        for(int i = 1 ; i <= n ; i ++){
            cin >> arr[i][0];
            dp[i][0] = 0;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        for(int i = 1 ; i <= n; i++){
            cin >> arr[i][1];
        }

        for(int i = 1; i <= n ; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][0] = max(dp[i][0], dp[i-1][2]);
            
            dp[i][1] = max(dp[i-1][2] + arr[i][0], dp[i-1][0]+arr[i][0]);
            dp[i][2] = max(dp[i-1][0]+arr[i][1], dp[i-1][1] + arr[i][1]);
        }

        for(int i = 0; i < 3; i++){
            dp[n][0] = max(dp[n][0], dp[n][i]);
        }
        
        cout << dp[n][0] <<endl;
    }
}