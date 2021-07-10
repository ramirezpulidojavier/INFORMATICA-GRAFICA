#ifndef TECHO_H
#define TECHO_H

#include "cube.h"


/*****************************************************************************//**
 * CLASE QUE CREA LA PIEZA SUPERIOR DE LA CABEZA
 *
 * [USADA EN "CABEZA"]
 *****************************************************************************/

class _techo
{

    _cube techo = _cube(1); //Creamos el techo


public:

  //Constructor
  _techo();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
