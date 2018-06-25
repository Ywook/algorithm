#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int w[12][12];
int main(){
    int n;
    int ans = 100000000;
    scanf("%d", &n);
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int t;
            scanf("%d", &w[i][j]);
        }
    }
    for(int i = 0; i < n ; i++){
        v.push_back(i+1);
    }
    do{
        bool check = true;
        int sum = 0;
        for(int i = 0 ; i < n-1; i++){
            if(!w[v[i]][v[i+1]]) check = false;
            else sum += w[v[i]][v[i + 1]];
        }
        if(check && w[v[n-1]][v[0]] != 0){
            sum += w[v[n - 1]][v[0]];
            ans = (ans > sum) ? sum : ans;
        }
    }while(next_permutation(v.begin() + 1, v.end()));
    cout<<ans<<endl;
}