/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{

    public:
        //Como esta clase es heredada por todos los objetos, aqui es donde se crean los vectores que contienen los vertices, triangulos, texturas, etc
        vector<_vertex3ui> Triangles;
        vector<_vertex3f> Normal_triangles;
        vector<_vertex3f> Normal_vertex;
        vector<_vertex2f> Textura;

        //Constructor que pone el triangulo seleccionado de todos los objetos a -1 inicialmente (ninguno valido)
        _object3D(){Selected_triangle=-1;};

        //Funciones de dibujado
        void draw_line();
        void draw_fill(bool flat, bool smooth);
        void draw_chess(bool flat, bool smooth) ;

        //Funcion que calcula la normal de los vertices y triangulos para las luces
        void normal_creation_triangles_vertex() ;
        //Funcion que calcula la normal de los vertices y triangulos para la esfera
        void normal_sphere_creation();
        //Funcion que pinta la imagen de la textura sobre los objetos
        void draw_textura(bool flat, bool smooth);
        //Funcion que pinta la imagen de la textura sobre el cilindro y la esfera
        void draw_textura_extra(bool flat, bool smooth, int tapas_cant);
        //Funcion que pinta el objeto en los buffers ocultos con los colores univocos para cada triangulo
        void draw_selection();
        //Funcion que pinta la matriz en los buffers ocultos con los colores univocos para cada objeto
        void draw_selection_nuevo(int i);
        //Funcion similar a fill pero para la matriz, porque esta no pinta triangulos en azul y amarillo, sino objetos enteros
        void draw_selected_objeto(bool flat, bool smooth);

        //Set de selected triangle
        void selected_triangle(int Selected_triangle1){Selected_triangle=Selected_triangle1;};
        //Get de selected triangle
        int selected_triangle(){return Selected_triangle;};

    protected:
        //Todos los objetos tienen este atributo para la funcion pick
        int Selected_triangle;

};

#endif // OBJECT3D_H
