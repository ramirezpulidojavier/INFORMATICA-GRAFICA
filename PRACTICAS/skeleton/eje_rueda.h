#ifndef EJE_RUEDA_H
#define EJE_RUEDA_H

#include "eje.h"
#include "rueda.h"


/*****************************************************************************//**
 * CLASE QUE CREA UN EJE CON UNA RUEDA EN CADA EXTREMO
 *
 * [USADA EN "SISTEMA_RUEDAS"]
 *****************************************************************************/

class _eje_rueda
{

    _rueda rueda= _rueda(); //Creamos la rueda
    _eje eje = _eje();      //Creamos el eje


public:

  //Constructor
  _eje_rueda();

  //Funciones para pintar
  void draw_fill(bool flat, bool smooth);
  void draw_line();
  void draw_point();
  void draw_chess(bool flat, bool smooth);

};


#endif
