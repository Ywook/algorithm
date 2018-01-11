#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    vector<int> v;
    scanf("%d", &n);
    
    for(int i= 1 ; i <=n; i++){

        v.push_back(i);
    }

    do{
        for(int x : v){
            printf("%d ",x);
        }
        printf("\n");
    }while(next_permutation(v.begin(),v.end()));
}