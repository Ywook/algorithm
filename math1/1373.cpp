#include <iostream>
#include <string>

using namespace std;

int main(void){
    int len;
    string str;

    cin >> str;

    len = str.size();
    if(len%3 == 1){
        cout<<str[0];
    }else if(len%3 == 2){
        cout<<(str[0]-'0')*2 + str[0]-'0'; 
    }


    for(int i = len%3; i < len; i+=3){
        cout << (str[i]-'0')*4 + (str[i+1]-'0')*2 + (str[i+2]-'0');
    }
}   