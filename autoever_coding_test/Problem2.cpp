#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<int> arr, int n)
{
    bool answer = false;
    int left = 0;
    int right = arr.size()-1;
    
    sort(arr.begin(), arr.end());

    while(left < right){
        int temp = arr[left] + arr[right];

        if(temp == n){
            answer = true;
            break;
        }else if(temp > n){
            right -= 1;
        }else{
            left += 1;
        }
    }
    return answer;
}

int main(){
    if(solution({5,3,9,13}, 8)){
        cout<<"TRUE"<<endl;
    }else{
        cout << "false" << endl;
    }
}