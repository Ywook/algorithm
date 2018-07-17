#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int arr[2][100002];
int d[3][100002];
int main(){
   int t;

   scanf("%d", &t);

   while(t--){
       int n;
       scanf("%d", &n);

       for(int i = 0; i < 2; i++){
           for(int j = 1; j <= n; j++){
               scanf("%d", &arr[i][j]);
               d[i][j] = 0;
               d[2][j] = 0;
           }
       }
        for(int i = 1; i <= n; i++){
            d[0][i] = max(d[2][i - 1] + arr[0][i], d[1][i - 1] + arr[0][i]);
            d[1][i] = max(d[0][i - 1] + arr[1][i], d[2][i - 1] + arr[1][i]);
            d[2][i] = max(d[2][i - 1], max(d[0][i - 1], d[1][i - 1])); //햔재를 고르지 않는 경우
        }
        for(int i = 1; i < 3; i++){
            d[0][n] = max(d[0][n], d[i][n]);
        }
        printf("%d\n",d[0][n]);
   } 
}