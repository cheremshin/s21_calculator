# Copies all files with the same hierarchy (folder)

function(copy_recursive SOURCE_PATH DESTINATION_PATH REGEX)
    file(GLOB_RECURSE
         FILES
         ${SOURCE_PATH}
         "${SOURCE_PATH}/${REGEX}")

    foreach(file ${FILES})
        file(RELATIVE_PATH RELATIVE_FILE_PATH ${SOURCE_PATH} ${file})
        get_filename_component(FOLDER ${RELATIVE_FILE_PATH} DIRECTORY ${SOURCE_PATH})
        file(MAKE_DIRECTORY "${DESTINATION_PATH}/${FOLDER}")
        configure_file(${file} "${DESTINATION_PATH}/${RELATIVE_FILE_PATH}" COPYONLY)
    endforeach()
endfunction()