#include <iostream>
#include <cstdio>
using namespace std;

long long a[10004];
int n,k;

bool check(long long mid){
    int cnt = 0;
    for(int i = 0; i < k; i++){
        cnt += a[i]/mid;
    }
    return cnt>=n;
}
int main(){
    long long max_n = 0;
    scanf("%d %d", &k, &n);
    for(int i =0 ; i<k; i++){
        scanf("%lld", &a[i]);
        max_n = max(max_n, a[i]);
    }

    long long ans = 0;
    long long left = 1;
    long long right = max_n;

    while(left <= right){
        long long mid = (left+right)/2;
        if(check(mid)){
            ans = max(ans, mid);
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    cout<<ans<<endl;
    return 0;
}