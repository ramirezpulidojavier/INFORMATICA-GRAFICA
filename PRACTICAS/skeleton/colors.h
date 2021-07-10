/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef COLORS_H
#define COLORS_H

#include "vertex.h"

//Enum que contiene el nombre de los colores con su RGB correspondiente para usarlos por su nombre
//La forma de llamarlo en las clases que no tienen el using namespace _colors_ne, hay que poner _colors_ne:: antes del color
//Ejemplo glColor3fv((GLfloat *) &_colors_ne::COLORS[6]);
namespace _colors_ne {

  const _vertex3f RED(1,0,0);
  const _vertex3f GREEN(0,1,0);
  const _vertex3f BLUE(0,0,1);
  const _vertex3f CYAN(0,1,1);
  const _vertex3f MAGENTA(1,0,1);
  const _vertex3f YEllOW(1,1,0);
  const _vertex3f BLACK(0,0,0);
  const _vertex3f WHITE(1,1,1);

  //Vector de colores equivalente a las asignaciones anteriores (se usa con COLORS[X])
  const _vertex3f COLORS[]={RED,GREEN,BLUE,CYAN,MAGENTA,YEllOW,BLACK,WHITE};

}

#endif
