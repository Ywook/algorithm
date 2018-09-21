#include<iostream>
#include<cstdio>

using namespace std;

int map[32][17];
int visit[32][17];
int n, m, h, a, b;

void copyMap(int (*a)[17], int (*b)[17]){
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = b[i][j];
        }
    }
}
int solve(int index)
{
    int x = index;
    int y = 1;

    while(y <= h){
        if(map[y][x]) x++;
        else if(map[y][x-1]) x--;
        y++;
    }
    if(x == index) return 1;
    else return 0;
}
bool dfs(int row, int cur, int depth){
    int i,j,k;
    if(cur == depth){
        for(i = 1; i <= n; i++){
            if(!solve(i)) return false;
        }
        return true;
    }

    for(i = row; i <= h; i++){
        for(j = 1; j < n; j++){
            if(!map[i][j] && !map[i][j-1] && !map[i][j+1]){
                map[i][j] = 1;
                if(dfs(i,cur+1,depth)) return true;
                map[i][j] = 0;
            }
        }
    }
    return false;

}
int main(){

    scanf("%d %d %d", &n, &m, &h);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);

        map[a][b] = 1;
    }
    for(int i = 0; i < 4; i++){
        if(dfs(0,0,i)){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
}