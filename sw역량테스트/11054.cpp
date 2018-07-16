#include <iostream>
#include <cstdio>

using namespace std;
int a[1004];
int dp[1004];
int dp2[1004];

int main()
{
    int n;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        dp2[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j] && dp2[i] < dp2[j] + 1)
            {
                dp2[i] = dp2[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (dp2[i] + dp[i] - 1));
    }
    cout << ans << endl;
}