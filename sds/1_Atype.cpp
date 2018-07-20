#include<iostream>
#include<cstdio>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m, r1, c1, r2, c2;

int main(){
    int t;


    scanf("%d", &t);

    for(int l = 1; l <= t; l++){
        int ans = 0;
        scanf("%d %d %d %d %d %d", &n, &m, &r1, &c1, &r2, &c2);
        ans = abs(r2- r1) + abs(c2- c1);
        int temp = 0;
        //1번째 경우 위로 갔다가 오른쪽으로 가는 경우, 왼쪽으로 가는 경우
        temp = r1 +1 + abs(n-1 - r2) + abs(c2-c1);
        ans = min(temp, ans);

        temp = r1 + 1 + m-c1 + abs(n-1 - r2) + c2;
        ans = min(temp, ans);

        temp = r1 + 1 + c1 + 1 + abs(n-1 - r2) + abs(c2 - (m-1));
        ans = min(temp, ans);
        //2번째 경우 오른쪽으로 갔다가 위로 가는 경우, 아래로 가는 경우
        temp = m-c1 + abs(r2-r1) + c2;
        ans = min(temp, ans);

        temp = m-c1 + r1+1 + abs(n-1 - r2) + c2;
        ans = min(temp, ans);

        temp = m-c1 + abs(n-r1) + abs(n-1-r2) + c2;
        ans = min(temp, ans);

        //3번째 경우 아래로 갔다가 왼쪽으로 가는 경우, 오른쪽으로 가는 경우
        temp = n - r1 + r2 + abs(c2-c1);
        ans = min(temp, ans);

        temp = n - r1 + abs(m - c1 - 1) + r2 + abs(c2 - (m-1));
        ans = min(temp, ans);

        temp = n- r1 + abs(m - c1) + r2 + c2;
        ans = min(temp, ans);

        //4번째 경우 왼쪽으로 갔다가 위로 가는 경우, 아래로 가는 경우
        temp = c1 + 1 + abs(r2-r1) + abs(c2 - (m-1));
        ans = min(temp, ans);

        temp = c1 + 1 + r1 + 1 + n-1-r2 + abs(c2 - (m-1));
        ans = min(temp, ans);

        temp = c1 + 1 + n - r1 + r2 + abs(c2 - (m-1));
        ans = min(temp, ans);

        printf("#%d %d\n",l, ans);
    }
    return 0;
}