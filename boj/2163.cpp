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

//연산자의 기호는 ＠으로, A＠B = (A+B)×(A-B)으로 정의내리기로 했다.
