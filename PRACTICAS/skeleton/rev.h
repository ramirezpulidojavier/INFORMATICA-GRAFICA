/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef REV_H
#define REV_H

#include "object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _rev:public _object3D{

    public:

      //Constructor
      _rev();

      //Funcion que rota un punto sobre el eje z para generar el perfil de la esfera con el mismo arco entre las divisiones
      //punto -> vertice original que queremos girar para obtener el resto
      //num_div -> numero de veces a rotar ese punto original (que determinara cuantos vertices tiene el perfil)
      vector<_vertex3f> esfera_creation(_vertex3f punto, int num_div);

      //Funcion que rota un perfil sobre el eje seleccionado para generar el resto de vertices y triangulos de la figura
      //verti -> vector que contiene el perfil a rotar
      //eje -> eje sobre el que girar el perfil
      //n -> numero de rotaciones sobre el eje elegido
      //tapas_elegidas -> numero de tapas que quiero mostrar
      int circular_sweeping(vector<_vertex3f> verti, int eje, int n, int tapas_elegidas);

      //Funcion que convierte los puntos de un perfil adaptados al giro sobre un eje a otro perfil con los mismos puntos pero para otro eje
      //verti -> vector que contiene el perfil a rotar
      //eje1 -> eje para el que esta adaptado el perfil
      //eje2 -> eje para el que quiero adaptado el perfil
      vector<_vertex3f> conversionVertices(vector <_vertex3f> verti, int eje1, int eje2);

};

#endif
