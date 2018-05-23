#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int arr[32];
vector<char> stack;
int main(){
    char str[32];
    scanf("%s", str);
    int k = -1;
    int len = strlen(str);
    int flag = 1;
    for(int i =0 ; i < len ; i++){
        if(str[i] == '(' || str[i] =='['){
            k++;
            if(str[i] == '(') stack.push_back(')');
            else if(str[i] == '[') stack.push_back(']');
        }else{
            int s = stack.size();
            if(s - 1 < 0 || stack[s-1] != str[i]){
                flag = 0;
                break;
            }

            if(arr[k+1] != 0){
                if(str[i] == ')'){
                    arr[k] += arr[k+1] * 2;
                }else{
                    arr[k] += arr[k+1] * 3;
                }
                arr[k+1] = 0;
            }else{
                if(str[i] == ')'){
                    arr[k] += 2;
                }
                else {
                    arr[k] += 3;
                }
            }
            k--;
            stack.pop_back();
        }
    }
    int ans = 0;
    if(!flag || stack.size()!= 0){
        cout<<0<<endl;
    }else{
        for(int i = 0; i < len; i++){
            ans += arr[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}