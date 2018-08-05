#include<stdio.h>

int main(){
    int a[11][11];
    int n, value, row, col ,alpha = 1;
    scanf("%d", &n);
    
    value = n*n;
    int temp_n = n;
    
    row = 0; col = -1;
    while(temp_n > 0){
        for(int i = 0; i < temp_n; i++){
            col += alpha;
            a[row][col] = value;
            value--;
        }
        temp_n--;

        for(int j = 0; j < temp_n; j++){
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