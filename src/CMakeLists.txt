# Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

list(APPEND QT_MODULES Qml Core Quick Gui)
find_package(Qt6 COMPONENTS ${QT_MODULES} REQUIRED)

set(QT_PREFIXED_MODULES ${QT_MODULES})
list(TRANSFORM QT_PREFIXED_MODULES PREPEND "Qt6::")


# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Configure and add subdirectories
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/config)

add_subdirectory(Services/CalculatorService/)
get_target_property(CALCULATOR_SERVICE_INCLUDES CalculatorService INTERFACE_INCLUDE_DIRECTORIES)

add_subdirectory(Views/)


# Building
add_executable(${PROJECT_NAME} main.cpp Views/qmlSources.qrc)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
                CalculatorService
                Views
                ${QT_PREFIXED_MODULES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
                ${CALCULATOR_SERVICE_INCLUDES})


include(CopyRecursive)
set(FONTS_OUT_DIR ${PROJECT_BINARY_DIR}/resources/fonts)
file(MAKE_DIRECTORY ${FONTS_OUT_DIR})
copy_recursive(${PROJECT_SOURCE_DIR}/resources/fonts ${FONTS_OUT_DIR} "*.ttf")