#ifndef CUERPO_H
#define CUERPO_H

#include "cube.h"


/*****************************************************************************//**
 * CLASE QUE CREA UN CUERPO PARA EL OBJETO, ESTE SE COMPLETA CON ESCALERAS Y LUCES
 * MAS TARDE Y LUEGO SE UNE A UNA CABEZA RELLENA (CON ASIENTO DENTRO)
 *
 * [USADA EN "CUERPO_EQUIPADO"]
 *****************************************************************************/

class _cuerpo
{

    _cube cuerpo = _cube(1); //Creamos un cuerpo


public:

  //Constructor
  _cuerpo();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
