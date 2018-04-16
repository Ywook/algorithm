#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void merge(vector<int> *arr, int left, int mid, int right)
{
    int i, j, k, m;

    i = left;
    j = mid + 1;
    k = left;
    
    vector<int> temp;
    temp.clear();
    while(i <= mid && j <= right){
        if ((*arr)[i] < (*arr)[j])
        {
            temp.push_back((*arr)[i]);
            i++;
        }else{
            temp.push_back((*arr)[j]);
            j++;
        }
        k++;
    }

    while(i <= mid){
        temp.push_back((*arr)[i]);
        i++;
    }

    while(j <= right){
        temp.push_back((*arr)[j]);
        j++;
    }
    int e = 0;
    for(i = left; i <=right; i++){
        (*arr)[i] = temp[e];
        e++;

    }
}

void merge_sort(vector<int> *arr, int left, int right){
    int mid;
    
    if(left < right){
        mid = (left + right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
        for (int i = 0; i < 6; i++)
        {
            cout << (*arr)[i] << " ";
        }
        cout<<endl;
    }
}

int main(){

    vector<int> arr = {3,8,0, 2, 1,4};
    merge_sort(&arr, 0, 5);

    for(int i = 0 ; i < arr.size(); i ++){
        cout<<arr[i]<<endl;
    }
}