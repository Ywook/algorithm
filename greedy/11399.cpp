#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n;
    long long sum = 0;
    vector<int> v;
    vector<int> v2;
    cin >>n;
    while(n--){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int len = v.size();
    v2.push_back(v[0]);
    for(int i = 1; i < len; i++){
        v2.push_back(v2[i-1]+v[i]);
    }
    
    for(int i = 0 ; i < len; i++){
        sum += v2[i];
    }
    cout<<sum<<endl;
}