#ifndef SRC_MODELS_UTILS_COMMON_H_
#define SRC_MODELS_UTILS_COMMON_H_

#define SHORTCUTS_COUNT 10

typedef struct operation_shortcut {
    char *operation;
    char shortcut;
} operation_shortcut;

extern operation_shortcut operation_shortcuts[SHORTCUTS_COUNT];


int is_digit(char symbol);
int is_dot(char symbol);
int is_x(char symbol);
int is_operation(char symbol);
int is_open_bracket(char symbol);
int is_close_bracket(char symbol);

#endif // SRC_MODELS_UTILS_COMMON_H_
