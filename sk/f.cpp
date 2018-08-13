#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int a[1000002];

int main()
{
    int n1, q1, q2, i, j, type, n, m, s, e, l;
    long long ans = 0;

    scanf("%d %d %d", &n1, &q1, &q2);
    for( i = 1; i <= n1; i++){
        scanf("%d", &a[i]);
    }
    v[0] = 0;
    for( i = 0; i < q1 + q2 ; i++){
        scanf("%d" ,&type);
        ans = 0;
        if(type == 1){
            scanf("%d %d", &n, &m);
            for(j = n; j <=m; j++){
                if(a[j] < 0) continue;
                ans += a[j];
            }
            printf("%lld\n", ans);
        }else{
            scanf("%d %d %d", &s, &e, &l);
            for(j = s; j <= e; j++){
                a[j] += l;
            }
        }
    }
    return 0;
}