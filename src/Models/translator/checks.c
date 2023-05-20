#include "translator.h"

int is_digit(char symbol) {
    return (((symbol >= '0') && (symbol <= '9')) || (symbol == '.'));
}

int is_x(char symbol) {
    return (symbol == 'x');
}

int is_open_bracket(char symbol) {
    return (symbol == '(');
}

int is_close_bracket(char symbol) {
    return (symbol == ')');
}

int is_prefix_function(char symbol) {
    int result = 0;

    if (symbol == '~' || symbol == '$') {
        result = 1;
    }

    for (int i = 0; i < SHORTCUTS_COUNT && result == 0; i++) {
        if (symbol == operation_shortcuts[i].shortcut) {
            result = 1;
        }
    }

    return result;
}
