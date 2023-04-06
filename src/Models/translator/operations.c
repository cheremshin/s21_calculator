#include "translator.h"

operation_shortcut operation_shortcuts[SHORTCUTS_COUNT] = {
    {"cos", 'c'},
    {"sin", 's'},
    {"tan", 't'},
    {"acos", 'C'},
    {"asin", 'S'},
    {"atan", 'T'},
    {"sqrt", 'r'},
    {"ln", 'n'},
    {"log", 'g'},
    {"mod", 'm'}
};

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
