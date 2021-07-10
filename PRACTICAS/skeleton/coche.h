#ifndef CHOCHE_H
#define CHOCHE_H

#include "chasis.h"
#include "sistema_ruedas.h"

/*****************************************************************************//**
 * CLASE QUE COMBINA UN CHASIS (CUERPO COMPLETO + CABEZA RELLENA) CON UN SISTEMA DE RUEDAS
 * (DOS EJES CON RUEDAS) PARA FORMAR EL COCHE PRINCIPAL COMPLETO (SIN EXCAVADORA NI QUITANIEVES)
 *
 * [USADA EN "EXCAVADORA"]
 *****************************************************************************/

class _coche
{

    _chasis chasis = _chasis();                         //Creo un chasis
    _sistema_ruedas sistema_ruedas = _sistema_ruedas(); //Creo un sistema de ruedas (dos ejes)


public:

  //Constructor
  _coche();

  //Funciones para pintar
  void draw_fill(float libertad_puerta, float libertad_ventanilla, float libertad_entero, bool flat, bool smooth);
  void draw_line(float libertad_puerta, float libertad_ventanilla, float libertad_entero);
  void draw_point(float libertad_puerta, float libertad_ventanilla, float libertad_entero);
  void draw_chess(float libertad_puerta, float libertad_ventanilla, float libertad_entero, bool flat, bool smooth);

};


#endif
