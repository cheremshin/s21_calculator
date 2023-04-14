#include "translator.h"

stack_c *translate_to_polish(char *string) {
    char operation;
    stack_c *out = init_stack();
    stack_c *operations = init_stack();

    for (int i = 0; string[i] != '\0';) {
        if (is_digit(string[i])) {
            process_number(string, &i, out);
        } else if (is_prefix_function(string[i]) || string[i] == '(') {
            process_prefix_function(string, &i, operations);
        } else if (string[i] == ')') {
            process_close_bracket(string, &i, operations, out);
        } else {
            process_binary_operation(string, &i, operations, out);
        }
    }

    transfer_data(operations, out);

    // DEBUG  
    while (out->top > 0) { 
        printf("%c ", pop(out));
    }

    return out;
}
