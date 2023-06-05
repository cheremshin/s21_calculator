# CalculatorService

add_library(CalculatorService
            SHARED
                calculator_service.h
                calculator_service.c

                preparer/preparer.h
                preparer/preparer.c
                preparer/internal.c
                preparer/checks.c

                translator/translator.h
                translator/translator.c
                translator/processing.c
                translator/operations.c
                translator/checks.c

                calculator/calculator.h
                calculator/calculator.c
                calculator/internal.c
                
                utils/common.h
                utils/common.c
                utils/operation_shortcuts.c
                utils/stack.h
                utils/stack.c)

target_include_directories(CalculatorService
                            PUBLIC
                                ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(CalculatorService PRIVATE m)