#include<iostream>
#include<cstdio>
using namespace std;

int d[1004];
int a[1004];
int main(){
    int n;
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        d[i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if (a[i] > a[j] && d[j] +1 > d[i])
            {
                d[i] = d[j] + 1;
            }
        }
        ans = max(ans,d[i]);
    }
    cout<<ans<<endl;
}