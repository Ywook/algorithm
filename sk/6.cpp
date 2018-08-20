#include<stdio.h>


void merge(int *a, int left, int mid, int right){
    int i,j,k, m;
    
    i = m = left;
    j = mid + 1;
    int temp[13];
    while(i <= mid && j <=right){
        if(a[i] > a[j]){
            temp[m++] = a[j];
            j++;
        }else{
            temp[m++] = a[i];
            i++;
        }
    }

    while(i <= mid){
        temp[m++] = a[i++];
    }

    while(j <= right){
        temp[m++] = a[j++];
    }

    for(i = left; i <= right; i++){
        a[i] = temp[i];
    }
}

void mergesort(int *a, int left, int right){
    int mid;
    if(left < right){
        mid = (left + right)/2;
        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        merge(a, left, mid, right);
    }
    return;
}

int find_1(int *A, int len, int k){
    for(int i = 0; i < 10; i++){
        if(*(A+i) == k) return 1;
    }
    return -1;
}
int binary_search(int *A, int len, int k)
{
    int left = 0;
    int right = len-1;

    while(left <= right){
        int mid = (left+right)/2;
        if(k == *(A+mid)){
            return 1;
        }else if(k > *(A+mid)){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}

int find_2(int *A, int len, int k)
{
    mergesort(A, 0, len-1);
    // for(int i = 0; i < len; i++){
    //     for(int j = i+1; j < len; j++){
    //         if(*(A+i) > *(A+j)){
    //             int temp = *(A+j);
    //             *(A+j) = *(A+i);
    //             *(A+i) = temp;
    //         }
    //     }
    // }

    return binary_search(A, len, k);
}

int main()
{

    int arr[15] = {3, 10, 9, 1, 2, 6, 4, 8, 5, 7};
    int k;

    int ans = -1;

    scanf("%d", &k);

    ans = find_1(arr, 10, k);

    if (ans == -1)
        printf("배열에 %d이(가) 없습니다.\n", k);
    else
        printf("배열에 %d이(가) 존재합니다.\n", k);

    ans = -1;

    ans = find_2(arr, 10, k);
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    puts("");
    if (ans == -1)
        printf("배열에 %d이(가) 없습니다.\n", k);
    else
        printf("배열에 %d이(가) 존재합니다.\n", k);

    return 0;
}
