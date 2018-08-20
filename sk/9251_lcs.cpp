#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int d[1002][1002];
int main(){
    std::ios_base::sync_with_stdio(false);
    int i,j;
    string s1, s2;

    cin>>s1>>s2;

    s1 = "1" + s1;
    s2 = "2" + s2;

    for(i = 1; i < s1.size(); i++){
        for(j = 1; j < s2.size(); j++){
            if(s1[i] == s2[j]){
                d[i][j] = d[i-1][j-1] + 1;
            }else{
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    for(i = 0; i < s1.size(); i++){
        for(j = 0; j < s2.size(); j++){
            cout<<" "<<d[i][j];
        }
        cout<<endl;
    }
    cout<<d[s1.size()-1][s2.size()-1]<<"\n";
    return 0;

}