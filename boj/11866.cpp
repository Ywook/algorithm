#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;
int main(){
    int n,m;

    scanf("%d %d", &n, &m);

    int index = 0;
    v.push_back(0);
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    printf("<");
    int size = v.size();
    while(size > 2){
        index = (index + m)%(v.size()-1);
        if(index == 0){
            printf("%d, ", v[v.size()-1]);
            v.erase(v.begin() + v.size()-1);
            size = v.size();
            continue;
        }
        printf("%d, ",v[index]);
        v.erase(v.begin() + (index));
        index--;
        size = v.size();
    }
    // 1 4 5 7
    //  2 
    printf("%d", v[1]);
    printf(">");
}