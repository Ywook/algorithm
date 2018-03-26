#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int visit[26] = {0};
string s[21];
vector<char> stack;

int r, c;
int ans;
void dfs(int x, int y, int cnt){
    ans = max(cnt, ans);

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= ny && ny <r && 0 <= nx && nx < c){
            int k = s[ny][nx] - 'A';

            if(visit[k]){
                continue;
            }
            visit[k]++;
            dfs(nx,ny, cnt+1);
            visit[k]--;
        }
    }
    return;
}
int main(){
    scanf("%d %d", &r, &c);

    for(int i = 0; i < r; i++){
        cin>>s[i];
    }
    visit[s[0][0] -'A']++;
    dfs(0,0, 1);
    cout<<ans<<endl;
}  