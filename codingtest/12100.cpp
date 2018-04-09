#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int arr[21][21];

int n;
int res;


int solve(int move){
    queue<int> q;

    if(move == 1){ //위로 움직임
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int t = arr[j][i] ? arr[j][i] : 0;
                if(t) q.push(t);
                arr[j][i] = 0;
            }
            int idx = 0;
            while(!q.empty()){
                int q_data = q.front(); q.pop();

                if(arr[idx][i] == 0) arr[idx][i] = q_data;
                else if(arr[idx][i]== q_data){
                    arr[idx][i] *= 2;
                    idx++;
                }else{
                    idx++;
                    arr[idx][i] = q_data;
                }              
            }
        }
    }else if(move == 2){ //아래로 움직임
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                int t = arr[j][i] ? arr[j][i] : 0;
                if(t) q.push(t);
                arr[j][i] = 0;
            }

            int idx = n-1;
            while(!q.empty()){
                int q_data = q.front(); q.pop();

                if(arr[idx][i] == 0) arr[idx][i] = q_data;
                else if(arr[idx][i] == q_data){
                    arr[idx][i] *= 2;
                    idx--;
                }else{
                    idx--;
                    arr[idx][i] = q_data;
                }
            }
        }
    }else if(move == 3){ //왼쪽
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int t = arr[i][j] ? arr[i][j] : 0;
                if(t) q.push(t);
                arr[i][j] = 0;
            }

            int idx = 0;
            while(!q.empty()){
                int q_data = q.front();
                q.pop();

                if(arr[i][idx] == 0) arr[i][idx] = q_data;
                else if(arr[i][idx] == q_data){
                    arr[i][idx] *= 2;
                    idx++;
                }else{
                    idx++;
                    arr[i][idx] = q_data;
                }
            }
        }
    }else{ //오른쪽!
        for (int i = 0; i < n; i++)
        {
            for (int j = n-1; j >= 0; j--)
            {
                int t = arr[i][j] ? arr[i][j] : 0;
                if (t) q.push(t);
                arr[i][j] = 0;
            }

            int idx = n-1;
            while (!q.empty())
            {
                int q_data = q.front();
                q.pop();

                if (arr[i][idx] == 0)
                    arr[i][idx] = q_data;
                else if (arr[i][idx] == q_data)
                {
                    arr[i][idx] *= 2;
                    idx--;
                }
                else
                {
                    idx--;
                    arr[i][idx] = q_data;
                }
            }
        }
    }
    return 0;
}

void dfs(int depth){
    if(depth == 5){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res = max(arr[i][j],res);
            }
        }
        return;
    }
    int arr2[21][21];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr2[i][j] = arr[i][j];
        }
    }
    for(int i = 1; i < 5; i++){
        solve(i);
        dfs(depth+1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = arr2[i][j];
            }
        }
    }


}
int main(){

    scanf("%d", &n);

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    dfs(0);
    cout<<res<<endl;
}