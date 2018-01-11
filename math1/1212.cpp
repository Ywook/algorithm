#include <iostream>
#include <string>
using namespace std;
string str[8] = {"000","001","010","011","100","101","110","111"};

int main(void){
    string s;
    int len;
    cin >> s;
    bool st = true;
    len = s.size();
    if(len == 1  && s[0] -'0' == 0) cout <<"0";

    for(int i = 0; i < len; i++){
        int t = s[i] - '0';
        if(st && t < 4){
            if(t==0) continue;
            else if(t==1) cout <<"1";
            else if(t==2) cout <<"10";
            else if(t==3) cout <<"11";
            st = false;
        }else{
            cout<<str[t];
            st = false;
        }
    }
}