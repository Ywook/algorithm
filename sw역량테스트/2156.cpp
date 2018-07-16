#include<iostream>
#include<cstdio>

using namespace std;

int a[10004];
int d[10004];
int main(){
    int n;
    scanf("%d", &n);   

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    d[1] = a[1];
    d[2] = a[1] + a[2];
    d[3] = max(a[1] + a[3], a[2] + a[3]);

    for(int i = 4; i <= n; i++){
        d[i] = max(d[i-2] + a[i], d[i-1]);
        d[i] = max(d[i], d[i-3] + a[i-1] + a[i]);
    }
    printf("%d\n", d[n]);

}