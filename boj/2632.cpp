#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int size, m, n;

    scanf("%d %d %d", &size, &m, &n);
    vector<int> a(m);
    vector<int> b(n);

    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }

    vector<int> a_subset(1<<m), b_subset(1<<n);
    for(int i = 0; i < (1<<m); i++){
        for(int j = 0; j < m; j++){
            if(i & (1<<j)){
                a_subset[i] += a[j];
            }
        }

    }

    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                b_subset[i] += b[j];
            }
        }
    }
    
    sort(a_subset.begin(), a_subset.end());
    sort(b_subset.begin(), b_subset.end());
    reverse(b_subset.begin(), b_subset.end());

    int l = 0;
    int r = 0;
    m = (1<<m);
    n = (1<<n);
    long long ans = 0;
    while(l < m && r < n){
        if(a_subset[l] + b_subset[r] == size){
            long long n1, n2;
            n1 = n2 = 1;
            cout << " l : " << l << endl;

            l++;
            r++;
            while(l < m && a_subset[l] == a_subset[l-1]){
                n1++;
                l++;
            }
            while(r < n && b_subset[r] == b_subset[r-1]){
                n2++;
                r++;      
            }            
            ans += n1*n2;
        }else if(a_subset[l] + b_subset[r] < size){
            l++;
        }else{
            r++;
        }
    }
    printf("%lld\n", ans);

    return 0;
}