#ifndef SRC_MODELS_PREPARER_H_
#define SRC_MODELS_PREPARER_H_

#include <stdlib.h>
#include <string.h>

#include "../utils/common.h"


#define EXPRESSION_LENGTH 256
#define POSSIBLE_SYMBOLS_COUNT 34

extern char possible_symbols[POSSIBLE_SYMBOLS_COUNT];

/**
 * @brief A function that attempts to prepare an incoming string
 * for convertion to RPN
 * 
 * @param string String to be prepared
 * @return char* Pointer to prepared string (null - if incoming string is incorrect)
 */
char *prepare_to_translate(char *string);

/**************************
 *   Internal functions   *
  ************************/

int check_brackets(char *string);
int check_numbers(char *string);
int check_symbols(char *string);

void remove_spaces(char *string);
void convert_symbols(char *string);

int is_correct_number(char *string, int *i);

#endif // SRC_MODELS_PREPARER_H_
