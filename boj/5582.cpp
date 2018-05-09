#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[4002][4002];

int main(){

    string s, t;

    cin>> s>>t;
    s = "0" + s;
    t = "0" + t;
//i~j까지 문자열 일치 개수 합
    int ans  = 0;
//0부터 j까지~ 만약에 일치하면 ? dp[i][j] = dp[i][j-1] + 1;
    int l1 = s.size();
    int l2 = t.size();
    for(int i = 1; i < l1; i++){
        for(int j = 1; j < l2; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}