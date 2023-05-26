#include "preparer.h"


void remove_spaces(char *string) {
    char *copy = (char *)calloc(EXPRESSION_LENGTH, sizeof(char));

    for (int i = 0, j = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ') copy[j++] = string[i];
    }

    strcpy(string, copy);
    free(copy);
}

void convert_symbols(char *string) {
    char *copy = (char *)calloc(EXPRESSION_LENGTH, sizeof(char));

    for (int i = 0, j = 0; string[i] != '\0'; i++) {
        if (is_digit(string[i]) ||
            is_dot(string[i]) ||
            is_x(string[i]) ||
            is_open_bracket(string[i]) ||
            is_close_bracket(string[i])) {
            copy[j++] = string[i];
        } else if (is_binary_operation(string[i] && is_digit(string[i - 1]))) {
            copy[j++] = string[i];
        } else {
            accept_shortcuts(string, copy, &i, &j);
        }
    }

    strcpy(string, copy);
    free(copy);
}

void accept_shortcuts(char *string, char *copy, int *i, int *j) {
    int status = 1;
    char operation[5];
    char shortcut;

    if (string[*i] == '-') {
        status = 0;
        copy[(*j)++] = '~';
    } else if (string[*i] == '+') {
        status = 0;
        copy[(*j)++] = '$';
    }

    for (int k = 0; k < SHORTCUTS_COUNT && status; k++) {
        strcpy(operation, operation_shortcuts[k].operation);
        shortcut = operation_shortcuts[k].shortcut;

        if (strncmp(string + *i, operation, strlen(operation)) == 0) {
            copy[(*j)++] = shortcut;
            status = 0;
        }
    }

    *i += strlen(operation) - 1;
}
