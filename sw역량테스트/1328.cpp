#include<iostream>
#include<cstdio>

using namespace std;

long long d[102][102][102]; //N개가 있을때 L과 R에서 보이는 개수의 경우의 수
int main(){
    int n, l, r;

    scanf("%d %d %d", &n, &l,&r);

    //같은 높이를 가지는 빌딩은 없다. 
    //빌딩의 높이는 1보다 크거나 같고, N보다 작거나 같고, 같은 높이를 가지는 빌딩은 없다.
    //즉 빌딩의 높이는 1<= <=N;
    d[1][1][1] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= l; j++){
            for(int k = 1; k <= r; k++){
                d[i][j][k] = d[i-1][j-1][k] + d[i-1][j][k-1] + d[i-1][j][k]*(i-2);
                d[i][j][k] %= 1000000007;
            }
        }
    }

    printf("%lld\n", d[n][l][r]);
}