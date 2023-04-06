#include "translator.h"

stack *translate_to_polish(char *string) {
    char operation;
    stack *out = init_stack(CHAR_TYPE_ID);
    stack *operations = init_stack(CHAR_TYPE_ID);
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    for (int i = 0; string[i] != '\0'; i++) {
        if (is_digit(string[i])) {
            process_number(string, &i, out);
        } else if (is_prefix_function(string[i])) {
            process_prefix_function(string, &i, operations);
        } else if (string[i] == ')') {
            process_close_bracket(string, &i, operations, out);
        }
    }

    // DEBUG  
    while (out->top > 0) { 
        printf("%c ", get_char(*(pop(out))));
    }

    return out;
}

void process_number(char *string, int *i, stack *out) {
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    while (is_digit(string[*i])) {
        set_char(&char_data, string[(*i)++]);
        push(out, char_data);
    }

    set_char(&char_data, 0);
    push(out, char_data);
}

void process_prefix_function(char *string, int *i, stack *operations) {
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    set_char(&char_data, string[*i++]);
    push(operations, char_data);

    set_char(&char_data, 0);
    push(operations, char_data);
}

void process_close_bracket(char *string, int *i, stack *operations, stack *out) {
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    while (get_char(char_data) != '(') {
        set_char(&char_data, get_char(*pop(operations)));
        push(out, char_data);
    }
}
