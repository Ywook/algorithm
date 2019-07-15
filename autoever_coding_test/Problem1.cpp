#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int dir = 0;
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int check(int ny, int nx)
{
    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
    {
        return false;
    }
    return true;
}

int solution(vector<vector<int>> office, int r, int c, vector<string> move)
{
    int answer = 0;
    int nr, nc;

    n = office.size();
    answer += office[r][c];
    office[r][c] = 0;

    for(int i = 0; i < move.size(); i++){
        string temp = move[i];
        if(move[i].compare("left") == 0) {
            dir = (dir + 3)%4;
        }else if(move[i].compare("right") == 0){
            dir = (dir + 1)%4;
        }else{
            nr = r + dy[dir];
            nc = c + dx[dir];
            if (check(nr, nc))
            {
                if (office[nr][nc] != -1)
                {
                    r = nr;
                    c = nc;
                    answer += office[r][c];

                    office[r][c] = 0;
                }
            }
        }

    }
    return answer;
}

int main(){
    cout<<solution({{5,-1,4},{6,3,-1},{2,-1,1}},1,0, {"go","go","right","go","right"
    ,"go","left","go"})<<endl;
}