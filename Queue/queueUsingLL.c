#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
    int size;
};

struct Node *createNode(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void createQueue(struct Queue *q1){
    q1->front=NULL;
    q1->rear=NULL;
    q1->size=0;
}

void enQueue(struct Queue *q1,int data){
    struct Node *newNode = createNode(data);
    struct Node *temp = q1->front;
    if(temp==NULL){
        q1->front=newNode;
        q1->rear=newNode;
        q1->size++;
    }
    else{
        q1->rear->next=newNode;
        q1->rear=newNode;
        q1->size++;
    }
}

void deQueue(struct Queue *q1){
    struct Node *temp=q1->front;
    if(temp==NULL){
        printf("Queue is empty \n");
    }
    else{
        q1->front=q1->front->next;
        q1->size--;
        free(temp);
    }
}

int size(struct Queue *q1){
    return q1->size==0;
}

void display(struct Queue *q1){
    struct Node *temp=q1->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue *q1;
    createQueue(q1);
    enQueue(q1,10);
    enQueue(q1,20);
    enQueue(q1,30);
    display(q1);
    deQueue(q1);
    deQueue(q1);
    deQueue(q1);
    display(q1);

    printf("size of Queue : %d \n",q1->size);
    return 0;
}