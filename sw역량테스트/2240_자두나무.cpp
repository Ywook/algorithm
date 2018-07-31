#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1002];
int d[1002][32];
int t, w;

int solve(int i, int j){
    if(i > t ) return 0;
    if(j > w) return 0;
    if(d[i][j] != -1) return d[i][j];

    int pos = j%2+1;
    d[i][j] = max(solve(i+1, j), solve(i+1,j+1)) + (pos == a[i] ? 1:0);
    return d[i][j];
}
int main(){
    scanf("%d %d", &t, &w);

    for(int i = 1; i <= t; i++) scanf("%d", &a[i]);
    memset(d, -1, sizeof(d));
    printf("%d\n", max(solve(0, 0), solve(0, 1)));
    return 0;
}