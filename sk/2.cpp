#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
    int count;
}Queue;

void InitQueue(Queue *queue){
    queue->front = queue->rear = NULL;
    queue->count = 0;
}
int IsEmpty(Queue *queue){
    return queue->count == 0;
}

void Enqueue(Queue *queue, int data){
    Node *cur = (Node *)malloc(sizeof(Node));
    cur->data = data;
    cur->next = NULL;

    if(IsEmpty(queue)){
        queue->front = cur;
    }else{
        queue->rear->next = cur;
    }
    queue->rear = cur;
    queue->count++;
}

void Dequeue(Queue *queue){
    if(IsEmpty(queue)) {
        printf("NULL\n");
        return;
    }

    Node* temp = queue->front;
    queue->front = temp->next;

    printf("%d\n", temp->data);
    free(temp);
    queue->count--;
}

int main(void){
    Queue queue;
    
    InitQueue(&queue);
    for(int i = 1; i <= 5; i++) Enqueue(&queue, i);

    while(!IsEmpty(&queue)){
        Dequeue(&queue);
    }

    for(int i =1 ; i<= 3; i++) Enqueue(&queue, i);
    for(int i = 0; i < 4; i++) Dequeue(&queue);
    
    Enqueue(&queue, 10);

    while (!IsEmpty(&queue))
    {
        Dequeue(&queue);
    }

    return 0;
}