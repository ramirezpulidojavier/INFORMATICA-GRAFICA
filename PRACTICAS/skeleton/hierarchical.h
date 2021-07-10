#ifndef HIERARCHICAL_H
#define HIERARCHICAL_H

#include "excavadora_quitanieves.h"


/*****************************************************************************//**
 * CLASE QUE CREA EL MODELO JERARQUICO COMPLETO (GRUA EXCAVADORA QUITANIEVES)
 *
 * MODELO JERARQUICO COMPLETO
 *****************************************************************************/

class _hierarchical
{

    _excavadora_quitanieves excavadora_quitanieves = _excavadora_quitanieves(); //Creamos el modelo

public:

  //Constructor
  _hierarchical();

  //Funciones para pintar
  void draw_fill(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves, bool flat, bool smooth);
  void draw_line(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves);
  void draw_point(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves);
  void draw_chess(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves, bool flat, bool smooth);

};


#endif
