#ifndef LIMPIAPARABRISAS_H
#define LIMPIAPARABRISAS_H

#include "cilindro.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _limpiaparabrisas
{

    _cilindro limpiaparabrisas = _cilindro(20,2,1);


public:
  _limpiaparabrisas();
  void draw_fill(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero);
  void draw_line(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero);
  void draw_point(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero);
  void draw_chess(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero);
};


#endif // GRAPADORA_H
