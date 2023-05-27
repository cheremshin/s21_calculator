#include "preparer.h"


char possible_symbols[POSSIBLE_SYMBOLS_COUNT] = "0123456789.+-*/^() acdgilmnoqrstx";

int check_brackets(char *string) {
    int status = 1;
    int brackets_opened = 0;

    for (int i = 0; string[i] != '\0' && status; i++) {
        if (brackets_opened < 0) status = 0;

        if (is_open_bracket(string[i])) {
            brackets_opened++;
        } else if (is_close_bracket(string[i])) {
            brackets_opened--;
        }
    }

    if (brackets_opened != 0) status = 0;

    return status;
}

int check_numbers(char *string) {
    int status = 1;

    for (int i = 0; string[i] != '\0' && status; i++) {
        if (is_dot(string[i])) status = 0; // Prevents single dots
        if (is_digit(string[i])) status = is_correct_number(string, &i);
    }

    return status;
}

int is_correct_number(char *string, int *i) {
    int status = 1;
    int dot_count = 0;

    while (is_digit(string[*i]) || is_dot(string[*i])) {
        if (is_dot(string[*i])) { // There must be digit after dot
            dot_count++;
            if (!is_digit(string[*i + 1])) {
                status = 0;
            }
        }
        (*i)++;
    }

    if (dot_count > 1) status = 0;

    return status;
}

int check_symbols(char * string) {
    int status = 1;

    for (int i = 0; string[i] != '\0' && status; i++) {
        if (strchr(possible_symbols, string[i]) == NULL) {
            status = 0;
        }
    }

    return status;
}
