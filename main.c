#include <stdio.h>
#include "list.h"

int main () {

    List queue;
    List stack;

    init(&stack);
    init(&queue);

    push_last(&queue, 1);
    push_last(&queue, 2);
    push_last(&queue, 3);
    push_last(&queue, 4);

    push_last(&stack, 1);
    push_last(&stack, 2);
    push_last(&stack, 3);
    push_last(&stack, 4);

    print_list(queue);
    print_list(stack);

    printf("queue pop element: %d\n", pop_first(&queue));
    printf("stack pop element: %d\n", pop_last(&stack));

    print_list(queue);
    print_list(stack);

    free_list(&queue);

    return 0;
}