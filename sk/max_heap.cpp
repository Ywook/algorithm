#include <iostream>
#include <cstdio>
#include <cstring>

typedef struct
{
    int node[200004];
    int size;
} Heap;

void insert_heap(Heap *h, int item)
{
    int i;
    i = h->size + 1;
    h->size++;
    while ((i != 1) && item > h->node[i / 2])
    {
        h->node[i] = h->node[i / 2];
        i /= 2;
    }
    h->node[i] = item;
}

void remove(Heap *h)
{
    int parent, child;
    int item, temp;

    item = h->node[1];
    temp = h->node[h->size];
    h->size--;

    parent = 1;
    child = 2;

    while (child <= h->size)
    {
        if (child < h->size && h->node[child] < h->node[child + 1])
        {
            child++;
        }
        if (temp >= h->node[child])
        {
            break;
        }
        h->node[parent] = h->node[child];
        parent = child;
        child = parent * 2;
    }
    h->node[parent] = temp;
    printf("%d\n", item);
}
int main()
{
    int n;
    Heap heap;
    heap.size = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);

        if (t == 0)
        {
            if (heap.size == 0)
            {
                printf("0\n");
            }
            else
            {
                remove(&heap);
            }
        }
        else
        {
            insert_heap(&heap, t);
        }
    }
}