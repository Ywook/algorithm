#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};
int map[11][11];
int check[4];
int main(){
    int n, t;
    scanf("%d", &t);

    for(int l = 1; l<= t; l++){
        int ans = 0;
        queue<pair<int, int> > q;
        scanf("%d",&n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d",&map[i][j]);
                if(map[i][j] != 0){
                    q.push(make_pair(i,j));
                }
            }
        }

        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            check[map[y][x]]++;
            
            for(int i = 0; i < 8; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                    check[map[ny][nx]]++;
                }
            }
            if(!check[0] && check[1] &&check[2] &&check[3]) {
                ans++; 
            }

            for(int i = 0; i < 4; i++){
                check[i] = 0;
            }
        }
        printf("#%d %d\n", l, ans);

    }
    return 0;
}