#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int map[52][52];
int visit[2600];

vector<pair<int, int> > house;
vector<pair<int, int> > store;
int n, m;
int ans = 100000000;
int solve(){
    int cnt = 0;
    int y, x;
    for(int i = 0; i < house.size(); i++){
        int temp = 1000000000; 
        for (int j = 0; j < store.size(); j++)
        {
            if(visit[j]){
                temp = min(temp, abs(house[i].first - store[j].first) + abs(house[i].second - store[j].second));
            }
        }
        cnt += temp;
    }
    return cnt;
}
void dfs(int index, int depth){
    if(depth == m){
        ans = min(ans, solve());
        return;
    }

    for(int i = index; i < store.size(); i++){
        visit[i] = 1;
        dfs(i+1,depth+1);
        visit[i] = 0;
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1){
                house.push_back(make_pair(i, j));
            }else if(map[i][j] == 2){
                store.push_back(make_pair(i,j));
            }
        }
    }
    dfs(0,0);
    printf("%d\n",ans);
}