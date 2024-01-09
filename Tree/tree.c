#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}*root=NULL;

struct Node *createNode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct Node *createTree(){

    int data;
    printf("enter the data : ");
    scanf("%d",&data);

    // base condition for Recursion
    if(data==-1){
        return NULL;
    }

    // steps A create node
    struct Node *root = createNode(data);

    // step B left part recursion
    printf("enter data for left part of %d\n",data);
    root->left=createTree();

    // step C right part recursion
    printf("enter data for right part of %d\n",data);
    root->right=createTree();

    return root;
}

int height(struct Node *root){
    int x,y; 
    if(root==NULL){
        return 0;
    }
    x=height(root->left);
    y=height(root->right);
    return x>y?x+1:y+1; 
}

struct Node *inPre(struct Node *root){
    while(root && root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct Node *inSucc(struct Node *root){
    while(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node *delete(struct Node *r,int key){
    struct Node *temp;
    if(r==NULL){
        return NULL;
    }
    if(r->left==NULL && r->right==NULL){
        if(root==r){
            root= NULL;
        }
        free(r);
        return NULL;
    }
    if(key < r->data){
        r->left=delete(r->left,key);
    }
    else if(key > r->data){
        r->right=delete(r->right,key);
    }
    else{
        if(height(r->left)>height(r->right)){
            temp=inPre(r->left);
            r->data=temp->data;
            r->left=delete(r->left,temp->data);
        }
        else{
            temp=inSucc(r->right);
            r->data=temp->data;
            r->right=delete(r->right,temp->data);
        }
    }
    return r;
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node *root=NULL;
    root=createTree();
    inorder(root);
    delete(root,0);
    printf("\n");
    inorder(root);
    return 0;
}

// 25 20 10 5 1 -1 -1 8 -1 -1 12 -1 15 -1 -1 -1 22 -1 36 30 28 -1 -1 -1 40 38 -1 -1 48 45 -1 -1 50 -1 -1 