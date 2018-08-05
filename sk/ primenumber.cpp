#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;


int main(){
    bool prime[10000];

    for(int i = 2; i < 10000; i++) prime[i] = true;

    for(int i = 2; i < sqrt(10000); i++){
        if(prime[i]){
            for(int j = i*i; j <= 10000; j+=i){
                prime[j] = false;
            }
        }
    }
}