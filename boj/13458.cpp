#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long a[1000001];
vector<long long> v;
long long ans = 0;
int main(){
    long long n, b, c;
    scanf("%lld", &n);
    long long min_n;
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    scanf("%lld %lld", &b, &c);
    min_n = a[0];
    for(int i = 0; i < n; i++){
        a[i] -= b;
        ans++;
        if(a[i] > 0) {
            min_n = min(min_n, a[i]);
            v.push_back(i);
        }
    }
    for(long long b : v){
        ans += a[b]/c;
        if(a[b] % c != 0) {
            ans++;
        }
    }
     // 3명 
    // 1 2 3
    cout<<ans<<endl;


}