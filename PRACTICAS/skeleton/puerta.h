#ifndef PUERTA_H
#define PUERTA_H

#include "cube.h"


/*****************************************************************************//**
 * CLASE QUE CREA LA PUERTA (SIN VENTANILLA)
 *
 * [USADA EN "PUERTA_VENTANILLA"]
 *****************************************************************************/

class _puerta
{

    _cube puerta = _cube(1); //Creo una puerta


public:

  //Constructor
  _puerta();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
