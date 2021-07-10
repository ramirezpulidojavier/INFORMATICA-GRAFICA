/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef CONO_H
#define CONO_H

#include "rev.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cono:public _rev
{
public:

  //Constructor
  //giros -> numero de rotaciones del perfil sobre el eje elegido
  //eje -> sobre el que quiero rotarlo (x:0, y:1, z:2)
  //tam -> tamanio que tendra de alto y ancho el cono (altura y diametro de la base)
  //tapas_elegidas -> las tapaderas elegidas para la figura (0: ninguna, 1: superior, 2:inferio, 3:ambas)
  _cono(int giros, int eje, double tam, int tapas_elegidas);

};

#endif
