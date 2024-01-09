#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    int *arr;
    int top;
    int size;
};

void createStack(struct stack *s1){
    printf("enter the stack size : ");
    scanf("%d",&s1->size);
    s1->top=-1;
    s1->arr=(int *)malloc(s1->size*(sizeof(int)));
}

void push(struct stack *s1,int data){
    if(s1->top==s1->size-1){
        printf("stack overflow \n");
    }
    else{
        s1->top++;
        s1->arr[s1->top]=data;
    }
}

void pop(struct stack *s1){
    if(s1->top==-1){
        printf("stack underflow \n");
    }
    else{
        s1->top--;
    }
}

void top(struct stack *s1){
    printf("%d\n",s1->arr[s1->top]);
}

void size(struct stack *S1){
    printf("%d\n",S1->size);
}

void display(struct stack *s1){
    for(int i=s1->top;i>=0;i--){
        printf("%d ",s1->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack *s1;
    createStack(s1);
    push(s1,10);
    push(s1,20);
    push(s1,30);
    push(s1,40);
    push(s1,10);
    display(s1);
    pop(s1);
    display(s1);
    top(s1);
    size(s1);
    return 0;
}