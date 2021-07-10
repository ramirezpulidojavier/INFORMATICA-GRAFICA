/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef PLY_PERFIL_H
#define PLY_PERFIL_H

#include "rev.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _ply_perfil:public _rev
{
public:

  //Constructor
  _ply_perfil(const string &ply);
  //Abre un archivo de tipo ply y lo carga en el objeto de ply_perfil
  void cargar_ply_perfil(const string &ply);


};

#endif
