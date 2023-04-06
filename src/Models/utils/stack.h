#ifndef SRC_MODELS_UTILS_STACK_H_
#define SRC_MODELS_UTILS_STACK_H_

#include <stdio.h>
#include <stdlib.h>


/*************************
 *        Defines        *
 ************************/

#define CHAR_TYPE_ID     1
#define DOUBLE_TYPE_ID   2

#define INIT_SIZE        256
#define MULTIPLIER       2

/*************************
 *      Structures       *
 ************************/

/**
 * @brief Struct represents generic type for stack
 * 
 */
typedef struct generic_data {
    union {
        char c;
        double d;
    } value;
    int type_id;
} generic_data_t;

/**
 * @brief Struct represents stack
 * 
 */
typedef struct stack {
    generic_data_t *data;
    size_t size;
    size_t top;
} stack_t;


/*************************
 *    Stack functions    *
 ************************/

/**
 * @brief Function that inits stack
 * 
 * @param type_id Id of stack data
 * @return stack_t* Pointer to stack structure
 */
stack_t *init_stack(int type_id);

/**
 * @brief Functuon that clears stack allocated memory and sets NULL in it
 * 
 * @param stack Stack to be cleared
 */
void delete_stack(stack_t **stack);

/**
 * @brief Util function that doubles the allocated stack data memory
 * 
 * @param stack Stack to be doubled
 */
void resize_stack(stack_t *stack);

/**
 * @brief Function that pushes some value to stack
 * 
 * @param stack Stack for pushing data into it
 * @param value Generic data to be pushed
 */
void push(stack_t *stack, generic_data_t value);

/**
 * @brief Function that removes top of stack and returns it back
 * 
 * @param stack Stack for removing data from it
 * @return generic_data_t Pointer to generic data removed from top of stack
 */
generic_data_t *pop(stack_t *stack);

/**
 * @brief Funtction that returns generic data from top of stack
 * 
 * @param stack Stack to get its top
 * @return generic_data_t Pointer to generic data to get
 */
generic_data_t *peek(stack_t *stack);

#endif //  SRC_MODELS_UTILS_STACK_H_
