/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "ply_perfil.h"
#include "file_ply_stl.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/


//Constructor
_ply_perfil::_ply_perfil(const string &ply){

}


void _ply_perfil::cargar_ply_perfil(const string &ply){

    //Creamos un archivo de tipo ply
    _file_ply a;
    //Vector donde se almacenaran los vertices leidos en el archivo
    vector<float> Vertices_ply;

    int giros; //numero de rotaciones que leera del archivo
    int eje;   //Eje para el que esta adaptado el perfil

    //Abrimos el archivo ply
    a.open(ply);
    //Leemos los Vertices y los Triangulos
    a.read_perfil(Vertices_ply, eje, giros);

    //Reservamos Vertices con un tercio de los vertices que haya leido (cada 3 coordenadas conforman un vertice)
    Vertices.resize(Vertices_ply.size()/3);

    //Rellenamos Vertices con los leidos
    for (int i=0; i<(int)Vertices.size(); i++){
        //Los metemos consecutivos de 3 en 3 en Vertices
        Vertices[i] = _vertex3f(Vertices_ply[i*3],Vertices_ply[i*3+1],Vertices_ply[i*3+2]);
    }

    //Rotamos la figura y generamos el resto de triangulos y vertices de la figura
    circular_sweeping(Vertices, eje, giros, 1); //CAMBIAR LAS TAPAS PARA QUE MUESTRE LAS QUE HAY

    //Calculo la normal para los vertices y triangulos de la figura
    normal_creation_triangles_vertex();

    //Cerramos el fichero
    a.close();
}
