add_executable( ${PROJECT_NAME}
    "main.cpp"
    )

target_include_directories ( ${PROJECT_NAME} 
PRIVATE
    ${CMAKE_HOME_DIRECTORY}/sources/core
    ${CMAKE_HOME_DIRECTORY}/sources/ui
    )

target_link_libraries( ${PROJECT_NAME}
PRIVATE
    Core
    UI
    )
