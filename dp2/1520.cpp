#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> v;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int d[505][505];
int m,n;

int dfs(int i, int j){
    if(i == m-1 && j == n-1) return 1;
    if(d[i][j] != -1) return d[i][j];
    d[i][j] = 0;
    for(int k = 0 ; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        
        if(0 <= x && x < m && 0 <= y && y < n){
            if(v[i][j] > v[x][y]){
                d[i][j] += dfs(x,y);
            }
        }
    }
    return d[i][j];
}
int main(void){
    scanf("%d %d", &m, &n);
    for(int i = 0 ; i < m; i++){
        v.push_back(vector<int>());
        for(int j = 0; j < n; j++){
            int t;
            scanf("%d",&t);
            v[i].push_back(t);
            d[i][j]= -1;
        }
    }
    printf("%d\n", dfs(0,0));
}