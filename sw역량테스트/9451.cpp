#include <iostream>

using namespace std;

long long d[104];

int main(void)
{
    int t, n;
    cin >> t;
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    d[5] = 2;
    while (t--)
    {
        cin >> n;

        for (int i = 6; i <= n; i++)
        {
            d[i] = d[i - 1] + d[i - 5];
        }

        cout << d[n] << endl;
    }
}