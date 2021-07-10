#ifndef CABEZA_RELLENA_H
#define CABEZA_RELLENA_H

#include "cabeza.h"
#include "asiento.h"


/*****************************************************************************//**
 * CLASE QUE COMBINA UNA CABEZA CON UN ASIENTO COLOCADO EN SU INTERIOR PARA FORMAR UNA CABEZA COMPLETA
 *
 * [USADA EN "CHASIS"]
 *****************************************************************************/

class _cabeza_rellena
{

    _cabeza cabeza = _cabeza();     //Creamos una cabeza
    _asiento asiento = _asiento();  //Creamos un asiento que ira en el interior de la cabeza


public:

   //Constructor
  _cabeza_rellena();

  //Funciones para pintar
  void draw_fill(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth);
  void draw_line(float libertad_puerta, float libertad_ventanilla);
  void draw_point(float libertad_puerta, float libertad_ventanilla);
  void draw_chess(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth);

};


#endif
