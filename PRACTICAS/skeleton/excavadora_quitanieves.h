#ifndef EXCAVADORA_QUITANIEVES_H
#define EXCAVADORA_QUITANIEVES_H

#include "excavadora.h"
#include "quitanieves.h"


/*****************************************************************************//**
 * FIGURA JERARQUICA COMPLETA. UNE UNA GRUA (CUERPO + BRAZO TRASERO) CON UN QUITANIEVES (PALA + AGARRE) DELANTERO
 *
 * [USADA EN "HIERARCHICAL"]
 *****************************************************************************/

class _excavadora_quitanieves
{

    _excavadora excavadora = _excavadora();     //Creamos una excavadora
    _quitanieves quitanieves = _quitanieves();  //Creamos un quitanieves


public:

  //Constructor
  _excavadora_quitanieves();

  //Funciones para dibujar
  void draw_fill(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves, bool flat, bool smooth);
  void draw_line(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves);
  void draw_point(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves);
  void draw_chess(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves, bool flat, bool smooth);

};


#endif
