#include <iostream>
#include <cstdio>
using namespace std;
int a[1004];
bool check[1004];
int ans = 0;

int dfs(int x, int s){
    if(check[a[x]] == true && a[x] != s) return 0;
    if(check[a[x]] == true && a[x] == s) return 1;
    check[x] = true;
    if(dfs(a[x], s) == 0) return 0;
    return 1;
}

int main(){
    int t, n;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        ans = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }

        for(int i = 1; i <= n; i++){
            if(check[i] == false){
                ans += dfs(i, i);
            }
        }
        cout << ans << endl;

        for (int i = 1; i <= n; i++)
        {
            check[i] = false;
            a[i] = 0;
        }
    }
}