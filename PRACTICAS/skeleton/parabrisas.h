#ifndef PARABRISAS_H
#define PARABRISAS_H

#include "cube.h"



/*****************************************************************************//**
 * CLASE QUE CREA LA PIZA QUE ACTUA COMO MARCO DE LA LUNA. JUNTO A ESTA FORMAN LA PARTE DELANTERA DE LA CABEZA DE LA FIGURA
 *
 * [USADA EN "LUNA_PARABRISAS"]
 *****************************************************************************/

class _parabrisas
{

    _cube parabrisas = _cube(1); //Creo cubo que sera marco del cristal


public:

  //Constructor
  _parabrisas();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
