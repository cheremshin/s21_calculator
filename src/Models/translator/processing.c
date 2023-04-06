#include "translator.h"


void process_number(char *string, int *i, stack *out) {
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    while (is_digit(string[*i])) {
        set_char(&char_data, string[(*i)++]);
        push(out, char_data);
    }
}

void set_space(stack *out) {
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    char out_top = out->top > 0 ? get_char(*peek(out)) : 0;
    if (is_digit(out_top)) {
        set_char(&char_data, 0);
        push(out, char_data);
    }
}

void process_prefix_function(char *string, int *i, stack *operations) {
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    set_char(&char_data, string[(*i)++]);
    push(operations, char_data);
}

void process_close_bracket(char *string, int *i, stack *operations, stack *out) {
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    set_char(&char_data, get_char(*pop(operations)));
    while (get_char(char_data) != '(') {
        push(out, char_data);
        set_char(&char_data, get_char(*pop(operations)));
    }
}

void process_binary_operation(char *string, int *i, stack *operations, stack *out) {
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    char stack_top = operations->top > 0 ? get_char(*peek(operations)) : 0;
    while ((is_prefix_function(stack_top)) ||
           (get_priority(stack_top) >= get_priority(string[*i])) ||
           ((stack_top != '^') && (get_priority(stack_top) == get_priority(string[*i])))) {
        set_char(&char_data, get_char(*pop(operations)));
        push(out, char_data);
        stack_top = operations->top > 0 ? get_char(*peek(operations)) : 0;
    }

    set_char(&char_data, string[(*i)++]);
    push(operations, char_data);
}
