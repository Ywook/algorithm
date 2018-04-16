#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int ans = -1;
int check[101];
queue<int> q;
void dfs(vector<int> *v, int node){
    ans++;
    for(int i : v[node]){
        if(!check[i]) {
            dfs(v, i);
            check[i] = 1;
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    vector<int> v[101];
    for(int i = 0; i < m; i ++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    while(!q.empty()){
        int f = q.front(); q.pop();
        if(check[f]) continue;
        ans++;
        check[f] = 1;
        for(int i : v[f]){  
            if(!check[i]) q.push(i);
        }
    }
    cout<<ans<<endl;
}