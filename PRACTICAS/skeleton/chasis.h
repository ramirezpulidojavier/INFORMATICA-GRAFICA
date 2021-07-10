#ifndef CHASIS_H
#define CHASIS_H

#include "cabeza_rellena.h"
#include "cuerpo_equipado.h"


/*****************************************************************************//**
 * CLASE QUE COMBINA UN CUERPO EQUIPADO (ESCALERAS, LUCES, ETC) CON UNA CABEZA RELLENA (CON ASIENTO DENTRO)
 * ESTO SI CONFORMA UN CHASIS COMPLETO
 *
 * [USADA EN "COCHE"]
 *****************************************************************************/

class _chasis
{

    _cabeza_rellena cabeza = _cabeza_rellena();     //Creo una cabeza rellena
    _cuerpo_equipado cuerpo = _cuerpo_equipado();   //Creo un cuerpo completo


public:

  //Constructor
  _chasis();

  //Funciones para pintar
  void draw_fill(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth);
  void draw_line(float libertad_puerta, float libertad_ventanilla);
  void draw_point(float libertad_puerta, float libertad_ventanilla);
  void draw_chess(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth);

};


#endif
