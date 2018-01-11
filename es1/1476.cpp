#include<iostream>

using namespace std;

int main(void){
    int a, b, c;
    int e, s, m;
    int ans = 1;
    cin >> e >> s>> m;

    a = b = c = 1;

    while(e != a || s != b || m != c){
        if(a%15 == 0){
            a = 0 ;
        }

        if(b%28 == 0){
            b = 0;
        }
        if(c%19 == 0){
            c = 0;
        }
        a++; b++; c++;        
        ans ++;
    }
    cout<<ans<<endl;
}