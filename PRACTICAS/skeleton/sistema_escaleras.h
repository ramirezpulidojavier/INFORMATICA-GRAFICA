#ifndef SISTEMA_ESCALERAS_H
#define SISTEMA_ESCALERAS_H

#include "escaleras.h"


/*****************************************************************************//**
 * CLASE QUE CREA DOS ESCALERAS PARA SER ANIADIDAS LUEGO AL CUERPO DE LA FIGURA COMO COMPLEMENTO
 *
 * [USADA EN "CUERPO_EQUIPADO"]
 *****************************************************************************/

class _sistema_escaleras
{

    _escaleras escaleras= _escaleras(); //Creamos unas escaleras que utilizaremos dos veces


public:

  //Constructor
  _sistema_escaleras();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
