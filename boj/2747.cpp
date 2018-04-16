#include <iostream>
#include <cstdio>

using namespace std;
int a[46];

int main(){
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    int n;
    scanf("%d", &n);
    for(int i =3 ; i <= n; i++){
        a[i] = a[i-1] + a[i-2];
    }
    cout<<a[n]<<endl;
    return 0;
}