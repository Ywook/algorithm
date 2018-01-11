#include <iostream>

using namespace std;

int main(void){
    int n,m,k;

    cin>>n>>m>>k;
    int team = 0;
    for(int i = 0; i <= k; i++){
        int cnt = 0;
        int j = k-i;

        int t_n = n-i;
        int t_m = m-j;

        for(int k = 1; k <= t_m; k++){
            if(t_n-2 >= 0) t_n-=2;
            else break;
            cnt++;
        }

        team = max(cnt,team);
    }
    cout <<team<<endl;
}