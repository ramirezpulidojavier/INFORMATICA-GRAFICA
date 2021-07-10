#ifndef QUITANIEVES_H
#define QUITANIEVES_H

#include "cuerpo_quitanieves.h"
#include "agarre_quitanieves.h"




/*****************************************************************************//**
 * CLASE QUE COMBINA EL AGARRE JUNTO A LA PALA DELANTERA PARA HACER UN QUITANIEVES COMPLETO.
 * ESTE VA UNIDO AL RESTO DE FIGURA
 *
 * [USADA EN "EXCAVADORA_QUTIANIEVES"]
 *****************************************************************************/

class _quitanieves
{

    _cuerpo_quitanieves cuerpo = _cuerpo_quitanieves(); //Creo la pala del quitanieves
    _agarre_quitanieves agarre = _agarre_quitanieves(); //Creo el agarre del quitanieves


public:

  //Constructor
  _quitanieves();

  //Funciones para pintar
  void draw_fill(float libertad_estirar_quitanieves, bool flat, bool smooth);
  void draw_line(float libertad_estirar_quitanieves);
  void draw_point(float libertad_estirar_quitanieves);
  void draw_chess(float libertad_estirar_quitanieves, bool flat, bool smooth);

};


#endif
