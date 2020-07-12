set ( LIB_NAME UI )

set ( HEADER_FILES 
    "iui.h"
	"cui.h"
)

set ( SOURCE_FILES 
    "cui.cpp"
)

add_library( ${LIB_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES} )
