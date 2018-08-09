#include<cstdio>
#include<iostream>

using namespace std;

void binary(int n){
    if(n == 0 || n== 1){
        printf("%d", n);
        return;
    }

    if( n % -2 == 0)
    {
        binary(n / -2);
        printf("0");
    }else{
        binary((n - 1) / -2);
        printf("1");
    }
}
int main(){
    int n;

    scanf("%d", &n);
    binary(n);
    printf("\n");
}