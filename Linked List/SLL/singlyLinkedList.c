#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node* createNode(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void insertAtBeg(struct Node **head,int data){
    struct Node *temp=createNode(data);
    if(*head==NULL){
        *head=temp;
    }
    else{
        temp->next=*head;
        *head=temp;
    }
}

void insertAtEnd(struct Node **head,int data){
    struct Node *temp=createNode(data);
    struct Node *trav=*head;
    if(*head==NULL){
        *head=temp;
    }
    else{
        while(trav->next!=NULL){
            trav=trav->next;
        }
        trav->next=temp;
    }
}

void insertAtValue(struct Node **head,int data,int k){
    struct Node *temp=createNode(data);
    struct Node *trav=*head;
    if(trav->data==k){
        insertAtBeg(head,data);
    }
    else{
        while(trav->next->data!=k){
            trav=trav->next;
        }
        // 10 20 30 60 40 50
        temp->next=trav->next;
        trav->next=temp;
    }
}

void deleteSecondLast(struct Node **head,int k){
    struct Node *trav=*head;
    while(trav->next->data!=k){
        trav=trav->next;
    }
    struct Node *delNode=trav->next;
    trav->next=trav->next->next;
    delNode->next=NULL;
    free(delNode);
}

void deleteAtValue(struct Node **head,int k){
    struct Node *temp=*head;
    if(temp->data==k){
        *head=(*head)->next;
        temp->next=NULL;
        free(temp);
    }
    else{
        while(temp->next->data!=k){
            temp=temp->next;
        }
        // 10 20 30 40 50
        struct Node *trav=temp->next;
        temp->next=temp->next->next;
        free(trav);
    }
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

void RemoveDuplicate(struct Node *p)
{
 struct Node *q=p->next;
 
 while(q!=NULL)
 {
 if(p->data!=q->data)
 {
 p=q;
 q=q->next;
 }
 else
 {
 p->next=q->next;
 free(q);
 q=p->next;
 }
 }
 
}

int main(){
    
    struct Node *head=NULL;
    struct Node *first=createNode(10);
    struct Node *second=createNode(10);
    struct Node *third=createNode(30);
    struct Node *fourth=createNode(30);

    head=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    display(head);

    // insertAtBeg(&head,100);
    // insertAtEnd(&head,100);
    // display(head);
    // insertAtValue(&head,100,30);
    // display(head);
    // deleteAtValue(&head,40);
    // deleteSecondLast(&head,30);
    // display(head);

    // reverse(&head);
    RemoveDuplicate(head);
    display(head);
    return 0;
}