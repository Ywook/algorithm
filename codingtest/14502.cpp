#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int map[9][9];
int map2[9][9];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > v;
int ans;

int count(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map2[i][j] == 0){
                cnt++;
            }
        }
    }
    return cnt;
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map2[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<endl;
}
void bfs()
{
    queue<pair<int, int>> v2, v3;
    int v_size = v.size();
    while (v_size--)
    {
        int y = v.front().first;
        int x = v.front().second;
        v.pop();
        v2.push(make_pair(y, x));
        v3.push(make_pair(y, x));
    }

    while (!v2.empty())
    {
        int y = v2.front().first;
        int x = v2.front().second;
        v2.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (map2[ny][nx] == 0)
            {
                map2[ny][nx] = 2;
                v2.push(make_pair(ny, nx));
            }
        }
    }
    v_size = v3.size();

    while (v_size--)
    {
        int y = v3.front().first;
        int x = v3.front().second;
        v3.pop();
        v.push(make_pair(y, x));
    }
}
void dfs(int y, int x, int depth)
{
    if (depth == 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                map2[i][j] = map[i][j];
            }
        }
        // print();
        bfs();
        ans = max(ans, count());
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                dfs(i, j, depth + 1);
                map[i][j] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2)
            {
                v.push(make_pair(i, j));
            }
        }
    }

    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}