/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef PLY_H
#define PLY_H

#include "object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _ply:public _object3D
{
public:

   //Constructor
  _ply(const string &ply);
  //Abre un archivo de tipo ply y lo carga en el objeto de ply_perfil
  void cargar_ply(const string &ply);


};

#endif
