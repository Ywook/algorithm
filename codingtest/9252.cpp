#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char ans[1002];
int dp[1002][1002];
int main(){
    string s1,s2;

    cin>>s1>>s2;

    s1 = "0" + s1;
    s2 = "0" + s2;
    int s2_len = s2.length();
    int s1_len = s1.length();

    int i, j;
    for(i = 1; i < s2_len; i++){
        for(j = 1; j < s1_len; j++){
            if(s2[i] == s1[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int k = dp[s2_len-1][s1_len-1];
    i = s2_len-1;
    j = s1_len-1;
    while(i > 0 && j > 0){
        if (s1[j] == s2[i])
        {
            ans[k] = s2[i];
            k--;
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] == dp[i][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    k = dp[s2_len - 1][s1_len - 1];
    cout <<k<< endl;

    for(int i =1 ; i <= k; i++){
        printf("%c", ans[i]);
    }
    cout<<endl;
}