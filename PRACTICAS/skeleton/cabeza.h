#ifndef CABEZA_H
#define CABEZA_H

#include "luna_parabrisas.h"
#include "sistema_puertasventanilla.h"
#include "techo.h"
#include "tapa_izq.h"


/*****************************************************************************//**
 * CLASE QUE COMBINA VARIAS PIEZAS (LUNA_PARABRISAS, PUERTAS_VENTANILLAS, TECHO, TAPA_IZQUIERDA)
 * PARA FORMAR LA CABEZA DE LA FIGURA. NO SE HACE CON UN CUBO PARA PODER VERLA HUECA Y PODER MOVER VARIOS ELEMENTOS.
 * LA CABEZA NO ES TODO EL CHASIS, ESTA ESTÁ UNIDA A UN CUERPO
 *
 * [USADA EN "CABEZA_RELLENA"]
 *****************************************************************************/

class _cabeza
{

    _luna_parabrisas parabrisas =_luna_parabrisas(); //Creamos un luna_parabrisas para la parte delantera
    _sistema_puertasventanilla sistema_puerta_ventanilla = _sistema_puertasventanilla(); //Un sistema de puertas para los laterales
    _tapa_izq tapa_izq = _tapa_izq();   //Una tapa izquierda que es la pared que cierra por detras del asiento
    _techo techo = _techo();            //Un techo para cerra por arriba la cabeza


public:

  //Constructor
  _cabeza();

  //Funciones para pintar
  void draw_fill(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth);
  void draw_line(float libertad_puerta, float libertad_ventanilla);
  void draw_point(float libertad_puerta, float libertad_ventanilla);
  void draw_chess(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth);

};


#endif
