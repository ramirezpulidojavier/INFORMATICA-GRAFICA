/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "axis.h"

using namespace _colors_ne;


/*****************************************************************************//**
 * CONSTRUCTOR
 *
 *
 *****************************************************************************/

_axis::_axis(float Size)
{

  Vertices.clear();
  Vertices.resize(6);  //Ponia resize(5) pero si tiene 6 inserciones, no tiene sentido

  //Eje x
  Vertices[0]=_vertex3f(-Size,0,0);
  Vertices[1]=_vertex3f(Size,0,0);

  //Eje y
  Vertices[2]=_vertex3f(0,-Size,0);
  Vertices[3]=_vertex3f(0,Size,0);

  //Eje z
  Vertices[4]=_vertex3f(0,0,-Size);
  Vertices[5]=_vertex3f(0,0,Size);


}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _axis::draw_line()
{

  glLineWidth(1); //Ancho de la linea
  glBegin(GL_LINES);

  // eje X, color rojo
  glColor3fv((GLfloat *) &RED);
  glVertex3fv((GLfloat *) &Vertices[0]);
  glVertex3fv((GLfloat *) &Vertices[1]);

  // eje Y, color verde
  glColor3fv((GLfloat *) &GREEN);
  glVertex3fv((GLfloat *) &Vertices[2]);
  glVertex3fv((GLfloat *) &Vertices[3]);

  // eje Z, color azul
  glColor3fv((GLfloat *) &BLUE);
  glVertex3fv((GLfloat *) &Vertices[4]);
  glVertex3fv((GLfloat *) &Vertices[5]);
  glEnd();

}


