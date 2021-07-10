#ifndef EJE_H
#define EJE_H

#include "cilindro.h"



/*****************************************************************************//**
 * CLASE QUE CREA UN EJE QUE UNE DOS RUEDAS.
 *
 * [USADA EN "EJE_RUEDA"]
 *****************************************************************************/

class _eje
{

    _cilindro eje = _cilindro(80, 2, 1, 3); //Creamos el eje. _cilindro(numero_de_rotaciones, eje(0:x, 1:y, z:2), tamanio)


public:

  //Constructor
  _eje();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
