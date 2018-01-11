#include <iostream>
#include <cmath>
using namespace std;

long d[10004];

long next(int a, int p){
    long ans = 0;

    while(a>0){
        ans+=pow(a%10,p);
        a/=10;
    }
    return ans;
}

int check(int n){
    for(int i = 1; i < n; i++){
        if(d[i] == d[n]){
            return --i;
        }
    }
    return -1;
}
int solve(int p){
    int i = 2;
    int ans = -1;
    while(1){
        d[i] = next(d[i-1], p);
        ans = check(i);
        if(ans != -1) break;
        i++;
    }
    return ans;
}
int main(void){
    int a, p;
    
    cin >> a;
    cin >> p;

    d[1] = a;

    cout <<solve(p)<<endl;
}