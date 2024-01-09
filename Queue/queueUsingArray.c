#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data,size,*arr,front,rear;
};

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void pushQueue(struct Node **head,int data){
    struct Node *temp=*head;
    struct Node *newNode=createNode(data);
    if(temp==NULL){
        printf("queue is full \n");
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void popQueue(struct Node **head){
    struct Node *temp=*head;
    if(temp==NULL){
        printf("queue is empty \n");
    }
    *head=(*head)->next;
    temp->next=NULL;
    free(temp);
}

void Display(struct Node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void createQueue(struct queue *q1){
    printf("enter the size : ");
    scanf("%d",&q1->size);
    q1->front=-1;
    q1->rear=-1;
    q1->arr=(int *)malloc(q1->size*(sizeof(int)));
}

void enqueue(struct queue *q1,int data){
    if(q1->rear==q1->size-1){
        printf("queue is full \n");
    }
    q1->rear=(q1->rear+1)%q1->size;
    q1->arr[q1->rear]=data;
}

void dequeue(struct queue *q1){
    if(q1->front==q1->rear){
        printf("queue is empty \n");
    }
    else{
        q1->front=(q1->front+1)%q1->size;
    }
}

void display(struct queue *q1){
    for(int i=q1->front+1;i<=q1->rear;i++){
        printf("%d ",q1->arr[i]);
    }
    printf("\n");
}

int main(){
    struct queue *q1;
    // createQueue(q1);
    // enqueue(q1,10);
    // enqueue(q1,20);
    // enqueue(q1,30);
    // enqueue(q1,40);
    // display(q1);
    // dequeue(q1);
    // dequeue(q1);
    // display(q1);
    struct Node *head=NULL;
    struct Node *first=createNode(10);
    struct Node *second=createNode(20);
    struct Node *third=createNode(30);

    head=first;
    first->next=second;
    second->next=third;
    third->next=NULL;
    Display(head);
    pushQueue(&head,40);
    Display(head);
    popQueue(&head);
    Display(head);
    popQueue(&head);
    Display(head);
    popQueue(&head);
    Display(head);
    popQueue(&head);
    Display(head);


    return 0;
}