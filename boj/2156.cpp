#include <iostream>

using namespace std;
int arr[10004];
int dp[10004];

int main(){
    int n;

    cin>>n;
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    if (n>=2){
        dp[2] = dp[1] + arr[2];
    }
    if (n>=3){
        dp[3] = max(dp[2], arr[1] + arr[3]);
        dp[3] = max(dp[3], arr[2] + arr[3]);
    }

    for(int i = 4; i <= n; i++){
        dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
        dp[i] = max(dp[i], dp[i-3] + arr[i-1] + arr[i]);
    }
    cout<<dp[n]<<endl;
}