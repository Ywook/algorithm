#include <iostream>

using namespace std;

long d[5004];

int main(void)
{
    string str;
    int len;

    cin >> str;
    len = str.size();
    str = " " + str;
    d[0] = 1;

    for (int i = 1; i <= len; i++)
    {
        int t = str[i] - '0';
        if (1 <= t)
        {
            d[i] += d[i - 1];
            d[i] %= 1000000;
        }
        if (i == 1 || str[i - 1] == 0)
            continue;

        t = (str[i - 1] - '0') * 10 + (str[i] - '0');
        if (9 < t && t < 27)
        {
            d[i] += d[i - 2];
            d[i] %= 1000000;
        }
    }

    cout << d[len] << endl;
}