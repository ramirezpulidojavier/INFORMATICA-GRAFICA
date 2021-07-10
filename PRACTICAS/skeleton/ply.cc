/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "ply.h"
#include "file_ply_stl.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/


//Constructor vacio
_ply::_ply(const string &ply){


}

//Funcion que carga el play pasado como argumento en el objeto
void _ply::cargar_ply(const string &ply){

    //Creamos un archivo de tipo ply
    _file_ply a;
    //Vector donde se almacenaran los vertices leidos en el archivo
    vector<float> Vertices_ply;
    //Vector donde se almacenaran los triangulos leidos en el archivo
    vector<unsigned int> Triangles_ply;

    //Abrimos el archivo ply
    a.open(ply);
    //Leemos los Vertices y los Triangulos
    a.read(Vertices_ply, Triangles_ply);


    //Reservamos Vertices con un tercio de los vertices que haya leido (cada 3 coordenadas conforman un vertice)
    Vertices.resize(Vertices_ply.size()/3);

    for (int i=0; i<(int)Vertices.size(); i++){
        //Los metemos consecutivos de 3 en 3 en Vertices
        Vertices[i] = _vertex3f(Vertices_ply[i*3],Vertices_ply[i*3+1],Vertices_ply[i*3+2]);
    }

    //Reservamos Triangles con un tercio de los triangulos que haya leido (cada 3 vertices conforman un triangulo)
    Triangles.resize(Triangles_ply.size()/3);

    for (int i=0; i<(int)Triangles.size(); i++){
        //Los metemos consecutivos de 3 en 3 en Triangles
        Triangles[i] = _vertex3ui(Triangles_ply[i*3],Triangles_ply[i*3+1],Triangles_ply[i*3+2]);
    }

    //Se calculan las normales de la figura para que funcione con flat y smooth
    normal_creation_triangles_vertex();

    //Liberamos memoria porque no se usan mas estos vectores
    Vertices_ply.clear();
    Triangles_ply.clear();

    //Cerramos el fichero
    a.close();

}




