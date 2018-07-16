#include<iostream>
#include<cstdio>

using namespace std;

long long d[102][11];
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= 9; i++){
        d[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        d[i][0] = d[i-1][1];
        for(int j = 1; j < 10; j++){
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%1000000000;
        }
    }
    long long ans = 0;

    for(int i = 0; i < 10; i++){
        ans = (ans + d[n][i])%1000000000;
    }
    printf("%lld\n",ans);
    return 0;
}