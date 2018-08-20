#include<stdio.h>

int main(){
    int a[11][11];
    int n, value, row, col ,alpha = 1;
    scanf("%d", &n);
    int tmp = n;
    value = n*n;
    row = 0;
    col = -1;
    while(tmp>0){
        for(int i = 0; i < tmp; i++){
            col += alpha;
            a[row][col] = value;
            value--;
        }
        tmp--;
        for(int i = 0; i < tmp; i++){
            row += alpha;
            a[row][col] = value;
            value--;
        }
        alpha *= -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}