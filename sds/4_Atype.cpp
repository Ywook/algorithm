#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t, n, k, l;
    scanf("%d", &t);

    for(int w = 1; w <= t; w++){
        scanf("%d %d %d", &n, &k, &l);
        vector<pair<int, int> > v;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int s, q;
            scanf("%d %d", &s, &q);
            v.push_back(make_pair(s,q));
        }
        
        printf("#%d %d", w, ans);
    }
    return 0;
}