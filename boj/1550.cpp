#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
    char str[20];
    scanf("%s", str);
    int sum = 0;
    int alpha = 1;
    int n = strlen(str);
    int temp;
    for(int i = n-1; i > -1 ; i--){
        if(str[i] > '9'){
            temp = 10 + str[i] - 'A';
        }else{
            temp = str[i] -'0';
        }
        sum += pow(16,(n-1)-i)*temp;
    }
    printf("%d\n", sum);
    return 0;
}