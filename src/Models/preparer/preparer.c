#include "preparer.h"


char *prepare_to_translate(char *string) {
    int status = 0;
    char *out = NULL;

    // Validation
    status = check_brackets(string);
    if (status) check_numbers(string);
    if (status) check_symbols(string);

    // Preparing
    if (status) {
        out = (char *)malloc(EXPRESSION_LENGTH * sizeof(char));
        strcpy(out, string);
        remove_spaces(out);
        convert_symbols(out);
    }

    return out;
}

void remove_spaces(char *string) {
    char *copy = (char *)malloc(EXPRESSION_LENGTH * sizeof(char));
    strcpy(string, copy);

    int j = 0;
    for (int i = 0; copy[i] != '\0'; i++) {
        if (copy[i] != ' ') string[j++] = copy[i];
    }
    string[j] = '\0';
}

void convert_symbols(char *string) {
    
}
