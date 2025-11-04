#include <stdio.h>
#include "stack.h"

void test_stack(void) {
    SeqStack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top = %d\n", getTop(&s));

    printf("Pop = %d\n", pop(&s));
    printf("Pop = %d\n", pop(&s));
    printf("Pop = %d\n", pop(&s));
}
