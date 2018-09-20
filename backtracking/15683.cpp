#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int map[10][10]; //원본

int n, m;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int ans = 1000000;
vector<pair<int, int> > v;

void copyMap(int (*a)[10], int (*b)[10]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = b[i][j];
        }
    }
}
void solve(int y, int x, int d){
    int ny = y + dy[d];
    int nx = x + dx[d];

    if(nx >= 0 && nx < m && ny >= 0 && ny < n){
        if(map[ny][nx] == 6){
            return;
        }else if(map[ny][nx] == 0){
            map[ny][nx] = -1;
        }
        solve(ny, nx, d);
    }
}

void dfs(int cnt){
    if(cnt >= v.size()){
        int temp = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 0){
                    temp++;
                }
            }

        }
        ans = min(ans,temp);
        return;
    }

    int copy_map[10][10];

    int y = v[cnt].first;
    int x = v[cnt].second;
    int cctv_n = map[y][x];

    if(cctv_n == 1){
        for(int i = 0; i < 4; i++){
            copyMap(copy_map, map);
            solve(y, x, i);
            dfs(cnt + 1);
            copyMap(map, copy_map);
        }
    }else if(cctv_n == 2){
        for(int i = 0; i < 3; i+=2){
            copyMap(copy_map, map);
            solve(y,x, i);
            solve(y,x, i+1);
            dfs(cnt + 1);
            copyMap(map, copy_map);
        }
    }else if(cctv_n == 3){
        for(int i = 0; i < 2; i++){
            for(int j = 2; j < 4; j++){
                copyMap(copy_map, map);
                solve(y, x, i);
                solve(y, x, j);
                dfs(cnt + 1);
                copyMap(map, copy_map);
            }
        }
    }else if(cctv_n == 4){
        for(int i = 0; i < 4; i++){
            copyMap(copy_map, map);
            solve(y, x, i);
            solve(y, x, (i+1)%4);
            solve(y, x, (i+2)%4);
            dfs(cnt + 1);
            copyMap(map, copy_map);
        }
    }else{
        copyMap(copy_map, map);
        for(int i = 0; i < 4; i++){
            solve(y, x, i);
        }
        dfs(cnt + 1);
        copyMap(map, copy_map);
    }
}
int main(){
    int i, j;
    
    scanf("%d %d",&n, &m);

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] > 0 && map[i][j] < 6){
                v.push_back(make_pair(i,j));
            }
        }
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}