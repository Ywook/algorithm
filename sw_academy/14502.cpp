#include<vector>
#include<cstdio>

using namespace std;

int n, m;
int map[9][9];
int temp_map[9][9];
int visit[9][9];
int ans = 0;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

vector<pair<int ,int > > virus;
vector<pair<int, int > > empty_cnt;

void copy_map(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            map[i][j] = temp_map[i][j];
            visit[i][j] = 0;
        }
    }
}
void dfs(int y, int x){
    int ny, nx;
    visit[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny > -1 && ny < n && nx > -1 && nx < m){
            if(visit[ny][nx] == 0 && map[ny][nx] == 0){
                map[ny][nx] = 2;
                dfs(ny,nx);
            }
        }
    }
}
int safe_cnt(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
int main(){
    scanf("%d %d",&n, &m);

    for(int i = 0; i < n ; i++){
        for(int j = 0; j< m; j++){
            scanf("%d", &map[i][j]);
            temp_map[i][j] = map[i][j];
            if(map[i][j] == 0 ){
                empty_cnt.push_back(make_pair(i,j));
            }else if(map[i][j] == 2){
                virus.push_back(make_pair(i,j));
            }
        }
    }

    for(int i = 0; i < empty_cnt.size(); i++){
        for(int j = i + 1; j < empty_cnt.size(); j++){
            for(int k = j + 1; k < empty_cnt.size(); k++){
                copy_map();
                map[empty_cnt[i].first][empty_cnt[i].second] = 1;
                map[empty_cnt[j].first][empty_cnt[j].second] = 1;
                map[empty_cnt[k].first][empty_cnt[k].second] = 1;

                for(int t = 0; t < virus.size(); t++){
                    dfs(virus[t].first, virus[t].second);
                }
                ans = max(ans,safe_cnt());
            }
        }
    }
    printf("%d\n", ans);
    
}