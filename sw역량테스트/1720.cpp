#include<iostream>
#include<cstdio>

using namespace std;

long long d[32];
long long a[32];
int main(){
    int n;
    scanf("%d", &n);

    a[1] = d[1] = 1;
    a[2] = d[2] = 3;

    for(int i =3 i <= n; i++){
        d[i] = d[i-1] + d[i-2]*2;
    }

    for(int i = 3; i <= n; i++){
        long long temp ;
        if(i % 2) temp = d[(i-2)/2];
        else temp = d[(i-2)/2]*2 + d[i/2];
        a[i] = (d[i] + temp)/2;
    }
    printf("%lld\n", a[n]);
    return 0;
}