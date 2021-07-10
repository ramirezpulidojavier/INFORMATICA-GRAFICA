#ifndef RUEDA_H
#define RUEDA_H

#include "cilindro.h"



/*****************************************************************************//**
 * CLASE QUE CREA UNA RUEDA QUE POSTERIORMENTE SERA USADA PARA LOS EJES
 *
 * [USADA EN "EJE_RUEDA"]
 *****************************************************************************/

class _rueda
{

    _cilindro rueda = _cilindro(80, 2, 1, 3); //Creo la rueda. _cilindro(numero_de_rotaciones, eje(0:x, 1:y, z:2), tamanio)


public:

  //Constructor
  _rueda();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
