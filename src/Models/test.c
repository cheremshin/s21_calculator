#include <stdio.h>
#include <stdlib.h>

#include "utils/stack.h"
#include "translator/translator.h"


int main(void) {
    translate_to_polish("(5+1)");
    //3+4*2/(1-5)^2

    return 0;
}