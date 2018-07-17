#include<iostream>
#include<cstdio>

using namespace std;

int a[1004];
int d[1004];
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = n; i > 0; i--){
        d[i] = 1;
        for(int j = n; j > i; j--){
            if(a[i] > a[j] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
            }
        }
        ans = max(ans, d[i]);
    }
    printf("%d\n", ans);
}