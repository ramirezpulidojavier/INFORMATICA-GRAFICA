#ifndef GRUA_H
#define GRUA_H

#include "mastil.h"
#include "brazo.h"

/*****************************************************************************//**
 * CLASE QUE UNE EL BRAZO DE LA EXCAVADORA (PALA+VIGA = MANO+ANTEBRAZO) CON EL MASTIL PARA COMPLETAR
 * LA EXCAVADORA TRASERA
 *
 * [USADA EN "EXCAVADORA"]
 *****************************************************************************/

class _grua
{

    _mastil mastil = _mastil(); //Creamos un mastil (parte del codo al hombro)
    _brazo brazo = _brazo();    //Creamos un brazo (formado por pala y viga ("mano + antebrazo"))


public:

  //Constructor
  _grua();

  //Funciones para dibujar
  void draw_fill(float libertad_codo_brazo, float libertad_pala, bool flat, bool smooth);
  void draw_line(float libertad_codo_brazo, float libertad_pala);
  void draw_point(float libertad_codo_brazo, float libertad_pala);
  void draw_chess(float libertad_codo_brazo, float libertad_pala, bool flat, bool smooth);

};


#endif
