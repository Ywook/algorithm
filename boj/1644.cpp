#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


int main(){
    int n;

    scanf("%d", &n);
    vector<bool> prime(n+1);
    vector<int> a;
    for(int i = 2; i <= n; i++){
        if(prime[i] == false){
            a.push_back(i);
            for(int j = i*i; i <= n; j += i){
                prime[j] = true;
            }
        }
    }
    

}