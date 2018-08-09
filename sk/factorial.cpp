#include<cstdio>
#include<iostream>


using namespace std;
int a[200] = {1}, b[3] = {0}, c[205] = {0};
int main()
{
    int factorial = 100;

    int i,j,k;
    for(i = 1; i<=100; i++){
        b[0] = i;

        for(j = 0; j < 2; j++){
            b[j+1] += b[j]/10;
            b[j] -= (b[j]/10)*10;
        }

        for(j = 0; j < 3; j++){
            for(k = 0; k < 200; k++){
                c[j+k] += a[k] * b[j];
            }
        }

        for(j = 0; j < 199; j++){
            c[j+1]+= c[j]/10;
            c[j] -= (c[j]/10)*10;
        }

        for(j = 0; j < 200; j++){
            a[j] = c[j];
            c[j] = 0;
        }

        for(j = 0; j < 3; j++) {b[j] = 0;}

        j = 199;

        while(a[j--]== 0);
        printf("%3d : ", i);
        for(j = j +1; j >= 0; j--){
            printf("%d", a[j]);
        }
        puts("");
    }
}