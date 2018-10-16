#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;


int n;
int map[22][22];
int visit[22];
int ans = 1000000000;
void cnt(){
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        if(visit[i]){
            a.push_back(i);
        }else{
            b.push_back(i);
        }
    }
    int sum_a, sum_b;
    sum_a = sum_b = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = i+1; j < a.size();j++){
            sum_a = sum_a + map[a[i]][a[j]] + map[a[j]][a[i]];
            sum_b = sum_b + map[b[i]][b[j]] + map[b[j]][b[i]];
        }
    }
    ans = min(ans, abs(sum_a - sum_b));
}
void dfs(int index, int depth){
    if(depth == n/2){
        cnt();
        return;
    }

    for(int i = index+1; i < n; i++){
        visit[i] = 1;
        dfs(i, depth+1);
        visit[i] = 0;
    }
    return;
}
int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    dfs(0,0);
    printf("%d\n",ans);
}