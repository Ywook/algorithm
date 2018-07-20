#include <iostream>

long long dp[501][502];
int a[501][2];

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n, i, j, k, l;

    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> a[i][0];
        cin >> a[i][1];
    }

    for (k = 1; k < n; k++)
    {
        for (i = 1; i <= n - k; i++)
        {
            j = i + k;

            long long temp = 987654321;
            for (l = i; l < j; l++)
            {
                temp = min(dp[i][l] + dp[l + 1][j] + a[i][0] * a[l][1] * a[j][1], temp);
            }
            dp[i][j] = temp;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
