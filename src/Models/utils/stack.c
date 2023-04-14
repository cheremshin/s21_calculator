#include "stack.h"


stack_c *init_stack() {
    stack_c *stack = malloc(sizeof(stack_c));

    stack->size = INIT_SIZE;
    stack->top = 0;
    stack->data = malloc(stack->size * sizeof(char));

    return stack;
}

void delete_stack(stack_c **stack) {
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize_stack(stack_c *stack) {
    char *tmp = realloc(stack->data,
                        stack->size * MULTIPLIER * sizeof(char));
    
    if (tmp != NULL) {
        stack->data = tmp;
        stack->size *= MULTIPLIER;
    }
}

void push(stack_c *stack, char value) {
    if (stack->top == stack->size) {
        resize_stack(stack);
    }

    stack->data[stack->top++] = value;
}

char pop(stack_c *stack) {
    char out = 0;

    if (stack->top > 0) {
        stack->top--;
        out = stack->data[stack->top];
    }

    return out;
}

char peek(stack_c *stack) {
    char out = 0;

    if (stack->top > 0) {
        out = &stack->data[stack->top - 1];
    }

    return out;
}
