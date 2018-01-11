#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> v;
int check[52][52];
int dx[8] = {-1, 1, 1, -1, 1, -1, 0, 0};
int dy[8] = {1, 1, -1, -1, 0, 0, 1, -1};
int w,h;
int dfs(int x, int y){
    check[x][y] = 1;

    for(int i = 0; i < 8; i++){
        int ax = x + dx[i];
        int ay = y + dy[i];

        if(0<= ax && ax < h && 0 <= ay && ay < w){
            if(check[ax][ay] == 0 && v[ax][ay] == 1){
                dfs(ax,ay);
            }
        }
    }
    return 1;
}

int main(void){
    int t, ans;
    while(true){
        ans = 0;
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0)
            break;

        for(int i = 0; i < h; i++){
            v.push_back(vector<int>());
            for(int j = 0; j < w ; j++){               
                int temp;
                scanf("%d", &temp);
                v[i].push_back(temp);
                check[i][j] = 0;
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(check[i][j] == 0 && v[i][j] == 1){
                    ans += dfs(i,j);
                }
            }
        }
        cout << ans << endl;
        v.clear();
    }
}