#ifndef BRAZO_H
#define BRAZO_H

#include "pala.h"
#include "viga.h"


/*****************************************************************************//**
 * CLASE QUE CREA LA PIEZA QUE COMBINA LA PALA EXCAVADORA TRASERA CON EL BRAZO
 * SIMILAR A MANO + ANTEBRAZO
 *
 * [USADA EN "GRUA"]
 *****************************************************************************/

class _brazo
{
    _pala pala = _pala(); //Creamos una pala ("mano")
    _viga viga = _viga(); //Creamos una viga ("antebrazo")


public:

  //Constructor
  _brazo();

  //Funciones para pintar
  void draw_fill(float libertad_codo_brazo, float libertad_pala, bool flat, bool smooth);
  void draw_line(float libertad_codo_brazo, float libertad_pala);
  void draw_point(float libertad_codo_brazo, float libertad_pala);
  void draw_chess(float libertad_codo_brazo, float libertad_pala, bool flat, bool smooth);

};


#endif
