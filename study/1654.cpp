#include<iostream>
#include<cstdio>

using namespace std;

long long arr[10002];
int k, n;
long long max_len = 1000004;
long long ans = 1;

int check(int x){
    int cnt = 0;
    for(int i = 0 ; i < k; i++){
        cnt += (arr[i]/x);
    }
    return cnt;
}
int main(){
    long long left, mid, right;
    scanf("%d %d", &k, &n);

    for(int i = 0; i < k ; i++){
        scanf("%lld", &arr[i]);
        max_len = max(arr[i], max_len);
    }

    right = max_len;
    left = 1;

    while(left <= right){
        int cnt;
        mid = (left + right)/2;
        cnt = check(mid);

        if(cnt >= n){
            left = mid + 1;
            ans = max(ans, mid);
        }else{
            right = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
    
}