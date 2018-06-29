#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<char> alpha;

int check(string s){
    int m = 0;
    int j = 0;
    for(char a : s){
        if(a == 'a' || a== 'i'|| a == 'e' || a =='o' || a=='u'){
            m++;
        }else{
            j++;
        }
    }
    return (m >= 1 && j >1) ? 1 : 0;
}
void go(int l, string str, int num){
    
    if(l == str.size()) {
        if(check(str)){
            printf("%s\n", str.c_str());
        }
        return;
    }
    if (num >= alpha.size())
    {
        return;
    }
    go(l, str + alpha[num], num+1);
    go(l, str, num+1);
}

int main(){
    int l, c;
    scanf("%d %d", &l, &c);

   for(int i = 0; i < c; i++){
       char c;
       scanf(" %c", &c);
       alpha.push_back(c);
   }
   cout<<alpha[6]<<endl;
   string s ="";
   sort(alpha.begin(), alpha.end());
    go(l, s, 0);
}