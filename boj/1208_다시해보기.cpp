#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int n, s;
    scanf("%d %d", &n, &s);

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int m = n/2;
    n -= m;

    vector<int> first(1<<n);
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++){
            if(i &(1<<j)){
                first[i] += a[j];
            }
        }
    }
    vector<int> second(1<<m);
    for(int i = 0; i < (1<<m); i++){
        for(int j = 0; j < m; j++){
            if(i & (1<<j)){
                second[i] += a[j + n];
            }
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    reverse(second.begin(), second.end());

    n = (1<< n);
    m = (1 << m);
    int i = 0;
    int j = 0;
    long long ans = 0;
    while(i < n && j < m){
        if(first[i] + second[j] == s){
            long long c1 = 1;
            long long c2 = 1;
            i += 1;
            j += 1;

            while(i < n && first[i] == first[i-1]){
                i++; c1++;
            }
            while(j < m && second[j] == second[j-1]){
                c2++; j++;
            }
            ans += c1 * c2;
        }else if(first[i] +second[j] < s){
            i++;
        }else{
            j++;
        }
    }

    if(s == 0) ans -= 1;
    printf("%lld\n", ans);
    return 0;

}