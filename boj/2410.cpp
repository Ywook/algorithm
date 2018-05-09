#include<iostream>
#include<cstdio>

using namespace std;
long long dp[1000002];
int main(){
    int n;
    //1, 2 , 4 , 8, 16... i-k
    scanf("%d", &n);

    dp[0]= 1;
    for(int j = 0; (1<<j)<= n; j++){
        int k = 1<<j;
        for(int i = k; i <=n; i++){
            dp[i] =(dp[i]+ dp[i-k])%1000000000;
        }
    }
    cout<<dp[n]<<endl;
}