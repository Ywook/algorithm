#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int visit[10001];
int from[10001];
char how[10001];

void print(int init, int last){
    if(last == init) return;
    print(init, from[last]);
    printf("%c", how[last]);
}

int main(){
    int t, n , m, next;
    queue<int> q;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);
        q.push(n);
        memset(visit, 0, sizeof(visit));
        memset(from, 0 , sizeof(from));
        memset(how, 0, sizeof(how));
        from[n] = -1;
        while(!q.empty()){
            int now = q.front(); q.pop();
            
            next = (2*now)%10000; 
            if(!visit[next]){
                q.push(next);
                visit[next] = true;
                from[next] = now;
                how[next] = 'D';
            }
            
            next = now - 1;
            next = (next == -1)? 9999 : next;
            if(!visit[next]){
                q.push(next);
                visit[next] = true;
                from[next] = now;
                how[next] = 'S';
            }

            next = (now%1000)*10 + now/1000;
            if(!visit[next]){
                q.push(next);
                visit[next] = true;
                from[next] = now;
                how[next] = 'L';
            }

            next = (now%10) * 1000 + (now/10);
            if(!visit[next]){
                q.push(next);
                visit[next] = true;
                from[next] = now;
                how[next] = 'R';
            }
        }
        print(n,m);
        printf("\n");
    }
}