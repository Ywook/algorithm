#include<iostream>
#include<cstdio>

using namespace std;

int d[1000004];
int main(){
    int n;
    scanf("%d", &n);

    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    d[4] = 5;

    for(int i = 5; i <= n; i++){
        d[i] = (d[i-1] + d[i-2])%15746;
    }
    printf("%d\n", d[n]);
} 
