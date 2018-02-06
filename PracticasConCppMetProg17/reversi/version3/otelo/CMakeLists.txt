# CMakeLists.txt para crear una versión gráfica
# Este archivo no necesita modificaciones. Sólo tiene que crear el fuente otelo.cpp

# Ver FindSFML.cmake si se quieren detalles
# Indicamos dónde podría estar el fichero FindSFML.cmake
set ( CMAKE_MODULE_PATH /usr/share/SFML/cmake/Modules ${CMAKE_MODULE_PATH} )

find_package(SFML 2 REQUIRED system window graphics audio ) 

set ( VENTANAS_SRC
      ventana.h ventana.cpp
    )

if(SFML_FOUND)
  add_executable ( otelo otelo.cpp ${VENTANAS_SRC} )
  target_link_libraries ( otelo lotelo )
  target_link_libraries( otelo ${SFML_LIBRARIES})

  add_executable ( test_tablero test_tablero.cpp ${VENTANAS_SRC} )
  target_link_libraries( test_tablero ${SFML_LIBRARIES})

endif(SFML_FOUND)
