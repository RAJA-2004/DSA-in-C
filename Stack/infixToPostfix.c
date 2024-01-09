#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
}*head=NULL;

void push(char str){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("stack is full \n");
    }
    else{
        newNode->data=str;
        newNode->next=head;
        head=newNode;   
    }
}

char pop(){
    struct Node *temp = head;
    char popped = -1;
    if(temp==NULL){
        printf("stack is empty \n");
        return '\0';
    }
    else{
        head=(head)->next;
        popped=temp->data;
        temp->next=NULL;
        free(temp);
    }
    return popped;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' ){
        return 0;
    }
    else {
        return 1;
    }
}

int pre(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if (x=='*' || x== '/'){
        return 2;
    }
    return 0;
}

char *inTopost(char *infix){
    char *postfix;
    int i=0,j=0;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i])>pre(head->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(head!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char *infix="a+b-c*d/e"; // a+b-cd*/e a+b-cd*e/ ab+-cd*e/ ab+cd*e/-
    push(' ');
    char *postfix=inTopost(infix);
    printf("%s ",postfix);
    return 0;
}