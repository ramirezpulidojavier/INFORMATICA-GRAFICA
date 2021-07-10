#ifndef EXCAVADORA_H
#define EXCAVADORA_H

#include "coche.h"
#include "grua.h"


/*****************************************************************************//**
 * CLASE QUE UNE EL BRAZO QUE TIENE LA PALA (EXCAVADORA TRASERA) CON EL RESTO DEL CUERPO (SIN QUTIANIEVES)
 *
 * [USADA EN "EXCAVADORA_QUITANIEVES"]
 *****************************************************************************/

class _excavadora
{

    _coche coche = _coche();    //Creamos el coche
    _grua grua = _grua();       //Creamos la grua trasera


public:

  //Constructor
  _excavadora();

  //Funciones para dibujar
  void draw_fill(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_puerta, float libertad_ventanilla, float libertad_entero, bool flat, bool smooth);
  void draw_line(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_puerta, float libertad_ventanilla, float libertad_entero);
  void draw_point(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_puerta, float libertad_ventanilla, float libertad_entero);
  void draw_chess(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_puerta, float libertad_ventanilla, float libertad_entero, bool flat, bool smooth);

};


#endif
