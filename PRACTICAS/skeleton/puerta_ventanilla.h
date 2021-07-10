#ifndef PUERTA_VENTANILLA_H
#define PUERTA_VENTANILLA_H

#include "puerta.h"
#include "ventanilla.h"



/*****************************************************************************//**
 * CLASE QUE COMBINA UNA VENTANILLA Y UNA PUERTA PARA CREAR UNA PUERTA COMPLETA
 *
 * [USADA EN "SISTEMA_PUERTASVENTANILLA"]
 *****************************************************************************/

class _puerta_ventanilla
{

    _puerta puerta = _puerta();             //Creo una puerta
    _ventanilla ventanilla = _ventanilla(); //Creo una ventanilla


public:

  //Constructor
  _puerta_ventanilla();

  //Funciones para pintar
  void draw_fill(float libertad_ventanilla, bool flat, bool smooth);
  void draw_line(float libertad_ventanilla);
  void draw_point(float libertad_ventanilla);
  void draw_chess(float libertad_ventanilla, bool flat, bool smooth);

};


#endif
