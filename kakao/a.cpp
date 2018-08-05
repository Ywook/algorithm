#include<iostream>
#include<cstdio>

int festival1[6] = {5000000, 3000000, 2000000, 500000, 300000, 100000};
int festival2[5] = {5120000, 2560000, 1280000, 640000, 320000};
int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int ans = 0;
        int a, b;
        scanf("%d %d", &a, &b);

        if(a==1) ans += festival1[0];
        else if(1 < a && a < 4) ans += festival1[1];
        else if(3 < a && a < 7) ans += festival1[2];
        else if(6 < a && a < 11)ans += festival1[3];
        else if(10 < a && a < 16) ans += festival1[4];
        else if(15 < a && a < 22) ans += festival1[5];

        if(b==1) ans += festival2[0];
        else if(1 < b && b < 4) ans += festival2[1];
        else if(3 < b && b < 8) ans += festival2[2];
        else if(7 < b && b < 16) ans += festival2[3];
        else if(15 < b && b < 32) ans += festival2[4];

        printf("%d\n", ans);

    }   
    return 0;
}