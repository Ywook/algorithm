#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];
int main(){
    string s1, s2;

    cin>>s1>>s2;
    s1 = "1"+s1;
    s2 = "2"+s2;
    for(int i = 1; i < s2.length(); i++){
        for(int j = 1; j < s1.length(); j++){
            if(s2[i] == s1[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[s2.length()-1][s1.length()-1]<<endl;;
   return 0;
}