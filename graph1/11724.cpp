#include <iostream>
#include <vector>

using namespace std;
vector<int> a[1004];
bool check[1004];

void dfs(int x){
    check[x] = true;
    int size = a[x].size();
    for(int i = 0; i < size; i++){
        int t = a[x][i];
        if(check[t] == false)dfs(t);
    }

}

int main(void){
    int n, m;
    int ans = 1;
    cin>>n>>m;

    for(int i =1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        a[x].push_back(y); a[y].push_back(x);
    }

    dfs(1);

    for(int i = 2; i <= n; i++){
        if(check[i] == false ){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
}
