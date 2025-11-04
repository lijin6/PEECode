#include "stack.h"
#include <stdio.h>

void initStack(SeqStack *s) {
    s->top = -1;
}

int isEmpty(SeqStack *s) {
    return s->top == -1;
}

void push(SeqStack *s, int x) {
    if (s->top == MAXSIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = x;
}

int pop(SeqStack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int getTop(SeqStack *s) {
    if (s->top == -1) return -1;
    return s->data[s->top];
}
