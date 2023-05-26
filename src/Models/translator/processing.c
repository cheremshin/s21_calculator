#include "translator.h"


void process_number(char *string, int *i, stack_t *out) {
    while (is_digit(string[*i]) || is_dot(string[*i])) {
        push(out, &string[(*i)++]);
    }
}

void set_space(stack_t *out) {
    char value;

    peek(out, &value);
    if (is_digit(value)) {
        value = SEPARATOR;
        push(out, &value);
    }
}

void process_x(char *string, int *i, stack_t *out) {
    push(out, &string[(*i)++]);
}

void process_prefix_function(char *string, int *i, stack_t *operations) {
    push(operations, &string[(*i)++]);
}

void process_close_bracket(char *string, int *i, stack_t *operations, stack_t *out) {
    char value;
    peek(operations, &value);
    
    while (!is_open_bracket(value) && operations->top != 0) {
        pop(operations, &value);
        push(out, &value);
        peek(operations, &value);
    }

    pop(operations, &value); // Pop open bracket
    (*i)++;
}

void process_binary_operation(char *string, int *i, stack_t *operations, stack_t *out) {
    char stack_top;

    peek(operations, &stack_top);
    if (!is_open_bracket(stack_top)) {
        peek(operations, &stack_top);
        char op = string[*i];

        while ((is_prefix_function(stack_top)) ||
              ((get_priority(stack_top) >= get_priority(op)) && !is_open_bracket(stack_top))) {
            pop(operations, &stack_top);
            push(out, &stack_top);
            peek(operations, &stack_top);
        }
    }

    push(operations, &string[(*i)++]);
}
