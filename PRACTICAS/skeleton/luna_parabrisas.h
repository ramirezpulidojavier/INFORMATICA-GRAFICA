#ifndef LUNA_PARABRISAS_H
#define LUNA_PARABRISAS_H

#include "parabrisas.h"
#include "luna.h"



/*****************************************************************************//**
 * CLASE QUE COMBINA UN PARABRISAS CON UNA LUNA PARA CREAR LA PARTE DELANTERA DE LA CABEZA DEL MODELO
 *
 * [USADA EN "CABEZA"]
 *****************************************************************************/

class _luna_parabrisas
{

    _luna luna = _luna();                   //Creamos la luna (cristal)
    _parabrisas parabrisas = _parabrisas(); //Creamos parabrisas (el marco)


public:

  //Constructor
  _luna_parabrisas();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
