#include <stdio.h>
#include <stdlib.h>

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

int getLength(struct Node **head){
    struct Node *temp=*head;
    int count=0;
    while(temp!=NULL){
        count++;
    }
    return count;
}

void push(struct Node **head,int data){
    struct Node *trav=*head;
    struct Node *temp=createNode(data);
    if(*head==NULL){
        *head=temp;
    }
    else{
        temp->next=trav;
        *head=temp;
    }
}

void pop(struct Node **head){
    struct Node *temp=*head;
    *head=(*head)->next;
    temp->next=NULL;
    free(temp);
}

void reverse(struct Node **head){
    struct Node *currNode=*head;
    struct Node *prev=NULL;
    struct Node *forward=NULL;
    // 10 20 30 40 50 
    while(currNode!=NULL){
        forward=currNode->next;
        currNode->next=prev;
        prev=currNode;
        currNode=forward;
    }
    *head=prev;
}

void display(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct Node *head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    display(head);
    pop(&head);
    // display(head);
    // reverse(&head);
    display(head);
    return 0;
}

// 40 30 20 10