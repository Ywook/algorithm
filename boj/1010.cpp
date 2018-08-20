#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int d[31][31];

int main(){
    int n, m, t, i,j,k;
    scanf("%d", &t);

    for (i = 1; i < 31; i++) d[1][i] = i;
    for (i = 2; i < 31; i++)
    {
        for (j = i; j <= 31; j++)
        {
            for (k = j; k >= i; k--)
                d[i][j] += d[i - 1][k - 1];
        }
    }

    while(t--){
        scanf("%d %d", &n, &m);
        printf("%d\n", d[n][m]);
    }


    return 0;
}