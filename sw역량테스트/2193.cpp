#include<iostream>
#include<cstdio>

using namespace std;

long long d[101][2];
int main(){
    int n;
    scanf("%d", &n);

    d[1][1] = 1;
    d[2][0] = 1;
    d[3][1] = 1;
    d[3][0] = 1;

    for(int i = 4 ; i <= n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    printf("%lld\n", d[n][0] + d[n][1]);
}