#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int solve(char * str, int st, int et){
    while(st < et){
        if(str[st] != str[et]){
            return 0;
        }
        st++;
        et--;
    }
    return 1;
}

int main(){
    int test, len, start ;
    char str[10003];
    char str2[10003];
    scanf("%d", &test);

    int flag = 1;
    int recheck = 0;
    while(test--){
        scanf("%s", str);
        int end = strlen(str);

        recheck = 0;
        start = 0;
        flag = solve(str, 0, end-1);

        if(!flag){
            recheck = -1;
            for(int i = 0; i < end; i++){
                int index = 0;
                for(int j = 0; j < end; j++){
                    if(i!=j){
                        str2[index] = str[j];
                        index++;
                    }
                }
                flag = solve(str2, 0, strlen(str) - 2);
                if(flag) {
                    recheck = i;
                    break;
                }
            }
        }
        if(flag && recheck == 0){
            printf("%s\n", str);
        }else if(!flag){
            printf("-1\n");
        }else{
            printf("%d\n", recheck);
        }
    }
}