/**
  * @file codificar.h
  * @brief Fichero cabecera para ocultar/revelar mensajes en imagenes.
  *
  * Permite ocultar/revelar un mensaje en una imagen.
  *
  */


#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_
#include "imagenES.h"


/**
  * @brief Oculta texto en una imagen y se almacena en un vector de char.
  *
  * @param buffer Vector donde se encuentra la imagen y donde se ocultará el texto.
  * @param ocultar Texto a ocultar en la imagen.
  * @pre 'buffer' debe ser una zona de memoria suficientemente grande como para que se pueda ocultar todo el texto.
  */
void Ocultar(unsigned char buffer[], const char ocultar[]);

  /**
  * @brief Revela texto oculto de una imagen y se almacena en otro vector.
  *
  * @param buffer Vector donde se encuentra la imagen junto con el texto oculto.
  * @param revelar Vector que contendrá el texto revelado de la imagen.
  * @param MAX Se refiere al máximo de caracteres que puede contener el vector del texto revelado.
  * @pre 'revelar' debe ser una zona de memoria suficientemente grande como para que se pueda almacenar todo el texto.
  */
void Revelar(unsigned char buffer[],char revelar[], const int MAX);


#endif
