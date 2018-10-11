#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> ans;
vector<int> a;
int flag = 0;
void dfs(int num,int sum, int depth){
    if(flag) return;
    
    if(depth > 7 || sum > 100) return;
    
    if(depth == 7 && sum + a[num] == 100){
        flag = 1;
        ans.push_back(a[num]);
        return;
    }
    for(int i = num +1; i <= 9; i++){
        dfs(i, sum + a[num], depth+1);
        if(flag){
            ans.push_back(a[num]);
            return;
        }
    }
}
int main(){
    a.push_back(0);
    for(int i = 0; i < 9; i++){
        int t;
        scanf("%d",&t);
        a.push_back(t);
    }
    sort(a.begin(), a.end());

    for(int i = 1; i < 4; i++){
        dfs(i,0, 1);
    }


    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}

/*
73
1
2
3
4
5
6
7
8
*/