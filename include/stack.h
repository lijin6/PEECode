#ifndef STACK_H
#define STACK_H

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int top;
} SeqStack;

void initStack(SeqStack *s);
int isEmpty(SeqStack *s);
void push(SeqStack *s, int x);
int pop(SeqStack *s);
int getTop(SeqStack *s);

#endif
