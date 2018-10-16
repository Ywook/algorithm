#include<iostream>
#include<cstdio>

using namespace std;

int n;
long long a[102];
int operator_cnt[5];

long long ans_max = -1000000002;
long long ans_min = 1000000002;

void solve(int depth, long long res){
    if(depth == n){
        ans_max = max(ans_max, res);
        ans_min = min(ans_min, res);
        return;
    }
    //1은 덧셈, 2는 뺄셈, 3은 곱셈, 4는 나눗셈
    if(operator_cnt[1] > 0){
        operator_cnt[1]--;
        solve(depth+1, res + a[depth]);
        operator_cnt[1]++;
    }

    if(operator_cnt[2] > 0){
        operator_cnt[2]--;
        solve(depth+1, res - a[depth]);
        operator_cnt[2]++;
    }

    if(operator_cnt[3] > 0){
        operator_cnt[3]--;
        solve(depth+1, res * a[depth]);
        operator_cnt[3]++;
    }
    if(operator_cnt[4] > 0){
        operator_cnt[4]--;
        solve(depth+1, res / a[depth]);
        operator_cnt[4]++;
    }
    return;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i < 5; i++){
        int temp;
        scanf("%d", &temp);
        operator_cnt[i] = temp;
    }

    solve(1, a[0]);
    printf("%lld\n", ans_max);
    printf("%lld\n", ans_min);
}