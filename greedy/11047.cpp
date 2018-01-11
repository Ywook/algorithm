#include <iostream>
#include <vector>

using namespace std;



int main(void){
    int n,k, sum, max;
    vector<int> d;
    cin >>n>>k;

    for(int i = 0; i < n; i++){
        int t;
        cin>>t;
        d.push_back(t);
    }
    sum = 0;
    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if(d[i] > k) continue;
        else{
            if(sum == k) break;
            while(sum + d[i] <= k)
            {
                sum += d[i];
                cnt++;
            }
        }
    }
    cout << cnt <<endl;
    
}