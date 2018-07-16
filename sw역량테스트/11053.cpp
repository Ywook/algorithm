#include<cstdio>
#include<iostream>

using namespace std;

int a[1003];
int d[1003];
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        d[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[i] > a[j] && d[j] + 1 > d[i]){
                d[i] = d[j] +1;
            }
        }
        ans =max(ans, d[i]);
    }
    printf("%d\n",ans);
}