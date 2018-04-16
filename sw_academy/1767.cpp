#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> q;
vector<int> v;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n;
int map[14][14];

int ans_core;
int ans;

int isLine(int x, int y, int d){
    if(d == 0){
        for(int i = y + 1; i < n; i++){
            if(map[i][x] != 0) return 0;
        }
    }else if(d == 1){
        for(int i = 0; i < y; i++){
            if(map[i][x] != 0) return 0;
        }
    }else if(d == 2){
        for(int i = x + 1; i < n; i++){
            if(map[y][i] != 0) return 0;
        }
    }else{
        for(int i = 0; i < x ; i++){
            if(map[y][i] != 0) return 0;
        }
    }
    return 1;
}

int drawLine(int x, int y, int d, int flag){
    int ans=0;
    if(d == 0){
        for(int i = y + 1; i < n; i++){
            map[i][x] = (flag)? 2:0;
            ans++;
        }
    }else if(d == 1){
        for(int i = 0; i < y; i++){
            map[i][x] = (flag)? 2:0;
            ans++;
        }
    }else if(d == 2){
        for(int i = x + 1; i < n; i++){
            map[y][i] = (flag) ? 2 : 0;
            ans++;
        }
    }
    else{
        for (int i = 0; i < x; i++)
        {
            map[y][i] = (flag) ? 2 : 0 ;
            ans++;
        }
    }
    return ans;
}
void dfs(int depth,int sum, int core){
    if(depth == q.size()){
        if(ans_core < core){
            ans = sum;
            ans_core = core;
        }else if (ans_core == core){
            ans = min(ans,sum);
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        if(isLine(q[depth].second, q[depth].first, i)){
            dfs(depth + 1, sum + drawLine(q[depth].second, q[depth].first, i, 1), core+1);
            drawLine(q[depth].second, q[depth].first, i, 0);
        }
    }
    dfs(depth + 1, sum, core);
}
int main(){
    int t;
    scanf("%d", &t);
    for(int l = 1; l <= t; l++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &map[i][j]);
                if(map[i][j] == 1){
                    if (i == 0 || j == 0 || i == n - 1 || j == n - 1){
                        continue;
                    }
                    q.push_back(make_pair(i, j));
                }
            }
        }

        dfs(0,0,0);
        cout<<"#"<<l<<" "<<ans<<endl;
        ans = 1000000000;
        ans_core = 0;
        q.clear();
    }
}