#include<iostream>
#include<cstdio>

using namespace std;

int a[10002];
int main(){
    int n, m;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);

    }
    
    int left, right, ans;
    ans = left = right = 0;
    int sum = a[0];
    while(left <= right && right < n ){
        if(sum == m){
            ans++;
            right++;
            sum += a[right];
        }else if(sum > m){
            sum -= a[left];
            left++;
            if(left > right && left < n){
                right = left;
                sum = a[left];
            }
        }else{
            right++;
            sum += a[right];
        }
    }

    cout<<ans<<endl;
}