#include<cstdio>
#include<iostream>

using namespace std;

typedef struct Double_Linked_List{
    int count;
    struct Node *start;
    struct Node *end;
}Double_Linked_List;

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

void init_Linekd_List(Double_Linked_List *L){
    L->start = L->end = NULL;
    L->count = 0;
}

int isEmpty(Double_Linked_List *L){
    return L->count == 0;
}

void insertLast(Double_Linked_List *L, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(isEmpty(L)){

    }else{
        newNode->next = NULL;

        L->end->next = newNode;
        newNode->prev = L->end;

        L->end = newNode;
    }
    L->count++;
}

void removeFirst(Double_Linked_List *L){
    Node* temp = L->start;
    
    Node* newheader = L->start->next;
    newheader->prev = NULL;

    L->start = newheader;

    temp->prev = NULL;
    temp->next = NULL;

    free(temp);
}

void search_Node(Double_Linked_List *L, int data){
    Node* temp = L->start;
    int index = 0;
    while(temp != NULL){
        if(temp->data == data){
            if(temp == L->start){
                L->start = L->start->next;
                L->start->prev = NULL;

                temp->prev = L->end;
                temp->next = NULL;

                L->end->next = temp;
                L->end = temp;
            }else if(){
                
            }
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            temp->prev = NULL;
            temp->next = L->start;
            
            L->start->prev =temp;

            L->start = temp;
            printf("index : %d 찾았땅!\n", index);
        }
        index++;
        temp = temp->next;

    }
    printf("없땅!\n");
    return;
}

int main(){
    Double_Linked_List L;

    init_Linekd_List(&L);

    insert
}