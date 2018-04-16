#include <iostream>
#include <cstdio>

using namespace std;
int n;
int arr[17][2];
int ans = 0;
void dfs(int index, int sum){
    for(int i = index ; i <= n; i++){
        if(i + arr[i][0] <= n+1)
        {
            ans = max(sum+arr[i][1], ans);
            dfs(i + arr[i][0],sum + arr[i][1]);
        }
    }
}
int main(){
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for(int i = 1; i <= n; i++){
        if(i + arr[i][0] <= n+1){
            ans = max(ans, arr[i][1]);
            dfs(i + arr[i][0], arr[i][1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
