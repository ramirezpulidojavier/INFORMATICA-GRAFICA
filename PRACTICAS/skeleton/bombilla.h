#ifndef BOMBILLA_H
#define BOMBILLA_H

#include "cono.h"


/*****************************************************************************//**
 * CLASE QUE CREA UN CONO A MODO BOMBILLA
 *
 * [USADA EN "LUCES"]
 *****************************************************************************/

class _bombilla
{

    _cono bombilla = _cono(80, 2, 1, 3); //_cono(numero_de_rotaciones, eje(0:x, 1:y, z:2), tamanio)


public:

  //Constructor
  _bombilla();

  //Funciones para dibujar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
