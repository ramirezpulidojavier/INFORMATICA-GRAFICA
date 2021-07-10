#ifndef EJE_RUEDAS_H
#define EJE_RUEDAS_H

#include "eje.h"
#include "rueda.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _eje_ruedas
{

_eje eje = _eje();
_rueda rueda = _rueda();

public:
  _eje_ruedas();
  void draw_eje_ruedas_points(float libertad1, float libertad2, float libertad3, float libertad4, float libertad_puerta, float libertad_ventanilla, float libertad_limpia);
  void draw_eje_ruedas_lines(float libertad1, float libertad2, float libertad3, float libertad4, float libertad_puerta, float libertad_ventanilla, float libertad_limpia);
  void draw_eje_ruedas_chess(float libertad1, float libertad2, float libertad3, float libertad4, float libertad_puerta, float libertad_ventanilla, float libertad_limpia);
  void draw_eje_ruedas_fill(float libertad1, float libertad2, float libertad3, float libertad4, float libertad_puerta, float libertad_ventanilla, float libertad_limpia);
};


#endif // EJE_RUEDAS_H
