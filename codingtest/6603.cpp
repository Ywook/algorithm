#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> subset;
vector<int> v;

int last = 0;
void dfs(int len, int depth){
    if(depth == 0){
        for(int i = 0; i < subset.size(); i ++){
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    int next = subset.empty()? 0:last;

    for(int i = next; i < len ; i++){
        subset.push_back(v[i]);
        last = i+1;
        dfs(len, depth -1);
        subset.pop_back();
    }
}
int main(){
    int k, i;
    scanf("%d", &k);

    while(k){
        for (i = 0; i < k; i++)
        {
            int t;
            scanf("%d", &t);
            v.push_back(t);
        }
        dfs(k, 6);
        printf("\n");
        v.clear();
        scanf("%d", &k);
    }


}