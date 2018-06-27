#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;
int check[1000004];
int dist[1000004];
int main()
{
    int f, s, g, u, d;
    int ans = 0;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    queue<int> q;
    q.push(s);

    check[s] = 1;
    while(!q.empty()){
        int z = q.front(); q.pop();
        int nz = z + u;
        if(nz <= f && nz > 0){
            if(!check[nz]){
                dist[nz] = dist[z] + 1;
                check[nz] = 1;
                q.push(nz);
            }
        }
        nz = z - d;
        if(nz <= f && nz > 0){
            if(!check[nz]){
                dist[nz] = dist[z] + 1;
                check[nz] = 1;
                q.push(nz);
            }
        }

    }
    if(check[g]){
        cout<<dist[g]<<endl;
    }else{
        cout<<"use the stairs"<<endl;
    }
}