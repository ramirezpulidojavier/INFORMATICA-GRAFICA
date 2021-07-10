#ifndef AGARRE_QUITANIEVES_H
#define AGARRE_QUITANIEVES_H

#include "cilindro.h"

/*****************************************************************************//**
 * CLASE QUE CREA UN AGARRE QUE UNE EL QUITANIEVES DELANTERO AL RESTO DE FIGURA
 * ES UN CILINDRO, SIMILAR AL AGARRE DE LAS ESCALERAS
 *
 * [USADA EN "QUITANIEVES"]
 *****************************************************************************/

class _agarre_quitanieves
{

    _cilindro agarre = _cilindro(80, 2, 1, 3); //_cilindro(numero_de_rotaciones, eje(0:x, 1:y, z:2), tamanio)


public:

  //Constructor
  _agarre_quitanieves();

  //Funciones para dibujar
  void draw_fill(float libertad_estirar_quitanieves, bool flat, bool smooth);
  void draw_line(float libertad_estirar_quitanieves);
  void draw_point(float libertad_estirar_quitanieves);
  void draw_chess(float libertad_estirar_quitanieves, bool flat, bool smooth);

};


#endif
