#ifndef ASIENTO_H
#define ASIENTO_H

#include "respaldo.h"
#include "sillon.h"

/*****************************************************************************//**
 * CLASE QUE COMBINA UN RESPALDO Y UN SILLON PARA CREAR UN ASIENTO
 *
 * [USADA EN "CABEZA_RELLENA"]
 *****************************************************************************/

class _asiento
{

    _respaldo respaldo = _respaldo(); //Creamos un respaldo
    _sillon sillon = _sillon();       //Creamos un sillon


public:

  //Constructor
  _asiento();

  //Funciones para dibujar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
