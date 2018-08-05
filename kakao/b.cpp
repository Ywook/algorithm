#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int a[502];

double solve(int st, int end){
    double m = 0;
    int n = end - st;
    for(int i = st; i < end; i++){
        m+=a[i];
    }
    m = m/(double)n;

    double ans = 0;
    for(int i = st; i < end; i++){
        ans += pow(a[i]-m,2);
    }
    ans = ans/(double)n;
    return sqrt(ans);
}
int main(){
    int n,k;
    double ans = 1;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n ; i++){
        scanf("%d", &a[i]);
    }
    ans = solve(0, k);
    for(int i = k; i <= n; i++){
        for(int j = 0; j + i <= n; j++){
            double temp = solve(j, j+i);
            ans = min(temp, ans);
        }
    }
    printf("%.12lf", ans);
    return 0;
}