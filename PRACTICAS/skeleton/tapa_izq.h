#ifndef TAPA_IZQ_H
#define TAPA_IZQ_H

#include "cube.h"



/*****************************************************************************//**
 * CLASE QUE CERRARA LA CABEZA POR LA PARTE TRASERA.
 *
 * [USADA EN "CABEZA"]
 *****************************************************************************/

class _tapa_izq
{

    _cube tapa_izq = _cube(1); //Creamos la pared trasera de la cabeza


public:

  //Constructor
  _tapa_izq();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
