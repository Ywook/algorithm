#include <iostream>

using namespace std;

int arr[1004];
int dp[1004];

int main(void){
    int n;

    cin >> n;

    for(int i = 1; i <= n  ; i ++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(arr[i] < arr[j] && dp[i] < dp[j] +1 ){
                dp[i] = dp[j] + 1;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        dp[1] = max(dp[1],dp[i]);
    }
    cout<<dp[1]<<endl;
}