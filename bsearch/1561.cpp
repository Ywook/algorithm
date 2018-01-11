#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;
int a[10004];
int n, m;

long long bsearch(long long second){
    long long s = 0;
    for(int i = 0; i < m; i++)
    {
        s += (second/a[i]);
    }
    return s;

}
int main(void){
    long long low = 0;
    long long high = LLONG_MAX;
    long long mid;

    cin>>n>>m;
    for(int i = 0; i < m; i++) scanf("%d", &a[i]);
    n-=m;
    if(n<=0){
        cout<< n <<endl;
        return 0;
    }
    while(low <= high){
        mid = (low+high)/2;
        (bsearch(mid) >= n)? high = mid-1 : low = mid+1;
    }
    
    long long cnt = 0;
    for(int i = 0; i < m; i++){
        cnt += (low-1)/a[i];
    }

    if(cnt>=n){
        low--;
        cnt = 0;
        for(int i = 0; i < m; i++){
            cnt += low/a[i];
        }
    }

    low++;
    for(int i = 0; i < m; i++){
        if(!low%a[i]) cnt++;
        if(cnt==n){
            cout<<i+1<<endl;
            break;
        }
    }
}