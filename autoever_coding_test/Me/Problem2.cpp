#include <iostream>
#include <vector>

using namespace std;

int dp[100002];
int solution(vector<int> play_list, int listen_time)
{
    int answer = 0;
    int len = play_list.size();

    dp[0] = play_list[0];

    for (int i = 1; i < len; i++)
    {
        dp[i] = dp[i - 1] + play_list[i];
    }

    int abc, rev;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (j - i + 1 < answer && len -1 - j + 2 + i < answer)
                break;

            abc = dp[j] - dp[i] + 2 - play_list[j];           //정순
            rev = (dp[len-1] - dp[j]) + dp[i] - play_list[i] + 2; //역순

            if (abc <= listen_time)
            {
                answer = max(answer, j - i + 1);
            }
            if (rev <= listen_time)
            {
                answer = max(answer, len - 1 - j + 2 + i);
            }
        }
    }
    return answer;
}

int main(){
    cout<<solution({2,1,3,4},4)<<endl;
}