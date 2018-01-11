#include <iostream>

using namespace std;

int arr[1004];
int dp[1004];

int main(void){
    int n, max, ans;
    cin >> n;

    for(int i = 1 ; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n ; i ++){
        dp[i] = 1;
        for(int j = 1 ; j < i; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j]+1;
            }
        }
    }
    ans = dp[1];
    for(int i = 2; i <= n; i++){
        if(dp[i] > ans) ans = dp[i]; 
    }

    cout<<ans<<endl;

}