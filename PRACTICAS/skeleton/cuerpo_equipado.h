#ifndef CUERPO_EQUIPADO_H
#define CUERPO_EQUIPADO_H

#include "sistema_escaleras.h"
#include "cuerpo.h"
#include "luces.h"


/*****************************************************************************//**
 * CLASE QUE ANIADE AL CUERPO DE LA FIGURA ESCALERAS LATERALES Y LUCES.
 * CON EL CUERPO COMPLETO, YA PODEMOS UNIRLE UNA CABEZA COMPLETA PARA HACER UN CHASIS
 *
 * [USADA EN "CHASIS"]
 *****************************************************************************/

class _cuerpo_equipado
{

    _luces luces = _luces();                            //Creo unas luces (formada por dos bombillas)
    _cuerpo cuerpo = _cuerpo();                         //Un cuerpo sin equipar
    _sistema_escaleras escaleras = _sistema_escaleras();//Sitema de escaleras laterales (dos escaleras)


public:

  //Constructor
  _cuerpo_equipado();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
