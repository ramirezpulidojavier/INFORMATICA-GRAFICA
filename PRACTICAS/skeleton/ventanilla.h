#ifndef VENTANILLA_H
#define VENTANILLA_H

#include "cube.h"


/*****************************************************************************//**
 * CLASE QUE CREA LA VENTANILLA DE LA PUERTA (SIN RESTO DE PUERTA)
 *
 * [USADA EN "PUERTA_VENTANILLA"]
 *****************************************************************************/

class _ventanilla
{

    _cube ventanilla = _cube(1); //Creamos la ventanilla


public:

  //Constructor
  _ventanilla();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
