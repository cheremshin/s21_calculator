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

int is_operation(char symbol) {
    return (symbol == '+' ||
            symbol == '-' ||
            symbol == '*' ||
            symbol == '/' ||
            symbol == '^');
}

int is_open_bracket(char symbol) {
    return (symbol == '(');
}

int is_close_bracket(char symbol) {
    return (symbol == ')');
}
