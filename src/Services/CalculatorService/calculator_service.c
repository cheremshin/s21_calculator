#include "calculator_service.h"
#include "preparer/preparer.h"
#include "translator/translator.h"
#include "calculator/calculator.h"


int calculate_value(char *expression, double *x, double *result) {
    int status = SUCCESSFUL;

    char *prepared_expression = prepare_to_translate(expression);

    if (prepared_expression == NULL) {
        status = INCORRECT_INPUT;
    } else {
        char *translated_expression = translate_to_polish(prepared_expression);
        double value = calculate(translated_expression, x);

        if (value == NAN) { 
            status = CALCULATION_ERROR;
        } else {
            *result = value;
        }

        free(translated_expression);
        free(prepared_expression);
    }

    return status;
}
