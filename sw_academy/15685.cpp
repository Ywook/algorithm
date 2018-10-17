#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
int n;
int map[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void print_map(){
    cout<<endl;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    scanf("%d", &n);
    vector<pair<int, pair<int, int> > >v;
    for(int i = 0; i < n; i++){
        int x, y, d, g, ny, nx;

        scanf("%d %d %d %d", &x, &y, &d, &g);
        //끝점을 기준으로 90도입니다.
        map[y][x] = 1;
        ny = y + dy[d];
        nx = x + dx[d];
        map[ny][nx] = 1;
        v.push_back(make_pair((d+1)%4, make_pair(ny, nx)));
        
        for(int j = 0; j < g; j++){
            int size = v.size();
            for(int k = size -1; k >= 0; k--){
                d = v[k].first;
                
                ny = ny + dy[d];
                nx = nx + dx[d];
                map[ny][nx] = 1;
                v.push_back(make_pair((d+1)%4, make_pair(ny,nx)));
            }
        }
        v.clear();
    }
    int ans = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] &&map[i+1][j+1]){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}