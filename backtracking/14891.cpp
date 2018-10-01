#include<iostream>
#include<cstdio>

using namespace std;

int a[4][8];

int k;

void rot_clock(int n){
    int tmp;
    tmp = a[n][0];
    a[n][0] = a[n][7];
    a[n][7] = a[n][6];
    a[n][6] = a[n][5];
    a[n][5] = a[n][4];
    a[n][4] = a[n][3];
    a[n][3] = a[n][2];
    a[n][2] = a[n][1];
    a[n][1] = tmp;
}

void rot_reclock(int n){
    int tmp;
    tmp = a[n][0];
    a[n][0] = a[n][1];
    a[n][1] = a[n][2];
    a[n][2] = a[n][3];
    a[n][3] = a[n][4];
    a[n][4] = a[n][5];
    a[n][5] = a[n][6];
    a[n][6] = a[n][7];
    a[n][7] = tmp;
}

void spin(int n, int dir){

}

int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    scanf("%d", &k);

//1번과 2번
//2, 6
//2번과 3번
//2, 6
//3번과 4번
//2, 6
    while(k--){
        int n, dir;
        scanf("%d %d", &n, &dir);
        spin(n, dir);
    }
}