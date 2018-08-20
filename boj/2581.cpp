#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int prime[10003];
int main(){
    int m, n, i, j;
    scanf("%d %d", &m, &n);
    // printf("%d %d\n", m, n);
    prime[1] = 1;
    for(i = 2; i <= sqrt(10000); i++){
        if(!prime[i]){
            for(j = i*i ; j <= 10000; j+=i){
                prime[j] = 1;
            }
        }
    }
    int ans = 10003;
    int sum = 0;
    for(i = m; i <= n; i++){
        if(prime[i] == 0){
            ans = min(i, ans);
            sum += i;
        }
    }
    if(ans == 10003 && sum == 0) printf("-1\n");
    else printf("%d\n%d\n", sum, ans);
    return 0;
}