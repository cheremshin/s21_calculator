#ifndef SRC_MODELS_UTILS_STACK_H_
#define SRC_MODELS_UTILS_STACK_H_

#include <stdio.h>
#include <stdlib.h>


/*************************
 *        Defines        *
 ************************/

#define INIT_SIZE        256
#define MULTIPLIER       2
#define OUT_OF_MEMORY    100

/*************************
 *      Structures       *
 ************************/

/**
 * @brief Struct represents stack
 * 
 */
typedef struct stack_c {
    char *data;
    size_t size;
    size_t top;
} stack_c;

/*************************
 *    Stack functions    *
 ************************/

/**
 * @brief Function that inits stack
 * 
 * @param pointer Memory address for stack allocation
 * @return Exit code
 */
int *init_stack_c(stack_c **pointer);

/**
 * @brief Functuon that clears stack allocated memory and sets NULL in it
 * 
 * @param stack Stack to be cleared
 */
void delete_stack_c(stack_c **stack);

/**
 * @brief Util function that doubles the allocated stack data memory
 * 
 * @param stack Stack to be doubled
 * @return Exit code
 */
int resize_stack(stack_c *stack);

/**
 * @brief Function that pushes some value to stack
 * 
 * @param stack Stack for pushing data into it
 * @param value Char to be pushed
 */
void push(stack_c *stack, char value);

/**
 * @brief Function that removes top of stack and returns it back
 * 
 * @param stack Stack for removing data from it
 * @return Char data removed from top of stack
 */
char pop(stack_c *stack);

/**
 * @brief Funtction that returns char from top of stack without removing
 * 
 * @param stack Stack to get its top
 * @return Char from top of stack
 */
char peek(stack_c *stack);

#endif //  SRC_MODELS_UTILS_STACK_H_
