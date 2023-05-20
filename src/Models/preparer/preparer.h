#ifndef SRC_MODELS_PREPARER_H_
#define SRC_MODELS_PREPARER_H_

#include <stdlib.h>


/**
 * @brief A function that attempts to prepare an incoming string
 * for convertion to RPN
 * 
 * @param string String to be prepared
 * @return char* Pointer to prepared string (null - if incoming string is incorrect)
 */
char *prepare_to_translate(char *string);

#endif // SRC_MODELS_PREPARER_H_
