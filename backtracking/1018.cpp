#include<iostream>
#include<cstdio>

using namespace std;
int n, m;
char map[52][52];

int solve(int y , int x){
    int cnt = 0;
    int cnt2 = 0;

    char init = map[y][x];
    char next;

    if(init == 'W') {next = 'B';}
    else next = 'W';
    // init = b, change = w;
    // init 을 w로 변경
    for(int i = y; i < y+8; i++){
        for(int j = x; j < x+8; j++){
            if(i == 0 && j == 0 ){
                if(map[i][j] != next) cnt2++;
                continue;
            }
            if(map[i][j] != next) cnt++;
            if(map[i][j] != init) cnt2++;
            swap(next, init);
        }
        swap(next,init);
    }

    return min(cnt, cnt2);
}
int main(){
    scanf("%d %d", &m, &n);
    int ans = 100;
    for(int i = 0; i < m; i++){
        scanf("%s", map[i]);
    }

    for(int i = 0; i + 8 <= m; i++){
        for(int j = 0; j + 8<=n;j++){
            ans = min(ans,solve(i,j));
        }
    }
    printf("%d\n" ,ans);
}