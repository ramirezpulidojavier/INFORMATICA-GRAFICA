#ifndef RESPALDO_H
#define RESPALDO_H

#include "cube.h"

/*****************************************************************************//**
 * CLASE QUE CREA LA PARTE TRASERA DEL ASIENTO QUE SE COLOCA DENTRO DE LA CABEZA
 *
 * [USADA EN "ASIENTO"]
 *****************************************************************************/

class _respaldo
{

    _cube respaldo = _cube(1); //Creo el respaldo


public:

  //Contructor
  _respaldo();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
