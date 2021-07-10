#ifndef SISTEMA_RUEDAS_H
#define SISTEMA_RUEDAS_H

#include "eje_rueda.h"


/*****************************************************************************//**
 * CLASE QUE CREA DOS EJES CON RUEDAS PARA HACER EL SISTEMA DE RUEDAS DE LA FIGURA (LAS 4 RUEDAS Y LOS 2 EJES)
 *
 * [USADA EN "COCHE"]
 *****************************************************************************/

class _sistema_ruedas
{

    _eje_rueda eje_rueda= _eje_rueda(); //Creamos un ejeruedas que sera utilizado dos veces


public:

  //Constructor
  _sistema_ruedas();

  //Funciones para pintar
  void draw_fill(bool libertad_entero, bool flat, bool smooth);
  void draw_line(bool libertad_entero);
  void draw_point(bool libertad_entero);
  void draw_chess(bool libertad_entero, bool flat, bool smooth);

};


#endif
