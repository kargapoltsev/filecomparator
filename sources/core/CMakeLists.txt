set ( LIB_NAME Core )

set ( HEADER_FILES 
    "filescomparator.h"
	"directoryhandler.h"
)

set ( SOURCE_FILES 
    "filescomparator.cpp"
	"directoryhandler.cpp"
)

add_library( ${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES} )

add_subdirectory( tests )
