#include<cstdio>
#include<iostream>

using namespace std;

int a[302][302];
int main(void){
    int n, m, k;

    scanf("%d %d", &n, &m);

    for(int i =1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d", &k);
    for(int m = 0; m < k; m++){
        int i, j, x, y;
        scanf("%d %d %d %d", &i, &j, &x, &y);

        int ans = 0;
        for(int row = i; row <= x; row++){
            for(int col = j; col <= y; col++){
                ans += a[row][col];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}