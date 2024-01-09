#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *creataeNode(int data){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void insertAtBeg(struct Node **head,int data){
    struct Node *temp=creataeNode(data);
    struct Node *trav=*head;
    // 10 20 30 
    do{
        trav=trav->next;
    }while(trav->next!=*head);
    temp->next=*head;
    trav->next=temp;
    *head=temp;
}

void display(struct Node *head){
    struct Node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

int main(){
    struct Node *head=NULL;
    struct Node *first=creataeNode(10);
    struct Node *second=creataeNode(20);
    struct Node *third=creataeNode(30);

    head=first;
    first->next=second;
    second->next=third;
    third->next=first;

    display(head);

    insertAtBeg(&head,100);

    display(head);

    return 0;
}