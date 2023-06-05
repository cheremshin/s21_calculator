# Dependencies
find_package(Qt6 COMPONENTS ${QT_MODULES} REQUIRED)


# Build
add_library(Views
        SHARED
            qmlSources.qrc)

target_link_libraries(Views PRIVATE ${QT_PREFIXED_MODULES})