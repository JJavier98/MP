# CMakeLists.txt para crear una biblioteca común
# Debe indicar los fuentes que componen la biblioteca. Dependerá de su diseño,
# aunque es de esperar algunos, como tablero.h, tablero.cpp, juego.h...

set ( LOTELO_SRCS
      #Añadir aquí los fuentes (.h y .cpp) de la biblioteca
    )
    
# Creamos la biblioteca lotelo
add_library (lotelo ${LOTELO_SRCS})
