#include<iostream>
#include<cstdio>

using namespace std;

int ans = 0;
int weight = 3000;
int content[5] = {2500, 500, 1500, 2000, 1000};

void dfs(int cnt, int sum){
    if(cnt > sizeof(content)/4){
        return;
    }

    if(sum == weight){
        ans++;
        return;
    }

    dfs(cnt+1, sum + content[cnt]); //선택하는경우
    dfs(cnt+1, sum); //안선택경우
}
int main(){
    dfs(0, 0);
    cout<<ans<<endl;
    return 0;
}