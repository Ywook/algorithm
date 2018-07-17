#include <iostream>

using namespace std;

int dp[305];
int score[305];

int main(int argc, char const *argv[])
{
    int n, i;

    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> score[i];
    }

    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    for (i = 3; i <= n; i++)
    {
        dp[i] = max(score[i] + dp[i - 2], score[i] + score[i - 1] + dp[i - 3]);
    }
    cout << dp[n] << endl;

    return 0;
}
