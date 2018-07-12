#include<iostream>
#include<cstdio>

using namespace std;

int d[10003];
int p[10003];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
    }

    d[1] = p[1];
    d[2] = max(p[1]*2, p[2]);

    for(int i = 3; i <= n; i++){
        d[i] = p[i];
        for(int j = 1; j <= i/2; j++){
            d[i] = max(d[i], d[i-j] + d[j]);
        }
    }
    printf("%d\n", d[n]);
    return 0;
}