#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, i;
    scanf("%d", &n);
    vector<int> a, d;
    for (i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        a.push_back(t);
        d.push_back(1);
    }
    int ans = 1;

    int pivot;
    for (int i = 1; i < n; i++)
    {
        pivot = a[i];
        for(int j = i -1; j >= 0;){//i를 마지막으로 할 때 d[i] 최대 군계일학 수
            if(pivot == a[j] + 1){
                d[i] = d[j] + 1;
                ans = max(d[i],ans);
                break;
            }
            j--;
        }
    }
    printf("%d\n", (ans));
}
