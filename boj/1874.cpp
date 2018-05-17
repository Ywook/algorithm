#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> stack;

int main(){
    int n;
    scanf("%d", &n);
    int top = 0;
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);

        if(t > top){
            for(int j = top +1; j <= t; j++){
                stack.push_back(j);
            }
            top = t;
        }


    }
}