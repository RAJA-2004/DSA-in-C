#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* create(int data){
    struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorder(struct tree* root){
    struct tree* stack[100];
    int top=-1;
    while(root!=NULL || top!=-1){
        while(root!=NULL){
            printf("%d ",root->data);
            stack[++top]=root;
            root=root->left;
        }
        root=stack[top--];
        root=root->right;
    }
}

struct tree* bst(){
    int data;
    printf("enter data : ");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    struct tree* root=create(data);
    root->left=bst();
    root->right=bst();
    return root;
}

int main(){
    struct tree* root=bst();
    inorder(root);
}