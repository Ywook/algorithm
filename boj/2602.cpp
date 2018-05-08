#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[23];
char angel[102], devil[102];

int main(){
    scanf("%s", str);
    scanf("%s", angel);
    scanf("%s", devil);
    int dp[30][2] = {1, 1};

    int a_len = strlen(angel);
//두가지 경우 천사 다리 먼저 밟는경우, 악마 다리 먼저 밟는 경우
//천사 다라를 밟았을 경우 무조건 다음은 악마 다리
//악마 다리를 밟았을 경우 다음은 무조건 천사 다리
//건너뛰는 칸의 수에는 상관이 없다.
    int len = strlen(str);
    for(int i = 0; i < a_len; i++){
        for(int j = len - 1; j >=0; j--){
            if(angel[i] == str[j]){
                dp[j+1][1] += dp[j][0];
            }
            if(devil[i] == str[j]){
                dp[j+1][0] += dp[j][1];
            }
        }
    }
        
    cout << dp[len][0] + dp[len][1]<<endl;
    //0, 1, 2 -> 3
    //0, 1, ,2, 3, 4 -> 5 5-3 = 2 
}