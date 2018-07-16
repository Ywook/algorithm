#include<iostream>
#include<cstdio>

using namespace std;

int d[100004];
int a[100004];
int main(){
    int n;
    scanf("%d", &n);


    for(int i = 0; i < n ; i++){
        scanf("%d", &a[i]);
    }
    int ans=a[0];
    d[0] = a[0];
    for(int i = 1; i < n; i++){
        d[i] = max(d[i-1] + a[i], a[i]);
        ans = max(d[i], ans);
    }
    printf("%d\n", ans);
}