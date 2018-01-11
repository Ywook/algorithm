#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[30][30];
int check[30][30];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> ans;

void dfs(int i, int j, int cnt){
    check[i][j] = 1;
    ans[cnt]++;

    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        
        if(0 <= x && 0 <= y){
            if(arr[x][y] == 1 && check[x][y] == 0){
                dfs(x,y, cnt);
            }
        }
    }
}

int main(void){
    int n, t;
    int cnt = 0;
    scanf("%d",&n);
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n; j++){
            scanf("%1d",&arr[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1 && check[i][j] == 0){
                ans.push_back(0);
                dfs(i, j, cnt++);
            }
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}