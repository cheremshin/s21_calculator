#include "stack.h"


stack_t *init_stack(int type_id) {
    stack_t *out = NULL;

    out = malloc(sizeof(stack_t));

    if (out == NULL) {
        perror("init_stack");
    } else {
        out->size = INIT_SIZE;
        out->top = 0;
        out->data = malloc(out->size * sizeof(generic_data_t));

        if (out->data == NULL) {
            free(out);
            perror("init_stack");
        } else {
            out->data->type_id = type_id;
        }
    }

    return out;
}

void delete_stack(stack_t **stack) {
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize_stack(stack_t *stack) {
    generic_data_t *tmp = realloc(stack->data,
                                  stack->size * MULTIPLIER * sizeof(generic_data_t));
    
    if (tmp == NULL) {
        perror("resize_stack");
    } else {
        stack->data = tmp;
        stack->size *= MULTIPLIER;
    }
}

void push(stack_t *stack, generic_data_t value) {
    if (stack->top == stack->size) {
        resize_stack(stack);
    }

    if (stack->data->type_id == value.type_id) {
        stack->data[stack->top++] = value;
    }
}

generic_data_t *pop(stack_t *stack) {
    generic_data_t *out = NULL;

    if (stack->top > 0) {
        stack->top--;
        out = &stack->data[stack->top];
    }

    return out;
}

generic_data_t *peek(stack_t *stack) {
    generic_data_t *out = NULL;

    if (stack->top > 0) {
        out = &stack->data[stack->top - 1];
    }

    return out;
}
