#include <iostream>

using namespace std;

int a_num[30];
int b_num[100];
long long sq(int a, int b){
    int ans = 1;
    while(b--){
        ans = ans*a;
    }
    return ans;
}

int main(void){
    int a, b, m;
    long long ans = 0;
    cin >>a>>b;
    cin >>m;

    for(int i = 0; i < m; i++){
        cin>>a_num[i];
    }

    for(int i = m-1; i>=0; i--){
        int t = a_num[i];
        ans += a_num[i]*sq(a,m-i-1);
    }
    int j = 0;
    while(1){
        if(ans < b){
            b_num[j] = ans;
            break;
        }
        b_num[j] = ans%b;
        ans /= b;
        j++;
    }
    for(int i = j; i >=0; i--){
       cout <<b_num[i]<<" ";
    }
    cout <<endl;
}