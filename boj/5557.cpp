#include<iostream>
#include<cstdio>

using namespace std;

int a[103];
long long dp[103][23]; //index sum 이다.
int n;

long long solve(int index, int sum){
    if (index < 1 || sum < 0 || sum > 20)
        return 0;
    if (index == 1 && sum == a[1]) return 1;
    if(dp[index][sum] != 0) return dp[index][sum];
    dp[index][sum] = solve(index-1, sum + a[index]) + solve(index-1, sum - a[index]);
    return dp[index][sum];
}
int main(){
    int i;

    scanf("%d", &n);

    for(i = 1; i <= n ; i ++){
        scanf("%d", &a[i]);
    }
    solve(n-1, a[n]);
    printf("%lld\n", dp[n-1][a[n]]);

}