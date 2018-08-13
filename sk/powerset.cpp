#include<iostream>
#include<cstdio>

using namespace std;

int data[]={1,2,3,4};

void powerset(int n){
    int power = 1<<n;
    for(int i = 0; i < power; i++){
        for(int j = 0; j < n; j++){
            if(i & 1 << j){
                printf(" %d : %d ", i,data[j]);
            }
        }
        cout<<endl;
    }
}
int main(){
    powerset(4);
    return 0;
}