#include<stdio.h>
#include<stdlib.h>

#define LEN 33

typedef int Data;

typedef struct Stack{
    Data arr[LEN];
    int top;
}Stack;

void stack_init(Stack *S){
    S->top = -1;
}

bool isEmpty(Stack *S){
    if(S -> top == -1)
        return true;
    else
        return false;
}

void push(Stack *S, Data data){
    S->top += 1;
    S->arr[S->top] = data;
}

void pop(Stack *S){
    if(isEmpty(S) == true){
        printf("Null");
        exit(-1);
    }

    S->top -= 1;
    return;
}

void print(Stack *S){
    int i;
    if(isEmpty(S) == true){
        printf("NULL");
        exit(-1);
    }

    for(i = 0 ;i < (S->top) +1; i++){
        printf("%d\n", S->arr[i]);
    }
    return;
}

void make_queue(Stack *S, int len)
{
    if(len == 1){
        printf("%d\n", S->arr[len-1]);
        return;
    }
    make_queue(S, len-1);
    printf("%d\n", S->arr[len-1]);
}

int main()
{
    Stack S;
    stack_init(&S);
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        push(&S, (i+1));
    }
    make_queue(&S, n);
// make_queue 함수 호출
    return 0;
}
