#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n, m, x , y, k;
int map[21][21];
vector<int> a;

int dice[6] = {0};

int dx[5] = {0,1, -1, 0, 0};
int dy[5] = {0,0, 0, -1, 1};
int main(){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
        }
    }

    map[x][y] = 0;
    for(int i = 0; i < k; i++){
        int t; 
        scanf("%d", &t);
        a.push_back(t);
    }

    for (int d : a)
    {
        int nx = x + dy[d];
        int ny = y + dx[d];
        int t;
        if(nx < 0 || ny < 0|| nx >= n || ny >=m) {
            continue;

        }
        if (d == 1)
        {
            t = dice[5];
            dice[5] = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[3];
            dice[3] = t;
        }
        else if (d == 2)
        {
            t = dice[4];
            dice[4] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[3];
            dice[3] = t;
        }
        else if (d == 3)
        {
            t = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[3];
            dice[3] = t;
        }
        else
        {
            t = dice[3];
            dice[3] = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[0];
            dice[0] = t;
        }

        if(map[nx][ny] == 0){
            map[nx][ny] = dice[3];
        }else{
            dice[3] = map[nx][ny];
            map[nx][ny] = 0;
        }
        cout<<dice[1]<<endl;
        x = nx;
        y = ny;
    }
}
/*
0 2
3 4
5 6
7 8
0
  0
4 1 5
  2
  3
아래쪽으로 돌리면
d[3] = d[2], d[2] = d[1], d[1] = d[0], d[0] = d[3]
위쪽으로 돌리면 
d[0] = d[1], d[1] = d[2], d[2] = d[3], d[3] = d[0]
왼쪽으로 돌리면 d[4] = d[1], d[1] = d[5], d[5] = d[3] d[3] = d[4]
d[5] = d[1] , d[1] = d[4] , d[4] = d[3], d[3] =d[5]
오른쪽으로 돌리면 d[3] = d[5] d[1] = d[4] d[5] = d[1] d[4] = d[3] 이 때 밑면이 되는것은 
*/
