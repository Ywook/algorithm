#include<iostream>
#include<cstdio>

using namespace std;

int n, s, ans;
int a[22];

void solve(int k, int sum){
    if (k == n){
        if(sum == s){
            ans++;
        }
        return;
    }
    
    solve(k+1, sum);
    solve(k+1, sum + a[k]);
}
int main(){
    

    scanf("%d %d", &n, &s);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    solve(0, 0);
    ans = (s == 0)? ans -1 : ans;
    cout<<ans<<endl;
}