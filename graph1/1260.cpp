#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> v(1004,vector<int>(1004,0)); 
bool check1[1004];
bool check2[1004];
int n, m;

void dfs(int x){
    check1[x] = true;
    cout << x <<" ";
    for(int i = 1; i <= n; i++){
        if(check1[i] == false && v[x][i] == 1){
            dfs(i);
        }
    }
}

void bfs(int x){
    queue<int> q;
    check2[x] = true; q.push(x);

    while(!q.empty()){
        x = q.front(); q.pop();
        cout << x << " "; 
        for(int i = 1; i <= n; i++){
            if(v[x][i] == 1 && check2[i] == false){
                check2[i] = true;
                q.push(i);
            }
        }
    }
}

int main(void){
    int k;

    cin >> n >> m >>k;

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >>x>>y;
        v[x][y] = v[y][x] = 1;
    }
    dfs(k);
    cout << endl;
    bfs(k);
}