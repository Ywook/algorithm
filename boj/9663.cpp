#include<iostream>
#include<cstdio>

using namespace std;
int ans = 0;
int map[17][17];

int check(int row, int col, int n){
    //상
    int i, j;
    i = row; j = col;
    while(i+1 <= n){
        i += 1;
        if(map[i][j]) return 0;
    }
    //하
    i = row; j = col;
    while (i-1 > 0 && j > 0)
    {
        i -= 1;
        if (map[i][j]) return 0;
    }
    //좌
    i = row; j = col;
    while(j -1 > 0){
        j-=1;
        if(map[i][j]) return 0;
    }

    //우
    i = row; j = col;
    while(j+ 1 <= n){
        j+=1;
        if(map[i][j]) return 0;
    }
    //왼위 대각
    i = row+1 ; j = col-1;
    while(i <= n && j > 0){
        if(map[i][j]) return 0;
        i+=1;
        j-=1;
    }
    //오위 대각
    i = row+1; j = col+1;
    while(i <= n && j <= n){
        if(map[i][j]) return 0;
        i+=1; j+=1;
    }
    //왼아래 대각
    i = row-1; j = col -1;
    while(i > 0 && j > 0){
        if(map[i][j]) return 0;
        i-=1; j-=1;
    }
    //오아래 대각
    i = row-1; j = col + 1;
    while(i > 0 && j <= n){
        if(map[i][j]) return 0;
        i-=1; j+=1;
    }
    return 1;
}
void backtracking(int row, int n){
    if(row == n+1){
        ans +=1;
        return;
    }

    for(int i = 1; i <= n; i++){
        if(check(row, i, n)){
            map[row][i] = 1;
            backtracking(row+1, n);
            map[row][i] = 0;
        }
    }
}
int main(){
    int n;

    scanf("%d", &n);

    backtracking(1, n);
    cout<<ans<<endl;
}