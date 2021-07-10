#ifndef PELDANIOS_H
#define PELDANIOS_H

#include "cilindro.h"

/*****************************************************************************//**
 * CLASE QUE CREA LO QUE SERIAN LAS BARRAS HORIZONTALES DE LAS ESCALERAS (PELDANIOS DE ESTA)
 *
 * [USADA EN "ESCALERAS"]
 *****************************************************************************/

class _peldanios
{

    _cilindro peldanio = _cilindro(80,2,1,3); //Creo un peldanio que sera reutilizado. _cilindro(numero_de_rotaciones, eje(0:x, 1:y, z:2), tamanio)


public:

  //Constructor
  _peldanios();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
