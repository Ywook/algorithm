#include<iostream>
#include<cstdio>

using namespace std;

int d[1004][11];
int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0; i < 10; i++){
        d[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        d[i][0] = d[i-1][0];
        for(int j = 1; j < 10; j++){
            for(int k = 0; k <= j; k++){
                d[i][j] = (d[i][j] + d[i-1][k])%10007;
            }
        }
    }
    int ans = 0;
    for(int i =0 ; i < 10; i++){
        ans = (ans + d[n][i])%10007;
    }
    printf("%d\n",ans);
}