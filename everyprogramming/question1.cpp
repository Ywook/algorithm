/*
정수 배열(int array)가 주어지면 가장 큰 이어지는 원소들의 합을 구하시오. 단, 시간복잡도는 O(n).

예제}

Input: [-1, 3, -1, 5]
Output: 7 // 3 + (-1) + 5

Input: [-5, -3, -1]
Output: -1 // -1

Input: [2, 4, -2, -3, 8]
Output: 9 // 2 + 4 + (-2) + (-3) + 8
*/
#include <cstdio>
#include <iostream>

using namespace std;

int a[1004];

int main(){
    int n;
    int current, ans;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    current = ans = a[0];
    
    for(int i = 1; i < n; i++){
        current = max(current+a[i], a[i]);
        ans = max(current,ans);
    }
    cout<<ans<<endl;
}