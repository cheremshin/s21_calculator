#include "stack.h"


char get_char(generic_data data) {
    return data.value.c;
}

double get_double(generic_data data) {
    return data.value.d;
}

void set_char(generic_data *data, char value) {
    data->value.c = value;
    data->type_id = CHAR_TYPE_ID;
}

void set_double(generic_data *data, double value) {
    data->value.d = value;
    data->type_id = DOUBLE_TYPE_ID;
}

stack *init_stack(int type_id) {
    stack *out = NULL;

    out = malloc(sizeof(stack));

    if (out == NULL) {
        perror("init_stack");
    } else {
        out->size = INIT_SIZE;
        out->top = 0;
        out->data = malloc(out->size * sizeof(generic_data));

        if (out->data == NULL) {
            free(out);
            perror("init_stack");
        } else {
            out->data->type_id = type_id;
        }
    }

    return out;
}

void delete_stack(stack **stack) {
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize_stack(stack *stack) {
    generic_data *tmp = realloc(stack->data,
                                  stack->size * MULTIPLIER * sizeof(generic_data));
    
    if (tmp == NULL) {
        perror("resize_stack");
    } else {
        stack->data = tmp;
        stack->size *= MULTIPLIER;
    }
}

void push(stack *stack, generic_data value) {
    if (stack->top == stack->size) {
        resize_stack(stack);
    }

    if (stack->data->type_id == value.type_id) {
        stack->data[stack->top++] = value;
    }
}

generic_data *pop(stack *stack) {
    generic_data *out = NULL;

    if (stack->top > 0) {
        stack->top--;
        out = &stack->data[stack->top];
    }

    return out;
}

generic_data *peek(stack *stack) {
    generic_data *out = NULL;

    if (stack->top > 0) {
        out = &stack->data[stack->top - 1];
    }

    return out;
}
