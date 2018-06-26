#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

queue<int> q;
bool prime[10005];
int visit[10001];
int ans[10001];

int change(int num, int i, int j){
    int changeNum = 0;
    if(i == 0){
        changeNum = num - num%10 + j;
    }else if(i == 1){
        int t = num%100 - num %10;
        changeNum = num - t + j*10;
    }else if(i == 2){
        int t = (num/100)%10;
        changeNum = num - t*100 + j *100;
    }else{
        int t = num/1000;
        changeNum = num - t*1000 + j * 1000;
    }
    return (changeNum > 999) ? changeNum : -1;
}
int main(){
    int t, n, m;

    scanf("%d", &t);
    
    for(int i = 2; i < 10000; i++) prime[i] = true;
    
    for(int i = 2; i < sqrt(10000); i++){
        if(prime[i]){
            for(int j = i*i; j <= 10000; j+=i){
                prime[j] = false;
            }
        }
    }

    while(t--){
        scanf("%d %d", &n, &m);
        //1000이상 10000미만
        q.push(n);
        visit[n] = true;
        while(!q.empty()){
            int k = q.front(); q.pop();
            for (int i = 0; i < 4; i++)
            {   
                
                for (int j = 0; j < 10; j++)
                {
                    int next = change(k, i, j);
                    if(next != -1){
                        if(prime[next] && !visit[next]){
                            q.push(next);
                            visit[next] = true;
                            ans[next] = ans[k] + 1;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans[m]);
        for(int i = 1000; i < 10000; i++){
            visit[i] = false;
            ans[i] = 0;
        }
    }
}