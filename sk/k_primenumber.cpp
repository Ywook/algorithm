#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int primenumber(int *dp, int k){
    if(dp[k]) return dp[k];
    else{
        int n, flag;
        if(!dp[k-1]){
            dp[k-1] = primenumber(dp, k-1);
        }
        n = dp[k-1];
        flag = 1;

        while(flag){
            n++; flag = 0;

            for(int i = 1; i <= sqrt(k); i++){
                if(!(n % dp[i])){
                    flag = 1;
                    break;
                }
            }
        }
        return n;
        //n은 k-1번째 소수이다. 그리고 나는 k번째 소수를 찾아야한다.
        

    }
    

}

int main(){
    int k,flag;
    int ans = 0;
    scanf("%d", &k);

    int* dp = new int[k+2];
    memset(dp, 0, sizeof(int) * (k+2));
    dp[1] = 2;
    printf("%d\n",primenumber(dp, k));
}