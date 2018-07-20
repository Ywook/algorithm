#include <iostream>

using namespace std;

long long dp[10004];
long long a[103];

int main(int argc, char const *argv[])
{
    int n, k, i, j;

    cin >> n >> k;

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= k; j++)
        {
            if (j - a[i] >= 0)
            {
                dp[j] += dp[j - a[i]];
            }
        }
    }

    printf("%lld \n", dp[k]);
    return 0;
}
