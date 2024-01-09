#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char *arr;
};

void createStack(struct stack *s1, char exp[]) {
    s1->top = -1;
    s1->size = 100;
    s1->arr = (char *)malloc(s1->size * sizeof(char));
}

void push(struct stack *s1, char c) {
    if (s1->top == s1->size - 1) {
        printf("stack overflow\n");
    } else {
        s1->top++;
        s1->arr[s1->top] = c;
    }
}

char pop(struct stack *s1) {
    if (s1->top == -1) {
        printf("stack is empty\n");
        return '\0'; 
    } else {
        char popped = s1->arr[s1->top];
        s1->top--;
        return popped;
    }
}

void validParenthesis(struct stack *s1, char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(s1, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char popped = pop(s1);
            if (exp[i] == ')' && popped != '(') {
                printf("Invalid parenthesis\n");
                return;
            } else if (exp[i] == ']' && popped != '[') {
                printf("Invalid square brackets\n");
                return;
            } else if (exp[i] == '}' && popped != '{') {
                printf("Invalid curly braces\n");
                return;
            }
        }
    }

    if (s1->top == -1) {
        printf("Valid parenthesis\n");
    } else {
        printf("Invalid parenthesis\n");
    }
}

int main() {
    struct stack s1;  
    char exp[] = "{(((a+b)*(c+d)))}";
    createStack(&s1, exp);
    validParenthesis(&s1, exp);
    free(s1.arr);  
    return 0;
}
