#include <stdio.h>

void binary(int num)
{
    if(num == 0 || num == 1) printf("%d",num);
    else{
        binary(num/2);
        printf("%d", num%2);
    }
    
}

int main()
{
    int n;
    scanf("%d", &n);

    // 재귀 함수 부분
    binary(n);

    printf("\n");

    // while 부분

    int binary, sum = 0, i = 1;
    while (1) {
        if(n == 0 || n == 1) {
            sum += n*i;
            break;
        }

        binary = n % 2;
        n /= 2;
        sum += binary*i;
        i*=10;
    }
    printf("%d\n", sum);
    return 0;
}