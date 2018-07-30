#include <iostream>
#include <algorithm>
#include <cstdio>
#include <limits.h>
using namespace std;

int d[504][504];
int a[504];
int sum[504];
int main(void)
{
    int t, k;
    long ans;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &k);

        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i < k; i++)
        {
            for (int st = 1; st + i <= k; st++)
            {
                int end = i + st;
                d[st][end] = INT_MAX;
                for (int l = st; l < end; l++)
                {
                    d[st][end] = min(d[st][end], d[st][l] + d[l + 1][end] + sum[end] - sum[st - 1]);
                }
            }
        }
        cout << d[1][k] << endl;
    }
}