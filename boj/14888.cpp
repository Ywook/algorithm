#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[102];
int op[4];
int n;

int ans_max = -1000000000;
int ans_min = 1000000000;

void dfs(int sum, int depth){
    if(depth == n+1){
        ans_max = max(sum, ans_max);
        ans_min = min(sum, ans_min);
        return;
    }

    if(op[0] > 0){
        op[0]--;
        dfs(sum + a[depth], depth+1);
        op[0]++;
    }
    if (op[1] > 0){
        op[1]--;
        dfs(sum - a[depth], depth + 1);
        op[1]++;
    }
    if (op[2] > 0){
        op[2]--;
        dfs(sum * a[depth], depth + 1);
        op[2]++;
    }
    if (op[3] > 0){
        op[3]--;
        dfs(int(sum / a[depth]), depth + 1);
        op[3]++;
    }
}
int main(){
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < 4; i++){
        scanf("%d", &op[i]);
    }

    dfs(a[1],2);
    cout<<ans_max<<endl;
    cout<<ans_min<< endl;
    return 0;
}