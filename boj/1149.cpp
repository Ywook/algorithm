#include<cstdio>
#include<iostream>

using namespace std;
int arr[1004][3];
int dp[1004][3];
int main(){
    int n;
    int ans = 1000000000;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
            if(i == 0) dp[i][j] = arr[i][j];
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = 100000000;
            for(int k = 0; k < 3; k++){
                if(j == k) continue;
                dp[i][j] = min(dp[i][j],dp[i-1][k] + arr[i][j]);
            }
        }
    }
    for(int i = 0; i < 3; i++){
        ans = min(ans, dp[n-1][i]);
    }
    cout<<ans<<endl;
}