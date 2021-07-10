#ifndef ESCALERAS_H
#define ESCALERAS_H

#include "agarre.h"
#include "peldanios.h"


/*****************************************************************************//**
 * CLASE QUE COMBINA LOS PELDANIOS CON LOS AGARRES PARA FORMAR UNA ESCALERA LATERAL COMPLETA
 *
 * [USADA EN "SISTEMA_ESCALERAS"]
 *****************************************************************************/

class _escaleras
{

    _agarre agarre = _agarre();         //Creamos el agarre
    _peldanios peldanio = _peldanios(); //Creamos el peldanio


public:

  //Constructor
  _escaleras();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
