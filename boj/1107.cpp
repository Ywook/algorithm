#include<iostream>
#include<cstdio>

int a[12];

int check(int x){
    if(x == 0){
        return a[x] ? 0 : 1;
    }
    int len = 0;
    while(x > 0){
        if(a[x%10]) return 0;
        len++;
        x/=10;
    }
    return len;
}
int main(){
    int n, m, x;
    int ans = 1000000;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int t;
        scanf("%d", &t);
        a[t] = 1;
    }
    ans = (n - 100 > 0) ? n - 100 : 100 - n;
    for(int i = 0; i <= 1000000; i++){
        int temp, len, temp2;
        x = i;

        len = check(x);
        if(!len) continue;
        temp2 =(n - x > 0) ? n - x + len : x -n + len;
        ans = ans > temp2 ? temp2 : ans;
    }
    printf("%d\n", ans );

}