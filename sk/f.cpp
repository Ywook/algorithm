#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int diff[10003][3], diff_cnt;
long long v[1000002];

void solve(int n, int m){
    int i, start, end;
    long long left = v[n-1], right = v[m], l;
    // printf("v[m] : %lld\n", right);
    for(i = 0; i < diff_cnt; i++){
        start = diff[i][0], end = diff[i][1], l = diff[i][2];
        // printf("l : %lld\n", l);

        if(start <= n-1){ //left에 더해줘야 하는 경우
            if(end <= n-1){
                left += (end - start +1) *l;
            }else{
                left += (n-1 - start +1)*l;
            }
            // printf("left : %lld\n", left);
        } //start =  1이다.
        if(start <= m){ //right에 더해줘야 하는 경우
            if(end <= m){ // end =  6 start = 1 m = 6 6*-4 = -24
                right += (end - start +1)*l;
            }else{
                right += (m - start + 1)*l;
            }
            // printf("right : %lld\n", right);
        }
    }
    printf("%lld\n", right-left);
}
int main()
{
    int n1, q1, q2, i, j, type, n, m, s, e, l;
    long long ans = 0;
    int temp;
    scanf("%d %d %d", &n1, &q1, &q2);
    v[0] = 0;
    for (i = 1; i <= n1; i++)
    {
        scanf("%d", &temp);
        v[i] = v[i - 1] + temp;
    }
    v[0] = 0;
    for (i = 0; i < q1 + q2; i++)
    {
        scanf("%d", &type);
        ans = 0;
        if (type == 1)
        {
            scanf("%d %d", &n, &m);
            solve(n,m);
        }
        else
        {
            scanf("%d %d %d", &s, &e, &l);
            diff[diff_cnt][0] = s;
            diff[diff_cnt][1] = e;
            diff[diff_cnt][2] = l;
            diff_cnt++;
        }
    }
    return 0;
}