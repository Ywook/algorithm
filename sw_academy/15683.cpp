#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
int n,m;
int dy[4] = {-1, 1, 0, 0}; // 2번일 경우 i = 0, 1 / 2, 3
int dx[4] = {0, 0, -1, 1}; // 3번일 경우 i = 1, 2 / 1, 3 / 0, 2 / 0, 3
 // 4번일 경우 0, 1, 2 / 1, 2, 3/ 2, 3, 0;
int map[10][10];
int ans = 100000000;
vector<pair<int, pair<int, int> > > cctv;

void copy(int (*a)[10], int (*b)[10]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = b[i][j];
        }
    }
}

int safe(){
    int cnt=0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            // cout<<map[i][j]<<" ";
            if(map[i][j] == 0) cnt++;
        }
        // cout<<endl;
    }
    return cnt;
}
void spread(int y, int x, int d){
    int ny = y + dy[d];
    int nx = x + dx[d];

    if(ny > -1 && ny < n && nx > -1 && nx < m){
        if(map[ny][nx] != 6){
            if(map[ny][nx] == 0) map[ny][nx] = -1;
            spread(ny, nx, d);
        }
    }
}

void dfs(int depth){
    if(depth >= cctv.size()){
        ans = min(ans, safe());
        return;
    }
    int temp[10][10];
    int num = cctv[depth].first;
    int y = cctv[depth].second.first;
    int x = cctv[depth].second.second;
    if(num == 1){
        for(int i = 0; i < 4; i++){
            copy(temp, map);
            spread(y, x, i);
            dfs(depth+1);
            copy(map, temp);
        }
    }
    if(num == 2){
        for(int i = 0; i < 3; i+= 2){
            copy(temp, map);
            spread(y, x, i);
            spread(y, x, i+1);
            dfs(depth+1);
            copy(map, temp);
        }
        //  2번일 경우 i = 0, 1 / 2, 3
         // 3번일 경우 i = 1, 2 / 1, 3 / 0, 2 / 0, 3
         // 4번일 경우 0, 1, 2 / 1, 2, 3/ 2, 3, 0/ 3, 0, 1/
    }
    if(num == 3){
        for(int i = 0; i < 2; i++)
        {
            for(int j = 2; j < 4; j++){
                copy(temp, map);
                spread(y, x, i);
                spread(y, x, j);
                dfs(depth+1);
                copy(map, temp);
            }
            
        }
    }
    if(num == 4){
        for(int i = 0; i < 4; i++){
            copy(temp, map);
            spread(y,x, i);
            spread(y, x, (i+1)%4);
            spread(y,x, (i+2)%4);
            dfs(depth+1);
            copy(map, temp);
        }
    }
    if(num == 5){
        copy(temp, map);
        for(int i = 0; i < 4; i++){
            spread(y, x, i);
        }
        dfs(depth+1);
        copy(map, temp);
    }
}
int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] > 0 && map[i][j] < 6){
                cctv.push_back(make_pair(map[i][j], make_pair(i,j)));
            }
        }
    }   
    dfs(0);

    printf("%d\n",ans);
}