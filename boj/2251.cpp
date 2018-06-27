#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;


int check[202][202];
int ans[202];
queue<pair<int, int>> q;

void water_check(int nx, int ny, int nz){
    if (!check[nx][ny])
    {
        q.push(make_pair(nx, ny));
        check[nx][ny] = 1;
        if (!nx)
        {
            ans[nz] = 1;
        }
    }
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int sum = c;
    q.push(make_pair(0,0)); ans[c] = 1; check[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first; int y = q.front().second; q.pop();
        int z = sum - x - y;

        int ny = y;
        int nx = x;
        int nz = z;
        // x->y
        ny += nx; nx = 0;

        if(ny > b){
            nx = ny-b;
            ny = b;
        }
        water_check(nx,ny, nz);

        // x -> z
        nx = x; ny = y; nz = z;
        nz += nx; nx = 0;
        if(nz > z){
            nx = nz - z;
            nz = z;
        }
        water_check(nx,ny, nz);

        // y -> x
        nx = x;
        ny = y;
        nz = z;

        nx += ny; ny = 0;
        if(nx > a){
            ny = nx - a;
            nx = a;
        }
        water_check(nx,ny, nz);
        //y -> z
        nx = x;
        ny = y;
        nz = z;

        nz += ny; ny = 0;
        if(nz > c){
            ny = nz - c;
            nz = c;
        }
        water_check(nx,ny, nz);

        // z -> x
        nx = x;
        ny = y;
        nz = z;

        nx += nz; nz = 0;
        if(nx > a){
            nz = nx - a;
            nx = a;
        }
        water_check(nx,ny,nz);

        //z ->y
        nx = x;
        ny = y;
        nz = z;

        ny += nz; nz = 0;
        if(ny > b){
            nz = ny-b;
            ny =b;
        }
        water_check(nx,ny,nz);
    }
    for(int i = 0; i < 201; i++){
        if(ans[i]){
            printf("%d ", i);
        }
    }
    //처음에 C는 A가 가득 찰때까지 물을 넣거나, B가 가득 찰때까지 물을 넣는 방법이있다.
    //마지막의 경우에는 반드시 A가 비어 있어야한다.


}