#include<iostream>
#include<cstdio>

using namespace std;

int d[101];
int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        int ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            d[i] = 1;
        }

        for(int i = 2; i <= n; i++){
            for(int j = i; j <= n; j+=i){
                d[j] = d[j]*-1;
            }
        }
        for(int i = 1; i <= n; i++){
            if(d[i] == 1){
                ans += 1;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}