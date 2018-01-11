#include <iostream>
#include <vector>

using namespace std;
vector<int> a;

long long bsearch(int k, int len){
    long long cnt = 0;
    for(int i = 0; i < k; i++){
        cnt += a[i]/len;
    }
    return cnt;
}
int main(void){
    long long k , n, max, min;
    long long cnt;
    cin >>k >> n;

     max = 0;
    for(int i = 0 ; i < k; i++){
        int t;
        cin >> t;
        if(max < t) max = t;
        a.push_back(t);
    }

    min = 0;
    long long ans =0;
    while(min <= max){
        long long mid = (min+max)/2;
        cnt = bsearch(k, mid);
        if(cnt < n){
            max = mid-1;
        }else{
            if(mid > ans){
                ans = mid;
            }
            min = mid+1;
        }
    }
    
    cout << ans << endl;
}