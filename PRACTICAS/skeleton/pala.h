#ifndef PALA_H
#define PALA_H

#include "cube.h"


/*****************************************************************************//**
 * CLASE QUE CREA LA PALA DE LA EXCAVADORA TRASERA (EN EL MODELO DE UN BRAZO, EQUIVALE A MANO)
 *
 * [USADA EN "BRAZO"]
 *****************************************************************************/

class _pala
{

    _cube lado = _cube(1); //Creamos un cubo que será reutilizado como base y paredes laterales, delantera y trasera


public:

  //Constructor
  _pala();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
