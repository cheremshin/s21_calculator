#include "common.h"


int is_digit(char symbol) {
    return ((symbol >= '0') && (symbol <= '9'));
}

int is_dot(char symbol) {
    return (symbol == '.');
}

int is_x(char symbol) {
    return (symbol == 'x');
}

int is_binary_operation(char symbol) {
    return (symbol == '+' ||
            symbol == '-' ||
            symbol == '*' ||
            symbol == '/' ||
            symbol == '^');
}

int is_unary_operation(char symbol) {
    int status = 0;

    if (symbol == '~' || symbol == '$') status = 1;

    for (int i = 0; i < SHORTCUTS_COUNT && !status; i++) {
        if (symbol == operation_shortcuts[i].shortcut) status = 1;
    }

    return status;
}

int is_open_bracket(char symbol) {
    return (symbol == '(');
}

int is_close_bracket(char symbol) {
    return (symbol == ')');
}
