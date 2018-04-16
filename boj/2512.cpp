#include <iostream>
#include <cstdio>
using namespace std;

long long a[10001];

int main(){
    long long n, m, left, right;

    scanf("%lld", &n);
    right = 1;
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        right = max(right, a[i]);
    }
    scanf("%lld", &m);
    long long ans = 0;
    left = 1;
    while(left <= right){
        long long mid = (left + right)/2;
        long long total = 0;

        for(int i = 0; i < n; i++){
            total += (mid>a[i])? a[i]:mid;
        }
        if(total > m){
            right = mid - 1;
        }else{
            left = mid +1;
            ans = mid;
        }
    }
    cout<<ans<<endl;

    return 0;
}