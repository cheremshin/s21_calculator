# Models

add_library(Models
                SHARED
                    SessionModel.h
                    SessionModel.cpp)

target_include_directories(Models
                            PUBLIC
                                ${CMAKE_CURRENT_SOURCE_DIR}
                            PRIVATE
                                ${CALCULATOR_SERVICE_INCLUDES}
                                ${CONTROLLERS_INCLUDES})

target_link_libraries(Models PRIVATE ${QT_PREFIXED_MODULES})