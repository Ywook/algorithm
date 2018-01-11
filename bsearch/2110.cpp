#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int c,n;
    vector<int> v;
    cin >> n >>c;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    long long left = v[0];
    long long right = v[n-1];
    
    int cnt;
    int ans = 0;
    while(left<=right){
        long long mid = (left+right)/2;

        cnt = 1;
        int prev = v[0];
        for(int i = 1; i < n ; i++){
            if(v[i] >= prev+mid){
                cnt++;
                prev = v[i];
            }
        }

        if(cnt >= c){
            if(mid > ans) {
                ans = mid;
            }

            left = mid+1;
        }else{
            right = mid-1;
        }
        
    }
    cout << ans << endl;
}