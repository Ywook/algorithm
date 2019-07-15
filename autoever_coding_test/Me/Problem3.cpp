#include <string>
#include <vector>

using namespace std;
int check[100002];
int solution(int N, vector<vector<int>> trees)
{
    int answer = 0;
    int len = trees.size();
    int x, y;
    int nx, ny;

    for (int i = 0; i < len; i++)
    {
        if (check[i])
            continue;

        x = trees[i][0];
        y = trees[i][1];

        for (int j = 0; j < len; j++)
        {
            if (i == j)
                continue;

            nx = trees[j][0];
            ny = trees[j][1];

            if (x < nx && y < ny)
            {
                check[j] = 1;
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (!check[i])
            answer++;
    }
    return answer;
}