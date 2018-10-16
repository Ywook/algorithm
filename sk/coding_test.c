#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    int a[32];
    int c[32];
    int *b;

    b = (int*) malloc(sizeof(int)*32);
    a = c;
    memcpy(a, "Hello world", sizeof(int)*32);
    printf("%s\n",a);

}