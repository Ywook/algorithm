#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n, l;
int map[102][102], map2[102][102];
int visit[102];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int ans = 0;
void solve(int index, int (*arr)[102]){
    memset(visit, 0, sizeof(visit));

    for(int i = 0; i < n-1; i++){
        if(arr[index][i] != arr[index][i+1]){
            int diff = arr[index][i] - arr[index][i+1];
            if(diff != -1 && diff != 1) return;
            
            if(diff== 1){
                for(int j =1; j <= l; j++){
                    if(i + j >= n || visit[i+j] == 1) return;

                    if(arr[index][i] -1 == arr[index][i+j]) visit[i+j]=1;
                    else return;
                }
            }else{
                for(int j = 0; j < l ; j++){
                    if(i - j < 0 || visit[i-j]) return;

                    if(arr[index][i] == arr[index][i-j]) visit[i-j] = 1;
                    else return;

                    
                }
            }
        }
    }
    ans++;
}

int main(){
    scanf("%d %d", &n, &l);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&map[i][j]);
            map2[j][i] = map[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        solve(i, map);
        solve(i, map2);
    }
    printf("%d\n",ans);
}