#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n;
    int cnt = 0;
    bool t = false;
    vector<int> v;
    cin >> n;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(), v.end());

    int i = 0;    
    while(1){

        if(i >= v.size()) break;

        if((i+1) < v.size() && v[i] > 1 && v[i+1] >1 ){
            sum += v[i]*v[i+1];
            i += 2;
        }else if((i+1) < v.size() && v[i] < 0 && v[i+1] < 0){
            for(int j = n-1; j >= i;){
                if((j-1) >= i) {
                    sum += v[j]*v[j-1];
                    j-=2;
                }
                else{
                    if(cnt > 0){
                        cnt--;
                    }
                    else{
                        sum += v[j];
                    }
                    j--;
                }
            }
            break;
        }
        else if(v[i] == 0){
            cnt++;
            i+=1;
        }
        else{
            sum += v[i];
            i += 1;
        }
    }
    cout << sum <<endl;
 }