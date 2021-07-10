#ifndef LUCES_H
#define LUCES_H

#include "bombilla.h"


/*****************************************************************************//**
 * CLASE QUE CREA DOS BOMBILLAS PARA GENERAR EL SISTEMA DE LUCES COMPLETO
 *
 * [USADA EN "CUERPO_EQUIPADO"]
 *****************************************************************************/

class _luces
{

    _bombilla bombilla = _bombilla(); //Creacion de la bombilla (luego se usa dos veces)


public:

  //Constructor
  _luces();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
