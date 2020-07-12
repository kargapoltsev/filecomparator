set ( TEST_NAME ${LIB_NAME}_Test )

set ( SOURCE_FILES 
    "main.cpp"
    "tests.cpp"
    )

add_executable( ${TEST_NAME} ${SOURCE_FILES} )

add_test( NAME ${TEST_NAME} COMMAND ${TEST_NAME} )

target_include_directories ( ${TEST_NAME}
PRIVATE
    ..
    )

target_link_libraries( ${TEST_NAME}
PRIVATE
    gtest
    ${LIB_NAME}
    )

set_property(TARGET ${TEST_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")

