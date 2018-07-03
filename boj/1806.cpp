#include <iostream>
#include <cstdio>

using namespace std;

int a[100002];

int main()
{
    int n, s;

    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int left, right, ans, temp, sum;
    ans = 100003;
    temp = left = right = 0;
    sum = a[0];

    while (left <= right && right < n)
    {
        if (sum == s)
        {
            ans = (ans > right - left + 1) ? (right - left + 1) : ans;
            right++;
            sum += a[right];
        }
        else if (sum < s)
        {
            right++;
            sum += a[right];
        }
        else
        {
            if(right - left + 1 < ans){
                ans = right - left + 1;
            }
            sum -= a[left];
            left++;
            if (left > right && left < n)
            {
                sum = a[left];
                right = left;
            }
        }
    }
    cout << ((ans > 100000) ? 0 : ans) << "\n";
}
