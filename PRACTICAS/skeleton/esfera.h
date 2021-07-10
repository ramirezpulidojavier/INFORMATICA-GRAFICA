/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef ESFERA_H
#define ESFERA_H

#include "rev.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _esfera:public _rev {

    private:

        int tapas_cant; //Cantidad de triangulos que conforman todas las tapaderas (ya sean 0, 1 o 2)

    public:

      //Constructor
      //giros-> numero de rotaciones del perfil sobre el eje seleccionado
      //eje -> eje sobre el que girar el perfil
      //tam -> longitud del diametro de la esfera
      //num_div -> cantidad de puntos que habra por cada rotacion (vertices del perfil)
      //tapas_elegidas -> las tapaderas elegidas para la figura (0: ninguna, 1: superior, 2:inferio, 3:ambas)
      _esfera(int giros, int eje, double tam, int num_div, int tapas_elegidas);

      //Funcion que devuelve la cantidad de triangulos que hacen de tapadera, ya sea superior, inferior, ambas o ninguna
      int get_tapas_cant(){return tapas_cant;}

};

#endif
