#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector<int> v;
int a[100004];
int b[100004];

int dfs(int i, int cnt,int j){
    if(a[i] != 0){
        if(b[i] != j){
            return 0;
        }
        return cnt-a[i];
    }    
    a[i] = cnt;
    b[i] = j;
    return dfs(v[i], ++cnt, j);
}

int main(void){
    int t, n;
    int ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        v.push_back(0);
        ans = 0;
        for(int i = 1; i <= n; i++){
            int c;
            scanf("%d", &c);
            v.push_back(c);
            a[i] = 0; b[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            if(a[i] == 0){
                ans += dfs(i, 1,i);
            }
        }
        cout<<n-ans<<endl;
        v.clear();
    }
}