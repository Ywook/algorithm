#include <iostream>
#include <vector>
using namespace std;


vector<int> graph[20004];
int color[20004];

bool dfs(int x, int y){
    color[x] = y;

    for(int i = 0; i < graph[x].size(); i++){
        int t = graph[x][i];
        if(color[t] == y) return false;
        if(color[t] == 0 && !dfs(t,-y)) return false;
    }

    return true;
}
int main(void){
    int v,e,k;
    cin>>k;

    while(k--){
        cin>>v>>e;
        bool ans = true;

        for(int i = 1; i<= v; i++){
            graph[i].clear();
            color[i]=0;
        }

        for(int i = 1; i <= e; i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y); graph[y].push_back(x);
        }

        for(int i = 1; i<= v; i++){
            if(!ans) break;
            if(color[i]==0){
                ans = dfs(i,1);
            }
        }
        (ans)? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}