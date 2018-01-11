#include <iostream>

using namespace std;

long long d[204][204];

int main(void){
    int n, k;
 
    cin >> n;
    cin >> k;
    d[0][0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int l = 0; l <= j; l++){
                d[j][i] += d[j-l][i-1];
                d[j][i] %= 1000000000;
            }
        }
    }

    cout<<d[n][k] << endl;
}