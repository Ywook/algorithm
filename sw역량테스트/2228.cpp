#include<iostream>
#include<cstdio>

using namespace std;

int a[102];
int d[102][102]; // d[i][j] = a[1]~a[i] 까지 수가 있을 때 j개의 구간으로 나누고 구간에 속한 수들의 총 합 최대
int main(){
    int n,m;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    
    //m개의 구간으로 나누어야 한다.
    /*
        1. 구간에 포함 X (i번째 수) d[i-1][j]
        2. 구간에 포함 O (i번째 수) d[k-2][j-1]
    */
}