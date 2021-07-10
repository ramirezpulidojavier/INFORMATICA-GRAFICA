#ifndef SILLON_H
#define SILLON_H

#include "cube.h"

/*****************************************************************************//**
 * CLASE QUE CREA LA PARTE BAJA DEL ASIENTO QUE IRA DENTRO DE LA CABEZA
 *
 * [USADA EN "ASIENTO"]
 *****************************************************************************/

class _sillon
{

    _cube sillon = _cube(1); //Creo el sillon


public:

  //Constructor
  _sillon();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
