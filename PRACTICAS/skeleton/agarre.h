#ifndef AGARRE_H
#define AGARRE_H

#include "cilindro.h"

/*****************************************************************************//**
 * CLASE QUE CREA UN AGARRE PARA LAS ESCALERAS.
 * CILINDRO VERTICAL QUE IRA A CADA LADO DE LOS PELDANIOS
 *
 * [USADA EN "ESCALERAS"]
 *****************************************************************************/

class _agarre
{

    _cilindro agarre = _cilindro(80,2,1,3); //Creamos el agarre. _cilindro(numero_de_rotaciones, eje(0:x, 1:y, z:2), tamanio)


public:

  //Constructor
  _agarre();

  //Funciones para dibujar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
