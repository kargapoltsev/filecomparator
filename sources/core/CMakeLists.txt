set ( LIB_NAME Core )

set ( HEADER_FILES 
    "filescomparator.h"
)

set ( SOURCE_FILES 
    "filescomparator.cpp"
)

add_library( ${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES} )

add_subdirectory( tests )
