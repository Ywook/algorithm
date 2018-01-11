#include <iostream>
#include <vector>

using namespace std;

int main(void){
    long long n,m;
    long long left = 0;
    long long right = -1;
    vector<int> v;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        long long t;
        cin>>t;
        left = min(t,left);
        right = max(t,right);
        v.push_back(t);
    }
    long long ans = 0;
    long long cnt;
    while(left<=right){
        long long mid = (left+right)/2;
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] > mid) cnt+=(v[i]-mid);
        }

        if(cnt >= m){
            left = mid+1;
            ans = max(ans,mid);
        }else{
            right = mid-1;
        }
        
    }   

    cout << ans<<endl;
}