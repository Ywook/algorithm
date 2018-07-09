#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int a[1001];
int b[1001];

int main(){
    int t, n, m;

    scanf("%d", &t);
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    vector<int> a_sum, b_sum;

    int sum;
    for(int i = 0; i < n; i++){
        sum = a[i];
        a_sum.push_back(sum);
        for(int j = i + 1; j < n; j++){
            sum += a[j];
            a_sum.push_back(sum);
        }
    }

    for(int i = 0; i < m; i++){
        sum = b[i];
        b_sum.push_back(sum);
        for(int j = i + 1; j < m ; j++){
            sum += b[j];
            b_sum.push_back(sum);
        }
    }
    sort(a_sum.begin(), a_sum.end());
    sort(b_sum.begin(), b_sum.end());
    reverse(b_sum.begin(), b_sum.end());

    int l, r;
    n = a_sum.size();
    m = b_sum.size();
    l = r = 0;
    long long ans = 0;
    while(l < n && r < m){
        if(a_sum[l] + b_sum[r] == t){
            long long n1, n2;
            n1 = n2 = 1;

            l++; r++;

            while(l < n && a_sum[l] == a_sum[l-1]){
                l++; n1++;
            }

            while (r < m && b_sum[r] == b_sum[r - 1])
            {
                r++;
                n2++;
            }

            ans += n1*n2;
        }else if(a_sum[l] + b_sum[r] < t){
            l++;
        }else{
            r++;
        }
    }

    printf("%lld\n", ans);
}