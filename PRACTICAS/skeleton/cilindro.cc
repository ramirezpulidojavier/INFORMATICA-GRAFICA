/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "cilindro.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cilindro::_cilindro(int giros, int eje, double tam, int tapas_totales)
{

    //Resize para meter el perfil (el del cilindro tiene 4 puntos)
    Vertices.clear();
    Vertices.resize(4);

    //PUNTOS PARA EL PERFIL QUE GIRA EN EL EJE X
    //Vertices[0] = _vertex3f(tam/2,0,0);
    //Vertices[1] = _vertex3f(tam/2,tam/2,0);
    //Vertices[2] = _vertex3f(-tam/2,tam/2,0);
    //Vertices[3] = _vertex3f(-tam/2,0,0);

    //PUNTOS PARA EL PERFIL QUE GIRA EN EL EJE Y
    Vertices[0] = _vertex3f(0,tam/2,0);
    Vertices[1] = _vertex3f(tam/2,tam/2,0);
    Vertices[2] = _vertex3f(tam/2,-tam/2,0);
    Vertices[3] = _vertex3f(0,-tam/2,0);

    //PUNTOS PARA EL PERFIL QUE GIRA EN EL EJE Z
    //Vertices[0] = _vertex3f(0,0,tam/2);
    //Vertices[1] = _vertex3f(0,tam/2,tam/2);
    //Vertices[2] = _vertex3f(0,tam/2,-tam/2);
    //Vertices[3] = _vertex3f(0,0,-tam/2);


    //Convierto el perfil en otro con los mismos puntos pero adaptados a que giren sobre el perfil que yo quiera
    //Vertices -> Vector de vertices que contiene el perfil original
    //2 -> eje sobre el que estan actualmente los puntos adaptados (x:0, y:1, z:2)
    //eje -> eje sobre el que quiero los puntos adaptados (x:0, y:1, z:2)
    Vertices = conversionVertices(Vertices, 2, eje);

    //Funcion encargada de la rotacion del perfil sobre el eje indicado
    //Vertices -> Contiene los puntos del perfil
    //eje -> eje sobre el que quiero girar el perfil (x:0, y:1, z:2)
    //giros -> Numero de rotaciones que queremos hacer alrededor del eje
    //tapas_totales -> Numero de tapas que el usuario quiere mostrar
    circular_sweeping(Vertices, eje, giros, tapas_totales);

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

    //Vaciamos textura antes de rellenarlo por si tiene basura dentro
    Textura.clear();

    //For que corrige los vertices de la ultima cara de triangulos para que la textura no dé fallos
    for(unsigned int i = 2*(giros-1); i < Triangles.size() - tapas_cant;i++){

        if(Triangles[i]._0 == 0) Triangles[i]._0 = Vertices.size()-2-tapas_totales;
        if(Triangles[i]._0 == 1) Triangles[i]._0 = Vertices.size()-1-tapas_totales;

        if(Triangles[i]._1 == 0) Triangles[i]._1 = Vertices.size()-2-tapas_totales;
        if(Triangles[i]._1 == 1) Triangles[i]._1 = Vertices.size()-1-tapas_totales;

        if(Triangles[i]._2 == 0) Triangles[i]._2 = Vertices.size()-2-tapas_totales;
        if(Triangles[i]._2 == 1) Triangles[i]._2 = Vertices.size()-1-tapas_totales;


    }

    //Llamamos a la funcion que crea las normales para triangulos y vertices del cilindro
    normal_creation_triangles_vertex();

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
      if((int)i>giros) coordx= 1-coordx;

      //Le metemos a textura cada coordx calculada y como altura de la imagen le pasamos la altura que tiene el vertice en dicho punto
      //pero adaptada al intervalo [0, 1] que es donde tienen que estar los valores para la imagen (mismo procedimiento que linea 92)
      Textura.push_back(_vertex2f(coordx, (Vertices[i]._1 + (tam/2))/tam));

    }


}



