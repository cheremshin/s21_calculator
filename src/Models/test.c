#include <stdio.h>
#include <stdlib.h>

#include "utils/stack.h"
#include "translator/translator.h"


int main(void) {
    translate_to_polish("123(5)");

    return 0;
}