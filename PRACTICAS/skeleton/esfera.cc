/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "esfera.h"
#include <math.h>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_esfera::_esfera(int giros, int eje, double tam, int num_div, int tapas_totales)
{

    //punto_original es el punto que utilizaremos para generar el perfil a traves de rotaciones
    _vertex3f punto_original = _vertex3f(0, tam/2, 0);

    //Se rellena Vertices con los puntos calculados tras rotar el original sobre el eje z
    //num_div -> numero de rotaciones (cantidad de vertices que tendra el perfil)
    Vertices.clear();
    Vertices = esfera_creation(punto_original, num_div);

    //Con esto se genera un perfil destinado a ser girado sobre el eje y, pero de querer otro, se usa la siguiente funcion
        //Vertices -> Vector de vertices que contiene el perfil original
        //2 -> eje sobre el que estan actualmente los puntos adaptados (x:0, y:1, z:2)
        //eje -> eje sobre el que quiero los puntos adaptados (x:0, y:1, z:2)
    Vertices = conversionVertices(Vertices, 2, eje);

    //Una vez elegido el eje definitivo y teniendo el perfil adaptado, generamos el resto de vertices y triangulo de la figura completa
        //Vertices -> Contiene los puntos del perfil
        //eje -> eje sobre el que quiero girar el perfil (x:0, y:1, z:2)
        //giros -> Numero de rotaciones que queremos hacer alrededor del eje
        //tapas_totales -> Numero de tapas que el usuario quiere mostrar
    int tapaderas = circular_sweeping(Vertices, eje, giros, tapas_totales);

    //El numero de triangulos de la tapadera coincide con el numero de giros * numero de tapas
    //Adaptamos el numero de tapas que pide al usuario a lo que mete por pantalla (0-> 0tapas, 1/2-> 1tapa, 3->2tapas)
    if(tapas_totales == 1 || tapas_totales == 2){
        tapas_cant = giros;
        tapas_totales=1;
    }else if(tapas_totales == 3){
        tapas_cant = giros*2;
        tapas_totales=2;
    }else{
        tapas_cant = 0;
        tapas_totales = 0;
    }

    //For que corrige los vertices de la ultima cara de triangulos para que la textura no dé fallos
    //Desde 2*(num_div-tapas_totales) porque evitamos comprobar los primeros vertices
    for(unsigned int i = 2*(num_div-tapas_totales); i < Triangles.size()-tapas_cant;i++){

        //Cambio los vertices del perfil por otros con las mismas coordenadas pero
        //diferente posicion de la imagen (introducidos en circula_sweeping)
        if((int)Triangles[i]._0 < (num_div+1-tapaderas)) Triangles[i]._0 = Vertices.size() - tapas_totales - (num_div+1-tapaderas-Triangles[i]._0);

        if((int)Triangles[i]._1 < (num_div+1-tapaderas)) Triangles[i]._1 = Vertices.size() - tapas_totales - (num_div+1-tapaderas-Triangles[i]._1);

        if((int)Triangles[i]._2 < (num_div+1-tapaderas)) Triangles[i]._2 = Vertices.size() - tapas_totales - (num_div+1-tapaderas-Triangles[i]._2);

    }

    //Funcion que calcula la normal de los vertices y triangulos de la esfera
    normal_sphere_creation();

    float coordy; //Coordenada Y de la imagen que introducimos (empieza por 1)
    Textura.clear();

    //Bucle para rellenar el vector de Textura con las coordenadas de la imagen (size-tapas porque no pongo textura a las tapas, son negras)
    for(unsigned int i = 0; i<Vertices.size()-tapas_totales; i++){

      //Para calcular el arco entre un vertice y el siguiente y asi tener la medida de las divisiones de la imagen (tantas divisiones como rotaciones)
      float alpha = atan2(Vertices[i]._2, Vertices[i]._0);

      //Coordx sera la coordenada x de la imagen que meteremos en Textura
      //Como atan2 tiene dominio [-M_PI, M_PI], para pasarlo a [0, 1] (necesario para la imagen) hay que hacer lo siguiente:
      float coordx =(alpha + M_PI )/ (2.0f * M_PI);

      //El primer valor tras pasarlo a nuestro intervalo es 0.5, por lo que resto a 0.5 cada valor para empezar en 0 e ir en adelante
      //En cierto punto "coordx" sera mayor que 0.5 y la resta sera negativa (la imagen tiene valores de 0 a 1), por lo que lo hago positivo
      coordx = abs(0.5 - coordx);

      //A partir de la mitad de los puntos, empiezan a decrementar su valor (..., 0.45, 0.5, 0.45, ...) por lo que a partir de este punto
      //cojo (1-valor) para mantener la continuidad (..., 0.45, 0.5, (1-0.45), (1-0.4), ...)
      //Como hay dos vertices por giro (+ los dos finales), la mitad de vertices se habran calculado despues de 'giros' puntos
      if((int)i > ( ((giros+1) * (num_div+1-tapaderas)) /2) - (num_div-tapaderas)/2 ) coordx= 1-coordx;

      //Esta condicion se cumple con los puntos superiores de cada linea vertical y en esos puntos, la altura debe ser maxima (1)
      if(i%(num_div+1-tapaderas)==0) coordy=1;

      //Esta condicion se cumple con los puntos inferiores de cada linea vertical y en esos puntos, la altura debe ser minima (0)
      else if (((int)i -(num_div-tapaderas)) %(num_div+1-tapaderas) == 0) coordy=0;

      //Esta condicion se cumple para el resto de casos (puntos intermedios) donde la altura de la imagen que les corresponde es ya su altura
      //pero adaptada al intervalo [0,1] MISMO PROCEDIMIENTO QUE EN CILINDRO Y EN ATAN2
      else coordy = (Vertices[i]._1 + (tam/2))/tam;

      //Rellenamos textura
      Textura.push_back(_vertex2f( coordx , coordy));

    }


}

