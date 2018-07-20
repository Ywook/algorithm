#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char book[10002];
int main(){
    int t;
    int n, s, j, k;

    scanf("%d", &t);

    for(int l = 1; l <= t; l++){
        int ans = 0;
        scanf("%d %d %d %d", &n, &s, &j ,&k);

        for(int i  = 0; i < k; i++){
            int page;
            scanf("%d", &page);
            book[page] = 1;
        }
        j++;
        for(int i = s; i <= n; i += j){
                if(book[i]) {
                    ans++;
                }
            }
        memset(book, 0, sizeof(book));
        printf("#%d %d\n", l, ans);
    }
}