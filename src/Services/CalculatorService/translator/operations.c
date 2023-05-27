#include "translator.h"


operation_priority operations_priority[OPERATIONS_COUNT] = {
    {'(', 3},
    {'~', 3}, // unary minus
    {'$', 3}, // unary plus
    {'^', 3},
    {'c', 3},
    {'s', 3},
    {'t', 3},
    {'C', 3},
    {'S', 3},
    {'T', 3},
    {'r', 3},
    {'n', 3},
    {'g', 3},
    {'*', 2},
    {'/', 2},
    {'m', 2},
    {'+', 1},
    {'-', 1},
    {0, 0}
};

int get_priority(char symbol) {
    int priority = 0;

    for (int i = 0; (i < OPERATIONS_COUNT) && (priority == 0); i++) {
        if (operations_priority[i].operation == symbol) {
            priority = operations_priority[i].priority;
        }
    }

    return priority;
}
