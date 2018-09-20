#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

string str = "";

int n;
bool check = false;

void backtracking(char c, int len){
    if(len == n){
        check = true;
        cout<<str<<endl;
        return;
    }

    str+=c;
    int loop = str.size()/2;
    int l, r;
    l = str.size() - 1;
    for(int i = 1; i <= loop; i++){
        string a = str.substr(l, i);
        string b = str.substr(l - i, i);

        if(a.compare(b) == 0){
            str.erase(len);
            return;
        }
        l -= 1;
    }

    for(int i = 1; i < 4; i++){
        if(!check) backtracking(i + '0', len+1);
    }
    str.erase(len);
}

int main(){
    scanf("%d",&n);

    for(int i = 1; i < 4; i++){
        backtracking(i + '0', 0);
    }    

    return 0;

}