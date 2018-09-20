#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[52][13];
int check[15];
int n, m;
int ans = 100000000;
vector<pair<int, int>> home;
vector<pair<int, int>> store;

void dfs(int store_num, int cnt)
{
    if (store_num > store.size())
    {
        return;
    }

    if (cnt == m)
    {
        int temp = 0;
        int d;

        for (int i = 0; i < home.size(); i++)
        {
            int y = home[i].first;
            int x = home[i].second;
            d = 100000000;
            for (int j = 0; j < store.size(); j++)
            {
                if (check[j])
                {
                    int ny = store[j].first;
                    int nx = store[j].second;
                    int d2 = abs(y - ny) + abs(x - nx);
                    d = min(d, d2);
                }
            }
            temp += d;
        }
        ans = min(ans, temp);
        return;
    }

    //치킨집을 사용할 경우
    check[store_num] = 1;
    dfs(store_num + 1, cnt + 1);
    //store_num 치킨집을 사용하지 않을 경우
    check[store_num] = 0;
    dfs(store_num + 1, cnt);
}
int main()
{
    int store_n = 0;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
            {
                home.push_back(make_pair(i, j));
            }
            else if (map[i][j] == 2)
            {
                store.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0, 0);
    printf("%d\n", ans);
    //10개를 뺄경우 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 11, 12
    //store 에서 m개를 뽑아서 치킨 거리의 값을 구한다.
    //모든 집의 치킨 거리의 합
}