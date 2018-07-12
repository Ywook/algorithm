#include<iostream>
#include<cstdio>

using namespace std;

int d[1000002];
int main(){
    int n;
    scanf("%d", &n);

    d[1] = 0;
    d[2] = 1;

    for(int i = 3; i <= n; i++){
        d[i] = d[i-1] + 1;
        if(i%3 == 0){
            d[i] = min(d[i], d[i/3] + 1);
        }
        if(i%2 == 0){
            d[i] = min(d[i], d[i/2] + 1);
        }
    }
    printf("%d\n", d[n]);

    return 0;
}