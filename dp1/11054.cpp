#include <iostream>
using namespace std;
int arr[1004];
int a1[1004];
int a2[1004];
int main(void){
    int n, i, j;
    cin >> n;

    for( i = 1; i <= n ; i++){
        cin >> arr[i];
    }

    for( i =1 ; i <= n ; i++){
        a1[i] = 1;
        for( j = 1; j < n; j++){
            if(arr[i] > arr[j] && a1[i] < a1[j] + 1){
                a1[i] = a1[j] + 1;
            }
        }
    }

    for( i = n; 1 <= i; i--){
        a2[i] = 1;
        for( j = n ; j > i;  j--){
            if(arr[i] > arr[j] && a2[i] < a2[j] + 1){
                a2[i] = a2[j] + 1;
            }
        }
    }
    int ans = 0;
    for( i = 1; i <= n; i++){
        ans = max(ans, a1[i]+a2[i]-1);
    }
    cout << ans<<endl;

}