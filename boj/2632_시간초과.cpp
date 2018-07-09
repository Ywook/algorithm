#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> a_subset, b_subset;

void get_all_sum(vector<int> &c, int size, map<int,int> &d){
    for(int i = 1; i < size; i++){ //1개 ~ size-1개로 만들 수 있는 경우 모두
        for(int j = 0; j < size; j++){ //j번 부터 더하기
            int sum = 0;
            for(int k = 1; k <= i; k++){ //j부터 i개만큼 더하기
                if(j+k-1 < size){
                    sum += (c)[j+k-1];
                }else{
                    sum += (c)[j+k-1-size];
                }
            }
            d[sum] += 1;
        }
    }

    int sum = 0;
    for(int i = 0; i < size; i++) sum += (c)[i];
    d[sum] = 1;
}
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
    get_all_sum(a, m, a_sum);
    get_all_sum(b, n, b_sum);

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