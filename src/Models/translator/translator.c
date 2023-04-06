#include "translator.h"

stack_t *translate_to_polish(char *string) {
    char operation;
    stack_t *out = init_stack(CHAR_TYPE_ID);
    stack_t *operations = init_stack(CHAR_TYPE_ID);
    generic_data_t char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    for (size_t i = 0; string[i] != '\0'; i++) {
        if (is_digit(string[i])) {
            get_number(string, &i, out);
        } else {
            
        }
    }

    return out;
}

void get_number(char *string, int *i, stack_t *out) {
    generic_data_t char_data = {.type_id = CHAR_TYPE_ID, .value = 0};

    while (is_digit(string[*i])) {
        set_char(&char_data, string[*i++]);
        push(out, char_data);
    }

    set_char(&char_data, 0);
    push(out, char_data);
}
