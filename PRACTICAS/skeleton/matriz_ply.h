/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MATRIZ_PLY_H
#define MATRIZ_PLY_H

#include "ply.h"
#include "colors.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _matriz_ply:public _object3D
{
private:

    _ply interno = _ply(" "); //Objeto ply que estara introducido en la matriz
   vector<vector<_ply>> matriz; //Matriz que contendra los 16 objetos

public:

  _matriz_ply();
  //Funciones de pintado
  void draw_matriz_fill(bool flat, bool smooth);
  void draw_matriz_chess(bool flat, bool smooth);
  void draw_matriz_line();
  void draw_matriz_points();
  //Dibuja la figura en los buffers invisibles dando un color diferente a cada una de estas
  void draw_selection_matriz();

};

#endif
