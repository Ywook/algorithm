#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> stack;
vector<char> ans;
int main(){
    int n;
    scanf("%d", &n);
    int top = 0;
    int flag = 1;
    int last = 0;
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);

        if(t > top){
            for(int j = top + 1; j <= t; j++){
                if(last < j){
                    stack.push_back(j);
                    ans.push_back('+');
                }
            }
            top = t;
            last = max(last, top);
        }
        if(t == top){
            ans.push_back('-');
            stack.pop_back();
            top = stack.back();
        }else if(t < top){
            flag = 0;
        }
    }

    if(!flag){
        printf("NO\n");
    }else{
        for (char a : ans)
        {
            printf("%c\n", a);
        }
    }
}