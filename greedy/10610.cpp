#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    string str;
    int n = 0;

    cin >> str;

    for(char c : str){
        n += c-'0';
    }
    sort(str.begin(), str.end());
    if(n%3 == 0 && str[0] == '0'){
        reverse(str.begin(), str.end());
        cout <<str<<endl;
    }else{
        cout << "-1"<<endl;
    }
}