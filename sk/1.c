#include <stdio.h>

int a[1000003];
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
    int len = 0;
    int binary, sum = 0, i = 1;
    while (1) {
        if(n == 0 || n == 1) {
            a[len] = n;
            break;
        }
        
        binary = n%2;
        a[len] = binary;
        n/=2;
        len++;

    }
    for(int i = len; i > -1; i--){
        printf("%d", a[i]);
    }
    puts("");
    return 0;
}