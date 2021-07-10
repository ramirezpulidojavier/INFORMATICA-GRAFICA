/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef CILINDRO_H
#define CILINDRO_H

#include "rev.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cilindro:public _rev {

    private:

        int tapas_cant; //Cantidad de triangulos que conforman todas las tapaderas (ya sean 0, 1 o 2)

    public:

      //Constructor
      //giros -> numero de rotaciones del perfil alrededor de un eje
      //eje -> eje sobre el que rotar el perfil (0:x, 1:y, 2:z)
      //tam -> tamanio del cilindro (de ancho y de largo)
      //tapas_elegidas -> las tapaderas elegidas para la figura (0: ninguna, 1: superior, 2:inferio, 3:ambas)
      _cilindro(int giros, int eje, double tam, int tapas_totales);

      //Funcion que devuelve la cantidad de triangulos que tiene en las tapaderas
      int get_tapas_cant(){return tapas_cant;}

};

#endif
