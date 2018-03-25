#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> a[20001];
int visit[20001];

void dfs(int color, int x){
    visit[x] = color;

    for(int i = 0; i < a[x].size(); i++){
        int next = a[x][i];
        if(visit[next] == 0){
            if(color == 1){
                dfs(2, next);
            }else{
                dfs(1, next);
            }
        }
    }
}
int main(){
    int k;
    bool ans;
    scanf("%d", &k);
    int empty = -1;
    while(k--){
        int v, e;
        scanf("%d %d", &v, &e);

        for(int i = 0; i < e; i++){
            int s1, s2;
            scanf("%d %d", &s1, &s2);
            a[s1].push_back(s2); a[s2].push_back(s1);
        }
        //기분 좋아땅

        for(int i = 1; i <= v; i++){
            if(visit[i] == 0){
                dfs(1, i);
            }
        }
        ans = true;
        for(int i = 1; i <= v; i++){
            for(int j = 0; j < a[i].size(); j++){
                int t  = a[i][j];

                if(visit[i] == visit[t] && i != t){
                    ans = false;
                    break;
                }
            }   
            if(!ans) break;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        for(int i = 1; i <= v; i++){
            a[i].clear();
            visit[i] = 0;
        }
    }
    
    return 0;
}