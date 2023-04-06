#ifndef SRC_MODELS_TRANSLATOR_H_
#define SRC_MODELS_TRANSLATOR_H_

#include <stdlib.h>
#include "../utils/stack.h"


#define SHORTCUTS_COUNT  10
#define OPERATIONS_COUNT 19

typedef struct operation_shortcut {
    char *operation;
    char shortcut;
} operation_shortcut;

typedef struct operation_priority {
    char operation;
    int priority;
} operation_priority;

extern operation_shortcut operation_shortcuts[SHORTCUTS_COUNT];
extern operation_priority operations_priority[OPERATIONS_COUNT];


/**
 * @brief Function that translates given string
 * in infix notation to polish notation
 * 
 * @param string String to be translated
 * @return stack_t Stack consists of char generic data
 */
stack_t *translate_to_polish(char *string);

int is_digit(char symbol);
int is_prefix_function(char symbol);

#endif // SRC_MODELS_TRANSLATOR_H_