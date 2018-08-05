#include<iostream>
#include<cstdio>

using namespace std;

int a[1002][1002];
int d[1002][1002];
int main(){
    int n,m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0){
                d[i][j] = a[i][j];
                ans = max(d[i][j], ans);
            }else if(a[i][j] == 1){
                d[i][j] = min(min(d[i - 1][j - 1], d[i - 1][j]), d[i][j - 1]) + 1;
                ans = max(d[i][j], ans);
            }
        }
    
    }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         printf("%d", d[i][j]);
    //     }
    //     cout<<endl;
    // }

    printf("%d\n", ans*ans);
} 