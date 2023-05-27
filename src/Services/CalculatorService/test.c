#include <stdio.h>
#include <stdlib.h>

#include "preparer/preparer.h"
#include "translator/translator.h"
#include "calculator/calculator.h"


int main(void) {
    //char *raw_expression = "123*15-10^cos(30)";
    char *raw_expression = "123+5*20^cos(30)";
    printf("%s\n", raw_expression);
    char *prepared_expression = prepare_to_translate(raw_expression);
    printf("%s\n", prepared_expression);
    char *translated_expression = translate_to_polish(prepared_expression);
    printf("%s\n", translated_expression);
    double result = 0;
    result = calculate(translated_expression, NULL);
    printf("%f\n", result );
    return 0;
}
