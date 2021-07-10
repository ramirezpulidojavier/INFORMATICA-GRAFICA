#ifndef LUNA_H
#define LUNA_H

#include "cube.h"

/*****************************************************************************//**
 * CLASE QUE CREA EL CRISTAL DELANTERO DE LA CABEZA. SE USA COMBINADA A UN PARABRISAS QUE SIRVE DE MARCO
 *
 * [USADA EN "LUNA_PARABRISAS"]
 *****************************************************************************/

class _luna
{

    _cube luna = _cube(1); //Creamos un cubo que será el cristal


public:

  //Constructor
  _luna();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
