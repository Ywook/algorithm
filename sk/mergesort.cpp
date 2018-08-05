#include<iostream>
#include<cstdio>

using namespace std;

const int ITEMSIZE = 6;
int result[ITEMSIZE];

void merge(int array[], int left, int mid, int right)
{
    int i, j, k, m;

    i = left;
    j = mid + 1;
    k = left;

    int tempArray[ITEMSIZE];

    while(i <= mid && j <= right){
        if(array[i] > array[j]){
            tempArray[k++] = array[j];
            j++;
        }else{
            tempArray[k++] = array[i];
            i++;
        }
    }

    while(i <= mid){
        tempArray[k++] = array[i];
        i++;
    }
    while(j <= right){
        tempArray[k++] = array[j];
        j++;
    }

    for(m = left; m <= right; m++)
        array[m] = tempArray[m];
}

void mergesort(int array[],int left,int right){
    int mid;
    if(left < right){
        mid = (left +right)/2;
        mergesort(array, left, mid);
        mergesort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}
int main(){
    int array[ITEMSIZE] = {3, 8, 0, 2, 1, 4};
    mergesort(array, 0, ITEMSIZE-1);
    for(int a : array){
        cout<<a<<endl;
    }
    return 0;
}