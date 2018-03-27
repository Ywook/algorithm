#include <iostream>
#include <cstdio>

using namespace std;

int money = 1000;
int n_500, n_100, n_50, n_10, n_5, n_1;
int ans;
void cal( int n){
    int k;
    k = money/n;
    money -= n*k;
    ans += k;
}
int main(){
    int m;

    scanf("%d", &m);

    money -= m;
    cal(500);
    cal(100);
    cal(50);
    cal(10);
    cal(5);
    cal(1);

    cout<<ans<<endl;
    return 0;
}