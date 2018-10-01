#include <iostream>
#include <queue>
#include <cstdio>
// #include<cstring>
using namespace std;

int n, k;
int dx[3] = {2, -1, 1};
int visit[100002];
int flag;
int ans = -1;
int ans_num = 0;
void bfs()
{
    if (n == k)
    {
        ans = 0;
        ans_num++;
        return;
    }
    int nx;
    queue<int> q;
    q.push(n);
    visit[n] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == k)
        {
            ans = visit[x];
            ans_num++;
            flag = 1;
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
                nx = x * dx[i];
            else
                nx = x + dx[i];

            if (nx >= 0 && nx <= 100000)
            {
                if (visit[nx] == -1 || visit[nx] >= visit[x] + 1)
                {
                    if (!flag)
                    {
                        visit[nx] = visit[x] + 1;
                        q.push(nx);
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    // memset(visit, -1, sizeof(visit));
    for (int i = 0; i < 100001; i++)
        visit[i] = -1;
    bfs();
    printf("%d\n", ans);
    printf("%d\n", ans_num);
}