#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int map[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<int> generation;
int main(){
    int n, x, y, d, g;
    scanf("%d", &n);
    int ans =0;
    while(n--){
        scanf("%d %d %d %d", &x, &y, &d, &g);

        map[y][x] = 1;
        map[y + dy[d]][x + dx[d]] = 1;

        y += dy[d];
        x += dx[d];
        generation.clear();
        generation.push_back(d);

        for(int i = 0; i < g; i++){
            int len = generation.size();

            for(int k = len - 1; k > -1; k--){
                d = (generation[k] + 1)%4;

                y += dy[d];
                x += dx[d];

                map[y][x] = 1;

                generation.push_back(d);
            }
        }
    }
    

    for(int i = 0 ; i< 101; i++){
        for(int j = 0; j < 101; j++){
            if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}