#include<iostream>
#include<cstdio>

using namespace std;

typedef struct{
    int node[100004];
    int size;
}Heap;

void insert_heap(Heap* h, int item){
    int i = h->size + 1;
    h->size++;

    while(i != 1 && item < h->node[i/2]){
        h->node[i] = h->node[i/2];
        i/=2;
    }
    h->node[i] = item;
    return;

}
void remove_heap(Heap* h){
    int item = h->node[1]; 
    int parent = 1;
    int child = 2;

    int temp = h->node[1] = h->node[h->size];
    h->size--;

    while(child <= h->size){
        if(child < h->size && h->node[child] > h->node[child+1]){
            child++;
        }
        if(temp <= h->node[child]){
            break;
        }
        h->node[parent] = h->node[child];
        parent = child;
        child *= 2;
    }
    h->node[parent] = temp;
    printf("%d\n", item);
}
int main(){
    int n;
    Heap heap;
    heap.size = 0;
    scanf("%d",&n);

    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d",&x);

        if(x == 0){
            if(heap.size == 0){
                printf("0\n");
            }else{
                remove_heap(&heap);
            }
        }else{
            insert_heap(&heap, x);
        }
    }
}