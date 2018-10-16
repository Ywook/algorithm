#include<iostream>
#include<cstdio>

using namespace std;
int n;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

char map[52][52];
char color[4] = {'C', 'P', 'Z', 'Y'};
int check(int y, int x, char color){
    int cnt = 1;
    int cnt2 = 1;
    //위, 아래
    int ny, nx;

    //아래
    ny = y + dy[1];
    while(ny < n && map[ny][x] == color){
        cnt++;
        ny += dy[1];
    }

    //위
    ny = y + dy[0];
    while(ny > -1 && map[ny][x] == color){
        cnt++;
        ny += dy[0];
    }
    //왼쪽 오른쪽  

    nx = x + dx[2];
    while(nx > -1 && map[y][nx] == color){
        cnt2++;
        nx += dx[2];
    }

    nx = x + dx[3];
    while(nx < n && map[y][nx] == color){
        cnt2++;
        nx += dx[3];
    }

    return max(cnt, cnt2);

}
int main(){
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%s", map[i]);
    }
    //1번 그냥 하고 최대값
    //2번 바꾸고 최대값

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //그냥 하고 최대값 
            ans = max(ans, check(i, j, map[i][j]));
            //바꾸고 최대값
            for(int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(ny > -1 && ny < n && nx > -1 && nx <=n){
                    swap(map[ny][nx], map[i][j]);
                    ans = max(ans, check(i, j, map[i][j]));
                    swap(map[ny][nx], map[i][j]);
                }
            }
        }
    }
    printf("%d\n", ans);
}