#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 52;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

vector<int> w;
int map[MAX][MAX];
int temp = 0;

bool desc(int a, int b)
{
    return a > b;
}

void go(int y_pos, int x_pos, int r, int c)
{
    temp++;
    map[y_pos][x_pos] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x_pos + dx[i];
        int ny = y_pos + dy[i];

        if (nx < 0 || ny < 0 || nx >= c || ny >= r)
            continue;
        if (map[ny][nx] == 0)
            continue;
        go(ny, nx, r, c);
    }
}

vector<int> solution(vector<vector<int>> v)
{
    int r = v.size();
    int c = v[0].size();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            map[i][j] = v[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 1)
            {
                temp = 0;
                go(i, j, r, c);
                w.push_back(temp);
            }
        }
    }

    vector<int> answer;
    answer.push_back(w.size());
    sort(w.begin(), w.end(), desc);
    if (w.size() != 0)
        answer.push_back(w[0]);
    else
        answer.push_back(0);
    return answer;
}