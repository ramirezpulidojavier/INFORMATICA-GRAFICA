#ifndef CUERPO_QUITANIEVES_H
#define CUERPO_QUITANIEVES_H

#include "cube.h"



/*****************************************************************************//**
 * CLASE QUE CREA LA "PALA" DEL QUITANIEVES. SE UNIRAN A TRAVES DE UN 'AGARRE' AL RESTO DE COCHE
 *
 * [USADA EN "QUITANIEVES"]
 *****************************************************************************/

class _cuerpo_quitanieves
{

    _cube base = _cube(1);   //Creamos la base de la pala
    _cube lado = _cube(1);   //Creamos los laterales de la pala
    _cube pared = _cube(1);  //Creamos la pared trasera de la pala (a la que va unida el agarre)


public:

  //Constructor
  _cuerpo_quitanieves();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
