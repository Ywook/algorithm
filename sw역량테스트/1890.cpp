#include <iostream>
#include <cstdio>

using namespace std;
int n;
long long arr[101][101];
long long dp[101][101];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &arr[i][j]);
        }
    }
    //시작점은 0, 0이다.
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == n - 1 && j == n - 1)
            {
                break;
            }
            int down = i + arr[i][j];
            int right = j + arr[i][j];

            if (down < n)
                dp[down][j] += dp[i][j];
            if (right < n)
                dp[i][right] += dp[i][j];
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}