#include <iostream>

using namespace std;

int arr[1004];
int dp[1004];

int main(){
    int n;
    int ans = 0;
    cin >> n;

    for(int i=0 ; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        if(dp[i] > ans) ans = dp[i];
    }
    cout<<ans<<endl;
}