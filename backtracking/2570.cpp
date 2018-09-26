#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, 1, -1, -1};

int map[102][102];

void dfs(){

}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int y, x;
        scanf("%d %d", &y, &x);
        map[y][x] = 1;
    }

    

}