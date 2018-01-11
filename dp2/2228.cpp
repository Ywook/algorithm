#include<iostream>
#include<vector>

using namespace std;
vector<int> v;
int main(void){
    int n,m;

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

}