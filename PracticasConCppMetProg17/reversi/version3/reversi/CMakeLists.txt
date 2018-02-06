# CMakeLists.txt para crear aplicación reversi
# Este archivo no necesita modificaciones. Sólo tiene que crear el funete reversi.cpp

add_executable ( reversi reversi.cpp )
TARGET_LINK_LIBRARIES ( reversi lotelo ) # depende de la librería
