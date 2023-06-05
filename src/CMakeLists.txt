# Qt
# list(APPEND QT_MODULES Qml Quick Gui)

# find_package(Qt6 6.5 COMPONENTS ${QT_MODULES} REQUIRED)
# qt_standard_project_setup()

# set(QT_PREFIXED_MODULES ${QT_MODULES})
# list(TRANSFORM QT_PREFIXED_MODULES PREPEND "Qt6::")


# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Configure and add subdirectories
add_subdirectory(Services/CalculatorService/)
get_target_property(CALCULATOR_SERVICE_INCLUDES CalculatorService INTERFACE_INCLUDE_DIRECTORIES)


# Building
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
                CalculatorService)

target_include_directories(${PROJECT_NAME}
        PRIVATE
                ${CALCULATOR_SERVICE_INCLUDES})
                # ${QT_PREFIXED_MODULES})
