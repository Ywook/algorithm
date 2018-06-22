#include<iostream>
#include<cstdio>

using namespace std;

int map[5002][5002];
int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);
            map[y][x] = 1;
        }
    }
}
1 0 2 0 0 0 0 0 0 0 3