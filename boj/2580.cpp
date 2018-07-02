#include<iostream>
#include<cstdio>

using namespace std;
int map[10][10];
int c[10][10];
int c2[10][10];
int c3[10][10];

void solve(int n){
    if(n == 81){
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", map[i][j]);
            }
            cout<<endl;
        }
        exit(0);
    }
    int x = n%9;
    int y = n/9;
    if(map[y][x]!=0){
        solve(n+1);
    }else{
        for(int i = 1; i <= 9; i++){
            if(c[y][i] == 0 && c2[x][i] == 0 && c3[(y/3)*3 + x/3][i] == 0){
                c[y][i] = 1;
                c2[x][i] = 1;
                c3[(y/3)*3 + x/3][i] = 1;
                map[y][x] = i;
                solve(n+1);
                c[y][i] = 0;
                c2[x][i] = 0;
                c3[(y / 3) * 3 + x / 3][i] = 0;
                map[y][x] = 0;
            }
        }
    }
}
int main(){
    for(int i = 0 ; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] != 0){
                c[i][map[i][j]] = 1;
                c2[j][map[i][j]] = 1;
                c3[(i/3)*3 + j/3][map[i][j]] = 1;
            }
        }
    }
    solve(0);
    // cout<<endl;
    // for (int i = 1; i < 10; i++)
    // {
    //     for (int j = 1; j < 10; j++)
    //     {
    //         printf("%d ", map[i][j]);
    //     }
    //     cout<<endl;
    // }
}