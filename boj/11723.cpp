#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int m, n;
    scanf("%d", &m);
    char str[30];
    int ans = 0;
    while(m--){
        scanf("%s", str);
        if(!strcmp(str, "add")){
            scanf("%d", &n); n--;
            ans = (ans|(1 << n));
        }else if(!strcmp(str, "remove")){
            scanf("%d", &n); n--;
            ans = (ans & ~(1 << n));
        }else if(!strcmp(str, "check")){
            scanf("%d", &n); n--;
            int res = (ans & (1 << n));
             if (res)
            {
                printf("1\n");
            }else{
                printf("0\n");
            }
        }else if(!strcmp(str, "toggle")){
            scanf("%d", &n); n--;
            ans = (ans ^ (1 << n));
        }else if(!strcmp(str, "all")){
            ans = (1 << 20) -1;
        }else if(!strcmp(str, "empty")){
            ans = 0;
        }
    }
    return 0;
}