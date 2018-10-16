#include<iostream>
#include<cstdio>

using namespace std;

char s[5][24];
int k;

void rotate(int n, int dir){
    int tmp;
    if(dir == 1){
        tmp = s[n][0];
        s[n][0] = s[n][7];
        s[n][7] = s[n][6];
        s[n][6] = s[n][5];
        s[n][5] = s[n][4];
        s[n][4] = s[n][3];
        s[n][3] = s[n][2];
        s[n][2] = s[n][1];
        s[n][1] = tmp;
        
    }else{
        tmp = s[n][0];
        s[n][0] = s[n][1];
        s[n][1] = s[n][2];
        s[n][2] = s[n][3];
        s[n][3] = s[n][4];
        s[n][4] = s[n][5];
        s[n][5] = s[n][6];
        s[n][6] = s[n][7];
        s[n][7] = tmp;
    }
}

void spin(int n, int dir)
{
    if(n == 1){
        if(s[n][2] != s[n+1][6]){
            if(s[n+1][2] != s[n+2][6]){
                if(s[n+2][2] != s[n+3][6]){
                    rotate(n + 1, dir * -1);
                    rotate(n + 2, dir);
                    rotate(n + 3, dir * -1);
                }else{
                    rotate(n + 1, dir * -1);
                    rotate(n + 2, dir);

                }
            }else{
                rotate(n+1, dir*-1);
            }
        }
        rotate(n,dir);
    }else if(n == 2){
        if(s[n][2] != s[n+1][6]){
            if(s[n+1][2] != s[n+2][6]){
                rotate(n+1, dir * -1);
                rotate(n+2, dir);
            }else{
                rotate(n+1, dir * -1);
            }
        }
        if(s[n][6] != s[n-1][2]){
            rotate(n-1, dir * -1);
        }
        rotate(n, dir);
    }else if(n == 3){
        if(s[n][2] != s[n+1][6]){
            rotate(n+1, dir * -1);
        }
        if(s[n][6] != s[n-1][2]){
            if(s[n-1][6] != s[n-2][2]){
                rotate(n-1, dir * -1);
                rotate(n-2, dir);
            }else{
                rotate(n-1, dir * -1);
            }
        }
        rotate(n, dir);
    }else{
        if(s[n][6] != s[n-1][2]){
            if(s[n-1][6] != s[n-2][2]){
                if(s[n-2][6] != s[n-3][2]){
                    rotate(n - 1, dir * -1);
                    rotate(n - 2, dir);
                    rotate(n - 3 , dir*-1);
                }else{
                    rotate(n-1, dir * -1);
                    rotate(n-2, dir);
                }
            }else{
                rotate(n-1, dir *-1);
            }
        }
        rotate(n, dir);
    }
}

int main(){
    for(int i = 1; i < 5; i++){
        scanf("%s", s[i]);
    }

    scanf("%d", &k);
    //n극은 0, s극은 1
    while(k--){
        int num, dir;
        scanf("%d %d", &num, &dir);
        spin(num, dir);
    }
    int ans = 0;
    if(s[1][0] != '0') ans +=1;
    if(s[2][0] != '0') ans +=2;
    if (s[3][0] != '0')
        ans += 4;
    if (s[4][0] != '0')
        ans += 8;

    printf("%d\n", ans);
}