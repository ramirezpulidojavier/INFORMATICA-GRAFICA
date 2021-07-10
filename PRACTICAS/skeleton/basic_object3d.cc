/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _basic_object3D::draw_point()
{

  glBegin(GL_POINTS);
  for (unsigned int i=0;i<Vertices.size();i++){

    glColor3f(0,0,0); //Pone color a negro para todos los puntos
    glVertex3fv((GLfloat *) &Vertices[i]);//Pinta

  }

  glEnd();

}
