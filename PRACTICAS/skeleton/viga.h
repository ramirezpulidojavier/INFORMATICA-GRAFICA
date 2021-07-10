#ifndef VIGA_H
#define VIGA_H

#include "cilindro.h"

/*****************************************************************************//**
 * CLASE QUE CREA LA UNION DEL MASTIL A LA PALA DE LA EXCAVADORA (EQUIVALENTE AL ANTEBRAZO EN LA FIGURA DE UN BRAZO)
 *
 * [USADA EN "BRAZO"]
 *****************************************************************************/

class _viga
{


    _cilindro viga = _cilindro(4, 2, 1, 3); //Creo la viga. _cilindro(numero_de_rotaciones, eje(0:x, 1:y, z:2), tamanio)


public:

  //Constructor
  _viga();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
