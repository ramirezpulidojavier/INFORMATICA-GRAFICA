/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "cono.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cono::_cono(int giros, int eje, double tam, int tapas_totales)
{

    Vertices.clear();
    Vertices.resize(3);

    //PUNTOS PARA EL PERFIL QUE GIRA EN EL EJE X
    //Vertices[0] = _vertex3f(tam/2,0,0);
    //Vertices[1] = _vertex3f(-tam/2,tam/2,0);
    //Vertices[2] = _vertex3f(-tam/2,0,0);

    //PUNTOS PARA EL PERFIL QUE GIRA EN EL EJE Y
    Vertices[0] = _vertex3f(0,tam/2,0);
    Vertices[1] = _vertex3f(tam/2,-tam/2,0);
    Vertices[2] = _vertex3f(0,-tam/2,0);

    //PUNTOS PARA EL PERFIL QUE GIRA EN EL EJE Z
    //Vertices[0] = _vertex3f(0,0,tam/2);
    //Vertices[1] = _vertex3f(0,tam/2,-tam/2);
    //Vertices[2] = _vertex3f(0,0,-tam/2);

    //Funcion que convierten un perfil adaptado a un vertice en otro perfil con los mismos puntos adaptados a otro vertice
    //Vertices -> vector con el perfil original
    //2 -> eje al que viene adaptado Vertices (x:0, y:1, z:2)
    //eje -> eje al que quiero adaptar los puntos con el nuevo perfil (x:0, y:1, z:2)
    Vertices = conversionVertices(Vertices, 2, eje);

    //Funcion que rota el perfil sobre el eje seleccionado y genera los triangulos y vertices correspondientes
    //Vertices -> vector con el perfil definitivo
    //eje -> eje sobre el que voy a girar el perfil (x:0, y:1, z:2)
    //giros -> numero de rotaciones que hara sobre el eje
    circular_sweeping(Vertices, eje, giros, tapas_totales);

    //Funcion que calcula la normal de los triangulos y vertices de la figura
    normal_creation_triangles_vertex();

}

