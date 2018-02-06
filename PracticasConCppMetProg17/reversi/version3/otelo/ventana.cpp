#include <iostream>
#include <string>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ventana.h"

// Definición del singleton
Ventana Ventana::win;

/**
 * @brief Estructura interna para recursos que deben estar en memoria (debe ignorarse)
 *
 * Fonts, texturas y buffers de sonido
 */
struct Recursos {
    sf::Font font;
    sf::Texture textura_ficha;
    sf::SoundBuffer errorBuffer, finalBuffer, sorpresaBuffer;
    bool load (const char *resource_dir);
};

bool Recursos::load (const char *resource_dir)
{
    const char * const TIPO_LETRA= "/fonts/DejaVuSerif.ttf";
    const char * const POLLO=      "/images/pollo.png";
    const char * const ERROR=      "/sounds/error.ogg";
    const char * const FINAL=      "/sounds/final.ogg";
    const char * const SORPRESA=   "/sounds/sorpresa.ogg";

    char fichero[256]; // Lo resolvemos con cadena-C
    strcpy (fichero, resource_dir); strcat (fichero, TIPO_LETRA );
    if (!font.loadFromFile(fichero)) {
        std::cerr << "Tipo de letra " << fichero << " no se puede leer " << std::endl;
        return false;
    }
    strcpy (fichero, resource_dir); strcat (fichero, POLLO );
    if (!textura_ficha.loadFromFile(fichero)) {
        std::cerr << "Textura " << fichero << " no se puede leer " << std::endl;
        return false;
    }

    strcpy (fichero, resource_dir); strcat (fichero, ERROR );
    if (!errorBuffer.loadFromFile(fichero)){
        std::cerr << "Sonido " << fichero << " no se puede leer " << std::endl;
        return false;
    }

    strcpy (fichero, resource_dir); strcat (fichero, FINAL );
    if (!finalBuffer.loadFromFile(fichero)){
        std::cerr << "Sonido " << fichero << " no se puede leer " << std::endl;
        return false;
    }

    strcpy (fichero, resource_dir); strcat (fichero, SORPRESA );
    if (!sorpresaBuffer.loadFromFile(fichero)){
        std::cerr << "Sonido " << fichero << " no se puede leer " << std::endl;
        return false;
    }
    return true;
}

/**
 * @brief Estructura interna con la implementación (debe ignorarse)
 */
struct Ventana::pimpl {
    Recursos rec; // Fonts, Texturas y Buffers de sonido
    sf::RenderWindow window;

    sf::CircleShape blanca, negra, posible;
    sf::Text msg_turno;
    sf::Text msg_estado;

    sf::Sound errorSound, finalSound, sorpresaSound;

    // Medidas donde está el tablero
    int xtab, ytab, // esquina superior izqda
        casillatab; // lado de cada casilla

    int filas, columnas;
    int turno;
    std::string estado; // '1','2','0','?'


    pimpl(): filas(0), columnas(0) {} // Cero si no se llamó a init

    void dibujar(); // Dibuja todos los objetos
};


void Ventana::pimpl::dibujar() {

    // Limpiar en blanco
    window.clear(sf::Color::White);

    // MARCOS del tablero
    sf::RectangleShape marco;
    marco.setFillColor(sf::Color::Black);
    // Arriba
    marco.setPosition  (sf::Vector2f(xtab-10,ytab-10));
    marco.setSize      (sf::Vector2f(columnas*casillatab+20,10));
    window.draw(marco);
    // izqda
    marco.setSize      (sf::Vector2f(10, filas*casillatab+20));
    window.draw(marco);
    // drcha
    marco.move(columnas*casillatab+10,0);
    window.draw(marco);
    // abajo
    marco.setPosition  (sf::Vector2f(xtab-10,ytab+filas*casillatab));
    marco.setSize      (sf::Vector2f(columnas*casillatab+20,10));
    window.draw(marco);

    // Líneas de casillas
    for (int i=1; i<columnas; ++i) {
       sf::Vertex linea[2]= {
          sf::Vertex(sf::Vector2f(xtab+ i*casillatab, ytab), sf::Color::Black),
          sf::Vertex(sf::Vector2f(xtab+ i*casillatab, ytab + filas*casillatab), sf::Color::Black)
        };
        window.draw(linea, 2, sf::Lines);
    }
    for (int i=1; i<filas; ++i) {
       sf::Vertex linea[2]= {
          sf::Vertex(sf::Vector2f(xtab , ytab + i*casillatab ), sf::Color::Black),
          sf::Vertex(sf::Vector2f(xtab+ columnas*casillatab, ytab+ i*casillatab ), sf::Color::Black)
        };
        window.draw(linea, 2, sf::Lines);
    }

    // Turno. Si vale cero no se dibuja nada

    if (turno== 1) {
        sf::Vector2f pos( xtab + (columnas / 2.0 ) * casillatab, casillatab / 2);
        blanca.setPosition(pos);
        window.draw(blanca);
    }
    if (turno==2) {
        sf::Vector2f pos( xtab + (columnas / 2.0 ) * casillatab, casillatab / 2);
        negra.setPosition(pos);
        window.draw(negra);
    }

    // Contenido de las casillas (fichas o figura con posible posición)

    for ( int fil= 0; fil< filas; ++fil)
        for (int col= 0; col< columnas; ++col) {
            sf::Vector2f pos(xtab + (col + 0.5)*casillatab , ytab + (fil + 0.5)*casillatab );
            if (estado[fil*columnas+col] == '1') {
                blanca.setPosition(pos);
                window.draw(blanca);
            }
            else if (estado[fil*columnas+col] == '2') {
                negra.setPosition(pos);
                window.draw(negra);
            }
            else if (estado[fil*columnas+col] == '?') {
                posible.setPosition(pos);
                window.draw(posible);
            }
        }

    // Mensajes
    window.draw(msg_turno);
    if (msg_estado.getString().getSize()>0)
        window.draw(msg_estado);

    // Una vez dibujado, lo refrescamos como frame actual
    window.display();
}

Ventana::Ventana() {
    rep= new pimpl; // Ahora sí puedo crear un pimpl, ya sabe qué es
}
Ventana::~Ventana() {
    delete rep;
}


bool Ventana::init(const char* resource_dir, unsigned int filas, unsigned int columnas, const char* titulo, unsigned int wpix, unsigned int hpix)
{
    if (filas<5 || columnas<5) {
        std::cerr << "Dimensiones de tablero " << filas << " y " << columnas << " demasiado pequeñas (al menos 5)" << std::endl;
        return false;
    }
    if (wpix<512 || hpix<512) {
        std::cerr << "Dimensiones gráficas" << wpix << " y " << hpix << " demasiado pequeñas (al menos 512)" << std::endl;
        return false;
    }
    if (!rep->rec.load(resource_dir)) {
        std::cerr << "Sin recursos no se puede continuar...";
        return false;
    }

    // Tamaños y posiciones
    int minwh= wpix<hpix?wpix:hpix;
    int maxcasillas= filas>columnas? filas : columnas;
    int lado_casilla= minwh/(maxcasillas+2); // Dejamos el ancho de una casilla por cada

    rep->xtab= (wpix - (lado_casilla * columnas)) /2;
    rep->ytab= (hpix - (lado_casilla * filas)) /2;
    rep->casillatab= lado_casilla;

    // Configuramos las fichas. Con posicionarlas y draw podemos dibujar las que queramos
    float mitad= rep->rec.textura_ficha.getSize().x / 2.0F;
    rep->blanca.setRadius( mitad );
    rep->blanca.setOrigin ( mitad, mitad);
    rep->blanca.setTexture( & (rep->rec.textura_ficha));
    rep->blanca.setFillColor(sf::Color::Red);
    rep->blanca.setScale( lado_casilla/(3*mitad), lado_casilla/(3*mitad) );

    rep->negra= rep->blanca;
    rep->negra.setFillColor(sf::Color::Blue);

    rep->posible= rep->blanca;
    rep->posible.setFillColor(sf::Color::White);
    rep->posible.setScale(lado_casilla/(6*mitad), lado_casilla/(6*mitad));

    // Mensajes de turno y de estado
    rep->msg_turno.setFont(rep->rec.font);
    rep->msg_turno.setString("Turno");
    rep->msg_turno.setCharacterSize(24); // En píxeles!
    rep->msg_turno.setColor(sf::Color::Blue);

    rep->msg_turno.setPosition( wpix/2 - lado_casilla/2 - rep->msg_turno.getLocalBounds().width ,
                                lado_casilla/2 - rep->msg_turno.getLocalBounds().height / 2);

    rep->msg_estado.setFont(rep->rec.font);
    rep->msg_estado.setString("Listo");
    rep->msg_estado.setCharacterSize(12); // En píxeles!
    rep->msg_estado.setColor(sf::Color::Blue);
    rep->msg_estado.setPosition( 5, hpix-30);

    // Creamos sonidos para poder activarlos con play
    rep->errorSound.setBuffer(rep->rec.errorBuffer);
    rep->finalSound.setBuffer(rep->rec.finalBuffer);
    rep->sorpresaSound.setBuffer(rep->rec.sorpresaBuffer);

    // Inicializamos el estado del tablero
    rep->filas= filas;
    rep->columnas= columnas;
    rep->turno= 1;
    rep->estado= std::string(filas*columnas, '0');

    // Preparamos la ventana de dibujo
    rep->window.create(sf::VideoMode(wpix,hpix), titulo);
    return true;
}

void Ventana::setTablero(int turno, const char *tablero)
{
    rep->turno= turno;
    rep->estado= tablero;
    rep->dibujar();
}

void Ventana::setEstado(const char *mensaje, bool esperarClick)
{
    rep->msg_estado.setString(mensaje);
    if (esperarClick)
        input(); // ignoramos lo que salga
}


void Ventana::setError(const char *mensaje)
{
    rep->msg_estado.setString(mensaje);
    rep->errorSound.play();
    rep->dibujar();
}

void Ventana::paso(int turno)
{
    char cadena[]= "Tiene que pasar. Pulse para seguir, el turno es de 0";
    cadena[std::strlen(cadena)-1]+= turno;

    rep->msg_estado.setString(cadena);
    rep->sorpresaSound.play();
    rep->dibujar();
    input(); // ignoramos lo que salga
}

void Ventana::final(int ganador) {

    rep->msg_estado.setString("La partida ha finalizado");
    rep->finalSound.play();

    sf::Clock reloj;
    std::string estado_inicial= rep->estado; // 1,2,0,?
    int segundos= reloj.getElapsedTime().asSeconds();

    // Hacemos más grande la ficha ganadora
    sf::CircleShape *ganadora= nullptr;
     sf::Vector2f old_scale;
    if (ganador==1) ganadora= &rep->blanca;
    if (ganador==2) ganadora= &rep->negra;

    if (ganadora) {
      old_scale= ganadora->getScale();
      ganadora->setScale(old_scale.x*2, old_scale.y*2);
    }

    while( segundos < 10 ) {
        if (reloj.getElapsedTime().asSeconds()> segundos) {
            segundos++;
            for (unsigned int i=0; i< rep->estado.size(); ++i )
                if (rep->estado[i]=='1')
                    rep->estado[i]= '2';
                else if (rep->estado[i]=='2') rep->estado[i]= '1';
            rep->turno= 0;
        }

        if (ganadora) {
          sf::Vector2f pos( rep->xtab + (rep->columnas / 2.0 ) * rep->casillatab, rep->casillatab / 2);
          ganadora->setPosition(pos);
          rep->window.draw(*ganadora);
        }

        rep->dibujar();
    }
    rep->estado= estado_inicial;
    if (ganadora)
      ganadora->setScale(old_scale);
    rep->dibujar();
}

Ventana::Input Ventana::input()
{
    if (rep->filas== 0 || rep->columnas==0) {
        std::cerr << "No se puede comenzar el juego sin llamar a init " << std::endl;
        std::abort();
    }

    Input res;
    res.tipo= Cerrar;

    while (rep->window.isOpen())
    {
        sf::Event event;
        while (rep->window.pollEvent(event))
        {
            switch (event.type) {

            // Si se pincha para cerrar ventana se cierra y la función acaba
            case sf::Event::Closed:
                rep->window.close();
                break;
            case sf::Event::TextEntered:
                if (static_cast<char>(event.text.unicode)=='?') { // Suponemos es ascii
                    res.tipo= Ayuda;
                    return res;
                }
                else if (static_cast<char>(event.text.unicode)=='!') { // Suponemos es ascii
                    res.tipo= Interrumpir;
                    return res;
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left){
                       sf::Vector2f real= rep->window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                       float x= real.x;
                       float y= real.y;
                       if (x > rep->xtab  && x < rep->xtab+ rep->columnas*rep->casillatab &&
                               y > rep->ytab  && y < rep->ytab+ rep->filas * rep->casillatab) {
                           res.tipo= Casilla;
                           res.fila=     (y - rep->ytab) / rep->casillatab;
                           res.columna=  (x - rep->xtab) / rep->casillatab;
                           return res;
                       }
                 }
                break;
            default:
                break;
            }
        }
        rep->dibujar(); // Redibujamos el frame actual
    }
    return res;
}

