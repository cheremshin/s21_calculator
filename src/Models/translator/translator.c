#include "translator.h"

stack *translate_to_polish(char *string) {
    char operation;
    stack *out = init_stack(CHAR_TYPE_ID);
    stack *operations = init_stack(CHAR_TYPE_ID);
    generic_data char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    for (int i = 0; string[i] != '\0';) {
        if (is_digit(string[i])) {
            process_number(string, &i, out);
        } else if (is_prefix_function(string[i]) || string[i] == '(') {
            process_prefix_function(string, &i, operations);
        } else if (string[i] == ')') {
            for (int j = out->top; j > 0; j--) {
                printf("%c\n", out->data[j]);
            }
            process_close_bracket(string, &i, operations, out);
        } else {
            process_binary_operation(string, &i, operations, out);
        }
    }

    while(operations->top > 0) {
        set_char(&char_data, get_char(*(pop(operations))));
        push(out, char_data);
    }

    // DEBUG  
    while (out->top > 0) { 
        printf("%c ", get_char(*(pop(out))));
    }

    return out;
}
