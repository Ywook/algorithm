#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    int cnt = 1;
    vector<pair<int, int>> v;
    cin >>n;

    while(n--){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b,a));
        
    }
    sort(v.begin(), v.end());
    int len = v.size();
    int end_time = v[0].first;
    for(int i = 1 ; i < len; i++){
        if(v[i].second >= end_time){
            cnt++;
            end_time=v[i].first;
        }
    }
    cout<<cnt<<endl;;

}