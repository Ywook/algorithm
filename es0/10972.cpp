#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    vector<int> v;
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }

    if(next_permutation(v.begin(),v.end())){
        for(int i = 0; i < n; i++){
            cout <<v[i]<<" ";
        }
    }else{
        cout <<"-1"<<endl;
    }
    
}