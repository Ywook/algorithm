#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check[104][104];
int m, n, k;

int bfs(int x1,int y1){
    check[y1][x1] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x1,y1));
    int ans= 0;
    while(!q.empty()){
        ans +=1;
        int x3 = q.front().first; int y3 = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = x3 + dx[i]; 
            int y = y3 + dy[i];
            if(check[y][x] == false && 0 <= x && x< n && 0 <= y && y < m){
                check[y][x] =true;
                q.push(make_pair(x,y));
            }
        }
    }


    return ans;
}

int main(){
    int ans = 0;
    vector<int> ans_n;
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for(int y = y1; y < y2; y++){
            for(int x = x1; x < x2; x++){
                check[y][x] = true;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j] == false){
                ans++;
                ans_n.push_back(bfs(j,i));
            }
        }
    }
    sort(ans_n.begin(), ans_n.end());
    
    cout<<ans<<endl;
    for(int i = 0; i < ans_n.size(); i++){
        printf("%d ", ans_n[i]);
    }
    cout<<endl;
    
}