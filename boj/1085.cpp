#include <iostream>
#include <cstdio>

using namespace std;
int ans;
int main(){
    int x,y,w,h;
    ans = w;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    ans= min(w-x, ans);
    ans= min(h-y,ans);
    ans= min(ans, x);
    ans= min(ans, y);
    cout<<ans<<endl;
}