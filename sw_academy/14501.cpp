#include<iostream>
#include<cstdio>

using namespace std;
int n;
int a[17][2];
//0은 걸리는 일 수 1은 머니
int ans = 0;
void dfs(int index, int sum){
    ans = max(ans, sum);
    for(int i = index; i <= n; i++){
        if(i + a[i][0] <= n+1){
            dfs(i + a[i][0], sum + a[i][1]);
        }
    }
}
int main(){
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a[i][0], &a[i][1]); 
    }
    
    for(int i = 1; i <= n; i++){
        if(i + a[i][0]<=n+1){
            dfs(i + a[i][0], a[i][1]);
        }
    }
    printf("%d\n",ans);
}