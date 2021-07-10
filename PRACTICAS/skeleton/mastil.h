#ifndef MASTIL_H
#define MASTIL_H

#include "cilindro.h"



/*****************************************************************************//**
 * CREA LA PIEZA QUE UNE EL COCHE CON LA VIGA+PALA TRASERAS.
 * EN EL MODELO DE UN BRAZO COMPLETO, SERÍA LA PARTE DEL HOMBRO AL CODO Y SE COMBINA CON "BRAZO" PARA FORMAR LA GRUA
 *
 * [USADA EN "GRUA"]
 *****************************************************************************/

class _mastil
{

    _cilindro mastil = _cilindro(4, 2, 1, 3); //Creo mastil con un cilindro de 4 giros (similar a un cubo). _cilindro(numero_de_rotaciones, eje(0:x, 1:y, z:2), tamanio)


public:

  //Constructor
  _mastil();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
