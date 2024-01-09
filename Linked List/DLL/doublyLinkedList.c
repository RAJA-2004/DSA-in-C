#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};

struct Node* createNode(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void insertAtBegin(struct Node **head,int data){
    struct Node *temp=createNode(data);
    if(*head==NULL){
        *head=temp;
    }
    else{
        temp->next=*head;
        (*head)->prev=temp;
        *head=temp;
    }
}

void insertAtEnd(struct Node **head,int data){
    struct Node *temp=createNode(data);
    struct Node *trav=*head;
    while(trav->next!=NULL){
        trav=trav->next;
    }
    temp->prev=trav;
    trav->next=temp;
}

void insertAtValue(struct Node **head,int data,int k){
    struct Node *temp=createNode(data);
    struct Node *trav=*head;
    while(trav->next->data!=k){
        trav=trav->next;
    }
    temp->next=trav->next;
    temp->prev=trav;
    trav->next->prev=temp;
    trav->next=temp;
}

void deleteAtValue(struct Node **head,int k){
    struct Node *trav=*head;
    while(trav->next->data!=k){
        trav=trav->next;
    }
    struct Node *temp=trav->next;
    trav->next=trav->next->next;
    trav->next->next->prev=trav;
    temp->next=NULL;
    temp->prev=NULL;
    free(temp);
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
    struct Node *first=createNode(10);
    struct Node *second=createNode(20);
    struct Node *third=createNode(30);
    struct Node *fourth=createNode(40);
    struct Node *fifth=createNode(50);

    head=first;
    first->prev=NULL;
    first->next=second;
    second->prev=first;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;
    fourth->next=fifth;
    fifth->prev=fourth;
    fifth->next=NULL;

    display(head);
    insertAtEnd(&head,100);
    insertAtBegin(&head,100);
    insertAtValue(&head,100,30);
    display(head);
    deleteAtValue(&head,40);
    display(head);
    return 0;

}