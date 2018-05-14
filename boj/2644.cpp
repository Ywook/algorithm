#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int n, m, s1, s2;
vector<int> v[102];
int visit[102];

int main(){
    scanf("%d", &n);
    scanf("%d %d", &s1, &s2);
    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }

    int ans = -1;
    queue<int> q;
    
            for(int a:v[s1]){
q.push(a);
    }
    int q_size = q.size();

    while(q_size){
        
    }
    return 0;
}