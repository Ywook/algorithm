#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

char check[250003];
vector<pair<int, pair<int, int>>> check_point;

void check_func(int st, int next, int x){
    int c_x = check_point[st].second.first;
    int c_y = check_point[st].second.second;
    if (c_x == check_point[next].second.first || c_y == check_point[next].second.second)
    {
        check[st] = 1;
    }
    else
    {
        if (x > 0)
        {
            //x축을 맞추거나 y축을 맞춘다
            //이 경우 다음 turn에서 boost를 사용해서 해당 check point로 이동 가능
            int minus_hp = abs(c_x - check_point[next].second.first);
            if (x - minus_hp >= 0)
            {
                check[st] = 1;
            }
            else
            {
                minus_hp = abs(c_y - check_point[next].second.second);
                if (x - minus_hp >= 0)
                {
                    check[st] = 1;
                }
            }
        }
    }
}
int main(){
    int n,q;


    check_point.push_back(make_pair(0,make_pair(-1, -1)));
    int x, y;
    

    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &x, &y);
        check_point.push_back(make_pair(i, make_pair(x,y)));
    }

    for(int i = 0 ; i < q; i++){
        int a, b, x;

        scanf("%d %d %d", &a, &b, &x);
        memset(check, 0, sizeof(check));

        queue<int> q;
        int c_x, c_y, end_x, end_y;


        for(int j = 1; j <= n; j++){
            if(j == b) continue;
            c_x = check_point[j].second.first;
            c_y = check_point[j].second.second;
            if (c_x == check_point[b].second.first || c_y == check_point[b].second.second)
            {
                check[j] = 1;
                check_func(a, j, x);
            }else{
                if(x > 0){
                    //x축을 맞추거나 y축을 맞춘다
                    //이 경우 다음 turn에서 boost를 사용해서 해당 check point로 이동 가능
                    int minus_hp = abs(c_x - check_point[j].second.first);
                    if(x-minus_hp >= 0) {
                        check[j] = 1;
                        check_func(a, j, x);
                    }
                    else{
                        minus_hp = abs(c_y - check_point[j].second.second);
                        if(x-minus_hp >= 0){
                            check[j] = 1;
                            check_func(a, j, x);
                        }
                    }
                }
            }
            if(check[a]) {
                printf("YES\n");
                break;
            }
        }
        if(!check[a])printf("NO\n");
    }
}