#include "stack.h"


stack_c *init_stack(int type) {
    stack_c *stack = malloc(sizeof(stack_c));

    stack->size = INIT_SIZE;
    stack->top = 0;
    stack->type = type;
    stack->elements = (stack_element *)malloc(stack->size * sizeof(stack_element));

    return stack;
}

void delete_stack(stack_c **stack) {
    free((*stack)->elements);
    free(*stack);
    *stack = NULL;
}

void resize_stack(stack_c *stack) {
    stack_element *tmp = realloc(stack->elements,
                        stack->size * MULTIPLIER * sizeof(stack_element));
    
    if (tmp != NULL) {
        stack->elements = tmp;
        stack->size *= MULTIPLIER;
    }
}

int is_empty_stack(stack_c *stack) {
    return (stack->top == 0);
}

void push(stack_c *stack, void *value) {
    if (stack->top == stack->size) {
        resize_stack(stack);
    }

    switch (stack->type)
    {
    case CHAR_TYPE:
        stack->elements[stack->top++].data.value_c = *((char *) value);
        break;
    case DOUBLE_TYPE:
        stack->elements[stack->top++].data.value_d = *((double *) value);
    }
}

void pop(stack_c *stack, void *p) {
    if (stack->top > 0) {
        stack->top--;

        switch (stack->type)
        {
        case CHAR_TYPE:
            *((char *) p) = stack->elements[stack->top].data.value_c;
            break;
        case DOUBLE_TYPE:
            *((double *) p) = stack->elements[stack->top].data.value_d;
            break;
        }
    }
}

void peek(stack_c *stack, void *p) {
    if (stack->top > 0) {
        switch (stack->type)
        {
        case CHAR_TYPE:
            *((char *) p) = stack->elements[stack->top - 1].data.value_c;
            break;
        case DOUBLE_TYPE:
            *((double *) p) = stack->elements[stack->top - 1].data.value_d;
            break;
        }
    }
}

void transfer_data(stack_c *source, stack_c *destination) {
    void *value = malloc(sizeof(double));

    while (source->top > 0) {
        pop(source, value);
        push(destination, value);
    }

    free(value);
}

void convert_to_string(stack_c *source, char *destination) {
    for (int i = 0; i < source->top; i++) {
        destination[i] = source->elements[i].data.value_c;
    }
}
