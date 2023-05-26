#include "translator.h"


char *translate_to_polish(char *string) {
    stack_c *out = init_stack(CHAR_TYPE);
    stack_c *operations = init_stack(CHAR_TYPE);

    for (int i = 0; string[i] != '\0';) {
        printf("%d\n", i);
        if (is_digit(string[i])) {
            process_number(string, &i, out);
        } else if (is_x(string[i])) {
            process_x(string, &i, out);
        } else if (is_prefix_function(string[i]) || is_open_bracket(string[i])) {
            process_prefix_function(string, &i, operations);
        } else if (is_close_bracket(string[i])) {
            process_close_bracket(string, &i, operations, out);
        } else {
            process_binary_operation(string, &i, operations, out);
        }
    }

    transfer_data(operations, out);
    
    char *translated_expression = (char *)calloc(out->top, sizeof(char));
    convert_to_string(out, translated_expression);

    return translated_expression;
}
