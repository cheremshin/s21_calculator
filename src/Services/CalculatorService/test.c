#include <stdio.h>
#include <stdlib.h>

#include "calculator_service.h"


int main(void) {
    //char *raw_expression = "123*15-10^cos(30)";
    char *raw_expression = "11/6+56-12^(1/3)";
    double result = 0;
    calculate_value(raw_expression, NULL, &result);
    printf("%f", result);
    return 0;
}
