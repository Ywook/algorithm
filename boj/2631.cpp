#include<iostream>
#include<cstdio>

using namespace std;
int a[203];
int d[203]; // 
int main(){
    int n, i, j, longest;
    scanf("%d", &n);
    longest = 1;
    for(i =1 ; i <= n; i++){
        scanf("%d", &a[i]);
        d[i] = 1;
    }
    for(i = 2; i <= n; i++){
        for(j = i-1; j >= 0; j--){
            if(a[i] > a[j] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                longest = max(d[i], longest);
            }
        }
    }
    printf("%d\n", n-longest);
    return 0;
}