/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef CUBE_H
#define CUBE_H

#include "object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cube:public _object3D
{
public:

  //Constructor
  //Tam -> tamanio del cubo
  _cube(double tam=1.0);

};

#endif
