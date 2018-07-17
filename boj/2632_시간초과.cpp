#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> a_subset, b_subset;

int main(){
    int size, m, n;

    scanf("%d %d %d", &size, &m, &n);
    vector<int> a(m);
    vector<int> b(n);
    map<int, int> a_sum, b_sum;

    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }

    
    long long ans = 0;
    ans = a_sum[size] + b_sum[size];
    for(int i = 1; i < size; i++){
        if(a_sum[i] && b_sum[size-i]){
            ans += a_sum[i]*b_sum[size-1];
        }
    }
    printf("%lld\n", ans);

    return 0;
}