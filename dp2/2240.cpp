#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1004];
int dp[1004][32][3];
int t,w;

int sol(int i, int j,int k)
{
    if(i == t+1 && j <= w)
    {
        return 0;
    }
    if(j > w){
        return 0;
    }
    if(dp[i][j][k] != -1) return dp[i][j][k];
    dp[i][j][k] = max(sol(i+1,j,k),sol(i+1, j+1, 3-k)) + (a[i] == k ? 1:0);
    return dp[i][j][k];
}
int main(void)
{
    cin>>t>>w;
    
    for(int i = 1 ; i <= t; i++)
    {
        scanf("%d",&a[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n",max(sol(1,0,1),sol(1,1,2)));
}