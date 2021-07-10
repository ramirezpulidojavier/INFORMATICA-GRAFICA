#ifndef SISTEMA_PUERTASVENTANILLA_H
#define SISTEMA_PUERTASVENTANILLA_H

#include "puerta_ventanilla.h"


/*****************************************************************************//**
 * CLASE QUE CREA DOS PUERTAS COMPLETAS (PUERTA + VENTANILLA) QUE SERAN LOS LATERALES DE LA CABEZA DE LA FIGURA
 *
 * [USADA EN "CABEZA"]
 *****************************************************************************/

class _sistema_puertasventanilla
{

    _puerta_ventanilla puerta_ventanilla= _puerta_ventanilla(); //Creamos una puerta+ventanilla que sera utlizada dos veces


public:

  //Constructor
  _sistema_puertasventanilla();

  //Funciones para pintar
  void draw_fill(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth);
  void draw_line(float libertad_puerta, float libertad_ventanilla);
  void draw_point(float libertad_puerta, float libertad_ventanilla);
  void draw_chess(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth);

};


#endif
