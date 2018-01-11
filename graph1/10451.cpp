#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> v(1004);
bool check[1004];

int dfs(int x, int y){
    if(check[v[x]] == 1 && v[x] != y) return 0;
    if(check[v[x]] == 1 && v[x] == y) return 1;
    check[x] = 1;
    if(dfs(v[x],y)==0) return 0;
    return 1;
}

int main(void){
    int t, n;
    
    cin>>t;

    while(t--){
        cin>>n;

        for(int i = 1; i<= n; i++){
            cin>>v[i];
            check[i]=false;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(check[i] == false) {
                ans+=dfs(i,i);
            }
        }
        cout<<ans<<endl;
    }
}