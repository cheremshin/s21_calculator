#include "translator.h"


void process_number(char *string, int *i, stack_c *out) {
    while (is_digit(string[*i])) {
        push(out, string[(*i)++]);
    }
}

void set_space(stack_c *out) {
    if (is_digit(peek(out))) {
        push(out, 0);
    }
}

void process_prefix_function(char *string, int *i, stack_c *operations) {
    push(operations, string[(*i)++]);
}

void process_close_bracket(char *string, int *i, stack_c *operations, stack_c *out) {
    while (peek(operations) != '(' && peek(operations) != 0) {
        push(out, pop(operations));
    }
    pop(operations);
    (*i)++;
}

void process_binary_operation(char *string, int *i, stack_c *operations, stack_c *out) {
    while ((is_prefix_function(peek(operations))) ||
           (get_priority(peek(operations)) >= get_priority(string[*i])) ||
           ((peek(operations) != '^') && (get_priority(peek(operations)) == get_priority(string[*i])))) {
        push(out, pop(operations));
    }

    push(operations, string[(*i)++]);
}
