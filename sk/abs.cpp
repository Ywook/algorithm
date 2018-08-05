#include<stdio.h>


int abs(int n){
    int temp = (n >> 31);
    return (temp ^ n) + (temp & 1);
}
int main(){
    printf("%d\n", abs(32));
}