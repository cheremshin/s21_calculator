#include "translator.h"


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
