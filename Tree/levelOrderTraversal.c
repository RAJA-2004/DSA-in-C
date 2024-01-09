#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct QueueNode {
    struct Node *data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
    int size;
};

void createQueue(struct Queue *q1) {
    q1->front = q1->rear = NULL;
    q1->size = 0;
}

void enQueue(struct Queue *q1, struct Node *data) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (q1->rear == NULL) {
        q1->front = q1->rear = newNode;
    } else {
        q1->rear->next = newNode;
        q1->rear = newNode;
    }

    q1->size++;
}

struct Node *deQueue(struct Queue *q1) {
    if (q1->front == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }

    struct QueueNode *tempNode = q1->front;
    struct Node *data = tempNode->data;
    
    q1->front = q1->front->next;
    free(tempNode);

    if (q1->front == NULL) {
        q1->rear = NULL;
    }

    q1->size--;

    return data;
}

int isEmpty(struct Queue *q1) {
    return q1->front == NULL;
}

struct Node *createNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *createTree() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node *root = createNode(data);

    printf("Enter data for left subtree of %d\n", data);
    root->left = createTree();

    printf("Enter data for right subtree of %d\n", data);
    root->right = createTree();

    return root;
}

void levelOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }

    struct Queue q1;
    createQueue(&q1);

    // initialize
    enQueue(&q1, root);
    enQueue(&q1,NULL);

    while (!isEmpty(&q1)) {

        // step A
        struct Node *temp = deQueue(&q1);

        if(temp==NULL){
            printf("\n");
            if(isEmpty(&q1)){
                enQueue(&q1,NULL);
            }
        }
        else{
            // step B
            printf("%d ", temp->data);
            // step C
            if (temp->left) {
                enQueue(&q1, temp->left);
            }
            // step D
            if (temp->right) {
                enQueue(&q1, temp->right);
            }
        }
    }
}

// 20 40 60 -1 80 -1 -1 -1 -1

int main() {
    struct Node *root = NULL;
    root = createTree();
    printf("Level Order Traversal: ");
    printf("\n");
    levelOrderTraversal(root);
    printf("\n");
    return 0;
}
