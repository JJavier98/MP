#ifndef _AVANZAR_H
#define _AVANZAR_H
#include <fstream>
#include <iostream>

using namespace std;

void Avanzar(istream& is)
{
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}

#endif