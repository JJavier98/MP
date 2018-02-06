# CMakeLists.txt principal del proyecto. No requiere modificaciones
project ( OTELO )
cmake_minimum_required (VERSION 3.0)

if ( CMAKE_COMPILER_IS_GNUCXX )
   message ( "Especificamos flags concretos para la gnu..." )
   set( OTELO_EXTRA_CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++14" 
        CACHE STRING "Flags extra que se añaden a CMAKE_CXX_FLAGS" )
   set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OTELO_EXTRA_CMAKE_CXX_FLAGS}" )
else() # Si estamos con otro, al menos fijamos que es C++14
   set ( CMAKE_CXX_STANDARD 14 )
endif( CMAKE_COMPILER_IS_GNUCXX )

# El desarrollo se hace como Debug. Por comodidad, lo fijamos.
set (CMAKE_BUILD_TYPE "Debug" CACHE STRING "Fijamos Debug" FORCE)


# Las librerías la creamos en este directorio
set ( LIBRARY_OUTPUT_PATH ${OTELO_BINARY_DIR}/lib CACHE PATH
                  "Output directory for the OTELO libraries" )
                  
# Indicamos que los includes están también en donde la librería
include_directories ( ${OTELO_SOURCE_DIR}/lotelo )
# Indicamos que las librerías están en este directoio
link_directories ( ${LIBRARY_OUTPUT_PATH} )


add_subdirectory (lotelo)   # Directorio donde montamos la librería
add_subdirectory (reversi)  # Directorio donde montamos un ejecutable en consola
add_subdirectory (otelo)    # Directorio donde moentamos otro ejecutable con gráficos
