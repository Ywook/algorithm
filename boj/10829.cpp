#include<iostream>
#include<cstdio>

using namespace std;

void binary(unsigned long long n){
    if(n == 0 || n== 1){
        printf("%lld", n);
        return;
    }
    binary(n/2);
    printf("%lld", n%2);
    
}
int main(){
    unsigned long long n;
    unsigned long long sum = 0;
    scanf("%lld", &n);
    unsigned long long i = 1;
    binary(n);
    printf("\n");
    while(1){
        if(n == 0 || n == 1){
            sum += n*i;
            break;
        }
        sum += (n%2)*i;
        i *= 10;
        n /=2;
    }

    printf("%lld\n", sum);
}