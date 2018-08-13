#include<iostream>
#include<cstdio>

using namespace std;

int ans = 5000;
int coin[25];
int n;
void solve(int pos){
    if(pos == n){
        int sum = 0;
        for(int i = 1; i < (1<<n); i *=2){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(!(coin[j] & i)){
                    cnt++;
                }
            }
            if(n - cnt > cnt) sum += cnt;
            else sum += n - cnt;
        }
        ans = min(sum, ans);
        return;
    }
    coin[pos] = ~coin[pos];
    solve(pos + 1);
    coin[pos] = ~coin[pos];
    solve(pos + 1);
}
int main(){
    char c;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        getchar();
        for(int j = 1<<(n - 1); j > 0; j/=2){
            scanf("%c", &c);
            if(c == 'H'){
                coin[i] |= j;
            }
        }
    }

    solve(0);
    printf("%d\n", ans);
}