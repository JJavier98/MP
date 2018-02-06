/**
 * @file ventana.h
 * @brief Fichero de interfaz gráfica
 *
 * Esta interfaz se ha diseñado de la forma más simple y ajustada al problema
 * Otelo de la asignatura Metodología de la Programación. Está basada en el uso
 * de la biblioteca SFML.
 *
 * El código no está diseñado para su reutilización ni para su mantenimiento. Sólo
 * será útil primero para mostrar cómo la sustitución de un componente del proyecto
 * puede modificar completamente la interfaz del juego y segundo para que el estudiante
 * pueda realizar pruebas más ágilmente.
 */

#ifndef __VENTANA_H_
#define __VENTANA_H_


/**
 * @brief La clase Ventana contiene la interfaz que usará el estudiante
 *
 * Es posible que una interfaz basada en funciones generales se hubiera entendido
 * más fácilmente. Sin embargo, los detalles de este diseño, donde:
 *
 *  -# sólo existe un único objeto de la clase,
 *  -# se evita mostrar la implementación en el archivo de cabecera
 *  -# se define un enumerado y una estructura dentro de la clase
 *
 * hacen del ejemplo un buen código para introducir al estudiante en nuevos detalles
 * de diseño así como para repasar algunas ideas del curso.
 *
 * Una forma sencilla y eficaz de conocer lo que hace es consultar el ejemplo:
 *
 * @include test_tablero.cpp
 */
class Ventana {
public:
    /**
     * @brief El singleton
     *
     * Un singleton se refiere a un único objeto de la clase. No es posible definir
     * más, pues la clase no admite que el usuario llame a un constructor.
     */
    static Ventana win;


    /**
     * @brief init Es la primera función a llamar para crear el único objeto ventana a usar
     * @param resource_dir Directorio donde se encuentran los sonidos/imágenes/fuentes
     * @param filas Filas del tablero
     * @param columnas Columnas del tablero
     * @param titulo Título de la ventana que muestra el juego
     * @param wpix Ancho en píxeles de la ventana con el juego
     * @param hpix Alto en píxeles de la ventana con el juego
     * @return Si se ha iniciado con éxito
     */
    bool init(const char* resource_dir,unsigned int filas, unsigned int columnas,
              const char* titulo= "Otelo", unsigned int wpix= 1024, unsigned int hpix= 768);

    /**
     * @brief setTablero Cambia el contenido que se mostrará cuando se vuelva a dibujar el tablero
     * @param turno Turno (0/1/2) del que tiene que escoger casilla
     * @param tablero Cadena de caracteres con los contenidos del tablero
     * @pre La cadena \a tablero sólo admitirá los carateres '1','2','0','?'
     *      para indicar ficha de jugador 1, del 2, posición vacía y posible posición para poner
     * @note Es una función incómoda, pues hay que montar la cadena. Se hace así para hacerla independiente
     *       de cómo haya implementado el tablero. Sería una buena idea crear una función global junto al
     *       \c main que recibe un objeto de la clase Tablero (con booleano para indicar si desea ayuda)
     *        y llame a esta función.
     */
    void setTablero(int turno, const char *tablero);


    /**
     * @brief setEstado Asigna el mensaje que aparecerá debajo cada vez que se pinta el tablero
     * @param mensaje La cadena con el mensaje codificado con ISO 8859-15
     * @param esperarClick Indica si esperará a que el usuario pulse en el tablero para continuar
     */
    void setEstado(const char *mensaje, bool esperarClick= false);

    /**
     * @brief setError Cambia el estado y genera un sonido de error
     * @param mensaje Cadena codificada como ISO-8859-15 que parece como nuevo estado hasta
     *        que se llame a otra función que lo cambie
     * @see setEstado
     */

    void setError(const char *mensaje);


    /** @brief Avisa que el jugador ha tenido que pasar con un sonido
     *  @param turno El jugador que seguirá jugando
     *  @post Indicará un mensaje y esperará a pulsar en el tablero para confirmar
     */
    void paso(int turno);

    /**
     * @brief final Muestra un mensaje de ganador, un sonido y una animación
     * @param ganador La ficha que se mostrará como ganadora
     * @note El ganador se muestra aumentando el tamaño de su ficha
     */
    void final(int ganador);

    /**
     * @brief Este enumerado describe el tipo de la entrada seleccionada
     * @see input
     */
    enum TipoEntrada {Casilla,       ///< Se ha pulsado en el tablero
                      Ayuda,         ///< Se ha pulsado la tecla ?
                      Interrumpir,   ///< Se ha pulsado la tecla !
                      Cerrar         ///< Se ha pulsado el cierre de la ventana
                     };

    /**
     * @brief Incluye la información asociada a una selección en el tablero
     *
     * Observe que tiene un primer campo \a tipo que nos sirve para distinguir el
     * tipo de entrada. Los otros campos son válidos sólo en el caso en que el tipo
     * sea que ha seleccionado una casilla dentro del tablero.
     *
     * Este diseño puede recordar la forma que tiene el tipo sf::Event de la biblioteca
     * SFML, pero es bastante más simple. El tipo asociado a un evento suele ser más complejo,
     * pues cambiando el tipo del evento normalmente cambian los campos asociados; además,
     * para aprovechar el espacio, el diseño de este tipo a bajo nivel suelen implicar el
     * uso de uniones.
     */
    struct Input {
        TipoEntrada tipo; ///< Tipo de entrada
        int fila;         ///< Fila que se ha pinchado (desde 0)
        int columna;      ///< Columna que se ha pinchado (desde 0)
    };

    /**
     * @brief input Espera a que el usuario decida una acción y la devuelve
     * @return Alguna posible entrada del enumerado \a TipoEntrada
     */
    Input input();


private:
    // Evitamos que se pueda copiar o asignar un objeto. Esto se implementa más adecuadamente
    // con "delete" en C++14
    Ventana(const Ventana&);
    Ventana& operator= (const Ventana&);
    ~Ventana();
    Ventana();
    // La implementación interna queda oculta, podríamos dar el .h con los cpp compilados
    // para evitar incluir ningún detalle sobre la implementación
    struct pimpl;
    pimpl *rep;
};


#endif //__VENTANA_H_
