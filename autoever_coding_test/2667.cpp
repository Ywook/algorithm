#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int temp = 0;
int map[27][27];
int check[27][27];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> v;

void dfs(int y, int x) {
    check[y][x] = 1;
    temp++;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (map[ny][nx] == 1 && check[ny][nx] == 0) dfs(ny, nx);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (map[i][j] == 1 && check[i][j] == 0) {
                temp = 0;
                dfs(i, j);
                v.push_back(temp);
            }
        }
    }

    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for (int i : v) printf("%d\n", i);

    return 0;
}