#include<iostream>
#include<cstdio>

using namespace std;
int a[102];
int d[100003];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= k; i++) d[i] = -1;
    d[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j-a[i] >= 0 && d[j-a[i]] != -1){
                if(d[j] == -1 || d[j] > d[j-a[i]+1]){
                    d[j] = d[j-a[i]]+1;
                }
            }
        }
    }
    printf("%d\n",d[k]);
}