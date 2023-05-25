#ifndef SRC_MODELS_UTILS_STACK_H_
#define SRC_MODELS_UTILS_STACK_H_

#include <stdio.h>
#include <stdlib.h>


/*************************
 *        Defines        *
 ************************/

#define INIT_SIZE   256
#define MULTIPLIER  2
#define CHAR_TYPE   0b00000001
#define DOUBLE_TYPE 0b00000010

/*************************
 *      Structures       *
 ************************/

typedef struct stack_element {
    union {
        char value_c;
        double value_d;
    } data;
} stack_element;

/**
 * @brief Struct represents stack
 * 
 */
typedef struct stack {
    int type;
    stack_element *elements;
    size_t size;
    size_t top;
} stack;

/*************************
 *    Stack functions    *
 ************************/

/**
 * @brief Function that inits stack
 * 
 * @param type Type of stored data
 * @return Pointer to stack structure
 */
stack *init_stack(int type);

/**
 * @brief Functuon that clears stack allocated memory and sets NULL in it
 * 
 * @param stack Stack to be cleared
 */
void delete_stack(stack **stack);

/**
 * @brief Util function that doubles the allocated stack data memory
 * 
 * @param stack Stack to be doubled
 */
void resize_stack(stack *stack);

/**
 * @brief Function that pushes some value to stack
 * 
 * @param stack Stack for pushing data into it
 * @param value Value to be pushed
 */
void push(stack *stack, void *value);

/**
 * @brief Function that removes top of stack and sets to p
 * 
 * @param stack Stack for removing data from it
 * @param p void* Pointer to a memory to store popped data
 */
void pop(stack *stack, void *p);

/**
 * @brief Funtction that sets top of stack to p without removing
 * 
 * @param stack Stack to get its top
 * @param p void* Pointer to a memory to store top of stack
 */
void peek(stack *stack, void *p);

/**
 * @brief Function that pushes all data from source stack to destination with removing from first one
 * 
 * @param source Stack to popping data from
 * @param destination Stack for pushing data to
 */
void transfer_data(stack *source, stack *destination);

/**
 * @brief Function that moves all stack's elements to string
 * 
 * @param source Stack to get elements from
 * @param destination String for moving elements to
 */
void convert_to_string(stack *source, char *destination);

#endif //  SRC_MODELS_UTILS_STACK_H_
