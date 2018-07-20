#include <cstdio>

int a[2003];
int dp[2003][2003];

int solve(int i, int j)
{
    if (i == j)
    {
        return 1;
    }
    else if (i + 1 == j)
    {
        if (a[i] == a[j])
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    if (dp[i][j] > 0)
    {
        return dp[i][j];
    }
    if (a[i] == a[j])
    {
        return dp[i][j] = solve(i + 1, j - 1);
    }
    else
    {
        return dp[i][j] = 2;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    int i, j;
    int s, e;
    int k;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);

    for (i = 1; i <= m; i++)
    {
        scanf("%d", &s);
        scanf("%d", &e);
        k = solve(s, e);
        if (k == 2)
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }
    return 0;
}
