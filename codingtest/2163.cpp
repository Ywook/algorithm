#include <iostream>
#include <cstdio>
using namespace std;

int n,m;
int main(){
    int ans = 0;
    scanf("%d %d", &n, &m);
    ans = n*m-1;
    cout<<ans<<endl;
    return 0;
}