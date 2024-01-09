#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct Node *createTree(){
    int data;
    printf("enter data : ");
    scanf("%d",&data);

    if(data==-1){
        return NULL;
    }

    struct Node *root=createNode(data);

    printf("enter the data on left of %d\n",data);
    root->left=createTree();

    printf("enter the data on right of %d\n",data);
    root->right=createTree();

    return root;
}

struct Node *createBst(struct Node *root,int k){
    struct Node *temp;
    if(root==NULL){
        return createNode(k);
    }
    if(k<root->data){
        root->left=createBst(root->left,k);
    }
    else if(k>root->data){
        root->right=createBst(root->right,k);
    }
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

struct Node *delete(struct Node *root,int key){
    struct Node *temp=NULL;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(key < root->data){
        root->left=delete(root->left,key);
    }
    else if(key > root->data){
        root->right=delete(root->right,key);
    }
    else{
        if(height(root->left)>height(root->right)){
            temp=inPre(root->left);
            root->data=temp->data;
            root->left=delete(root->left,temp->data);
        }
        else{
            temp=inSucc(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}

struct Node *search(struct Node *root,int key){
    struct Node *temp=root;
    while(temp!=NULL){
        if(key==temp->data){
            return temp;
        }
        else if(key < temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }

    return NULL;
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
    // root=createTree();
    root=createBst(root,20);
    root=createBst(root,30);
    root=createBst(root,50);
    root=createBst(root,40);
    root=createBst(root,60);
    inorder(root);
    delete(root,20);
    printf("\n");
    inorder(root);
    struct Node *temp = search(root,20);
    if(temp==NULL){
        printf("not found\n");
    }
    else{
        printf("\n%d found\n",temp->data);
    }
    printf("height : %d\n",height(root));
    return 0;
}