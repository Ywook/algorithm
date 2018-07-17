#include <iostream>
#include <cstdio>

using namespace std;

int a[1001][1001];
int dp[1001][1001];
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    dp[1][1] = a[1][1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
                {
                    dp[nx][ny] = max(dp[nx][ny], dp[i][j] + a[nx][ny]);
                }
            }
        }
    }

    cout << dp[n][m] << endl;
}