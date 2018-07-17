#include<iostream>
#include<cstdio>

using namespace std;

int c[2502][2502];
int d[2502];
string s;

int solve(int i, int j){
    if(i==j){
        return 1;
    }else if(i+1 == j){
        if(s[i] == s[j]){
            return 1;
        }else{
            return 2;
        }
    }

    if(c[i][j] > 0){
        return c[i][j];
    }
    if(s[i] == s[j]){
        return c[i][j] = solve(i+1, j-1);
    }else{
        return c[i][j] = 2;
    }

}
int main(){
    cin>>s;
    s = "0" + s;
    //d[i] = s의 i번째 문자열까지의 팰린드롬 분할 개수의 최솟값
    //d[i] = min(d[j-1]) + 1
    int n = s.size() -1;
    for(int i =1 ; i <= n ; i++){
        d[i] = -1;
        for(int j = 1; j <= i; j++){
            if(solve(j,i) == 1){
                if(d[i] == -1 || d[i] > d[j-1] + 1){
                    d[i] = d[j-1]+1;
                }
            }
        }
    }
    cout<<d[n]<<endl;
}