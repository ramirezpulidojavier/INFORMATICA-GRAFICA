/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line(){

    //Indica que el modo del poligono que se aplica es con ambas caras y que sera rasterizado en modo linea
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    //Delimita los vertices que definen una primitiva (hasta glEnd). El argumento especifica de que forma de las 10 que hay seran interpretados los vertices
    glBegin(GL_TRIANGLES); //Trata cada tripla de vertices como un triangulo independiente

    for(unsigned int i=0; i<Triangles.size();i++){
        //Pinta las lineas
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

     glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill(bool flat, bool smooth)
{

    //Se activa un modo u otro dependiendo del modo de iluminacion que seleccionemos
    if(smooth)
        glShadeModel(GL_SMOOTH);
    else if (flat)
        glShadeModel(GL_FLAT);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);


    for(unsigned int i=0; i<Triangles.size();i++){

        //Si estamos pintando justo el triangulo seleccionado con el pick cambiamos el color a amarillo
        if( (int)i == Selected_triangle )    glColor3fv((GLfloat *) &YEllOW);
        else glColor3fv((GLfloat *) &BLUE);

        if (smooth){ //Si es smooth se usan las normales de los vertices

                glNormal3f(Normal_vertex[Triangles[i]._0]._0,Normal_vertex[Triangles[i]._0]._1,Normal_vertex[Triangles[i]._0]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glNormal3f(Normal_vertex[Triangles[i]._1]._0,Normal_vertex[Triangles[i]._1]._1,Normal_vertex[Triangles[i]._1]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glNormal3f(Normal_vertex[Triangles[i]._2]._0,Normal_vertex[Triangles[i]._2]._1,Normal_vertex[Triangles[i]._2]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        }else if (flat){ //Si es flat se usan las normales de los triangulos

                glNormal3f(Normal_triangles[i]._0,Normal_triangles[i]._1,Normal_triangles[i]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

         }else { //Si no, se pinta normal

                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            }

        }


     glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_selected_objeto(bool flat, bool smooth)
{

    if(smooth)
        glShadeModel(GL_SMOOTH);
    else if (flat)
        glShadeModel(GL_FLAT);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);


    for(unsigned int i=0; i<Triangles.size();i++){

        if (smooth){

                glNormal3f(Normal_vertex[Triangles[i]._0]._0,Normal_vertex[Triangles[i]._0]._1,Normal_vertex[Triangles[i]._0]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glNormal3f(Normal_vertex[Triangles[i]._1]._0,Normal_vertex[Triangles[i]._1]._1,Normal_vertex[Triangles[i]._1]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glNormal3f(Normal_vertex[Triangles[i]._2]._0,Normal_vertex[Triangles[i]._2]._1,Normal_vertex[Triangles[i]._2]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        }else if (flat){

                glNormal3f(Normal_triangles[i]._0,Normal_triangles[i]._1,Normal_triangles[i]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

         }else {

                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            }

        }


     glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess(bool flat, bool smooth)
{

    if(smooth)
        glShadeModel(GL_SMOOTH);
    else if (flat)
        glShadeModel(GL_FLAT);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);

    for(unsigned int i=0; i<Triangles.size();i++){

        //Para los triangulos pares pinta en azul
        if(i%2==0)
            glColor3fv((GLfloat *) &BLUE);
        else //y los impartes en amarillo
            glColor3fv((GLfloat *) &YEllOW);

        if (smooth){

                glNormal3f(Normal_vertex[Triangles[i]._0]._0,Normal_vertex[Triangles[i]._0]._1,Normal_vertex[Triangles[i]._0]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glNormal3f(Normal_vertex[Triangles[i]._1]._0,Normal_vertex[Triangles[i]._1]._1,Normal_vertex[Triangles[i]._1]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glNormal3f(Normal_vertex[Triangles[i]._2]._0,Normal_vertex[Triangles[i]._2]._1,Normal_vertex[Triangles[i]._2]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        }else if (flat){

                glNormal3f(Normal_triangles[i]._0,Normal_triangles[i]._1,Normal_triangles[i]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

         }else {

                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            }
    }
     glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::normal_creation_triangles_vertex(){

    //Vectores de cada triangulo para hacer el producto vectorial y sacar la normal
    _vertex3f vectorA;
    _vertex3f vectorB;

    //Valores que almacenaran la suma de las normales de los triangulos que convergen en un punto para hacer la normal de este vertice
    float suma_normales_x = 0;
    float suma_normales_y = 0;
    float suma_normales_z = 0;
    //Lleva la  cuenta de cuantos triangulos convergen en cada vertice para dividir la media
    int triangulos_convergentes = 0;

    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);

    //Vaciamos los vertices antes de llenarlos por si tienen basura
    Normal_triangles.clear();
    Normal_vertex.clear();

    //Habra tantas normales de triangulos como triangulos haya
    Normal_triangles.resize(Triangles.size()); //Dar tamaño a Normal_triangles
    //Habra tantas normales de vertices como vertices haya
    Normal_vertex.resize(Vertices.size()); //Dar tamaño a Normal_vertex

    //Para cada triangulo
    for (unsigned int i=0; i<Triangles.size(); i++){

        //VECTOR A
        vectorA._0 = Vertices[Triangles[i]._1]._0 - Vertices[Triangles[i]._0]._0;
        vectorA._1 = Vertices[Triangles[i]._1]._1 - Vertices[Triangles[i]._0]._1;
        vectorA._2 = Vertices[Triangles[i]._1]._2 - Vertices[Triangles[i]._0]._2;

        //VECTOR B
        vectorB._0 = Vertices[Triangles[i]._2]._0 - Vertices[Triangles[i]._0]._0;
        vectorB._1 = Vertices[Triangles[i]._2]._1 - Vertices[Triangles[i]._0]._1;
        vectorB._2 = Vertices[Triangles[i]._2]._2 - Vertices[Triangles[i]._0]._2;

        //VECTOR NORMALES (En Normal[i] tendremos la normal de Triangles[i])
        Normal_triangles[i]._0 = (vectorA._1 * vectorB._2) - (vectorA._2 * vectorB._1);
        Normal_triangles[i]._1 = -1 * ((vectorA._0 * vectorB._2) - (vectorA._2 * vectorB._0));
        Normal_triangles[i]._2 = (vectorA._0 * vectorB._1) - (vectorA._1 * vectorB._0);

    }

    //NORMALIZACION DEL VECTOR DE NORMALES DE TRIANGLES PARA QUE TENGAN MODULO 1
    for (unsigned int i=0; i<Normal_triangles.size(); i++){

        float modulo = sqrt( pow(Normal_triangles[i]._0, 2) + pow(Normal_triangles[i]._1, 2) + pow(Normal_triangles[i]._2, 2) );

        if(modulo!=0){
            Normal_triangles[i]._0 = Normal_triangles[i]._0 / modulo;
            Normal_triangles[i]._1 = Normal_triangles[i]._1 / modulo;
            Normal_triangles[i]._2 = Normal_triangles[i]._2 / modulo;
        }else{
            Normal_triangles[i]._0 = 0;
            Normal_triangles[i]._1 = 0;
            Normal_triangles[i]._2 = 0;
        }

    }

    //NORMALES DE UN VECTOR DE VERTICES
    for (unsigned int i=0; i<Vertices.size(); i++){

        suma_normales_x = suma_normales_y = suma_normales_z = 0; //para cada vertice
        triangulos_convergentes = 0; //para cada coordenada

        for (unsigned int j=0; j<Triangles.size(); j++){

            if(i == Vertices.size()-4 || i== 0){ //En el caso del cilindro, para evitar fallo en la continuidad de las luces

                if (Triangles[j]._0 == Vertices.size()-4 || Triangles[j]._1 == Vertices.size()-4 || Triangles[j]._2 == Vertices.size()-4 || Triangles[j]._0 == 0 || Triangles[j]._1 == 0 || Triangles[j]._2 == 0){
                    suma_normales_x += Normal_triangles[j]._0;
                    suma_normales_y += Normal_triangles[j]._1;
                    suma_normales_z += Normal_triangles[j]._2;
                    triangulos_convergentes++;

                }

            }else if(i == Vertices.size()-3 || i== 1){ //En el caso del cilindro, para evitar fallo en la continuidad de las luces

                if (Triangles[j]._0 == Vertices.size()-3 || Triangles[j]._1 == Vertices.size()-3 || Triangles[j]._2 == Vertices.size()-3 || Triangles[j]._0 == 1 || Triangles[j]._1 == 1 || Triangles[j]._2 == 1){
                    suma_normales_x += Normal_triangles[j]._0;
                    suma_normales_y += Normal_triangles[j]._1;
                    suma_normales_z += Normal_triangles[j]._2;
                    triangulos_convergentes++;

                }

            }else{//Si no, comprueba que triangulos utilizan el vertice que estoy comprobando y lo suma para la media

                if (Triangles[j]._0 == i || Triangles[j]._1 == i || Triangles[j]._2 == i){
                    suma_normales_x += Normal_triangles[j]._0;
                    suma_normales_y += Normal_triangles[j]._1;
                    suma_normales_z += Normal_triangles[j]._2;
                    triangulos_convergentes++;

                }

            }
        }

        if(triangulos_convergentes!=0){
            Normal_vertex[i]._0 = suma_normales_x / triangulos_convergentes;
            Normal_vertex[i]._1 = suma_normales_y / triangulos_convergentes;
            Normal_vertex[i]._2 = suma_normales_z / triangulos_convergentes;
        }else{
            Normal_vertex[i]._0 = 0;
            Normal_vertex[i]._1 = 0;
            Normal_vertex[i]._2 = 0;
        }

    }


    //NORMALIZACION DEL VECTOR DE NORMALES DE VERTICES
    for (unsigned int i=0; i<Normal_vertex.size(); i++){

        float modulo = sqrt( pow(Normal_vertex[i]._0, 2) + pow(Normal_vertex[i]._1, 2) + pow(Normal_vertex[i]._2, 2) );

        if(modulo==0){
            Normal_vertex[i]._0 = 0;
            Normal_vertex[i]._1 = 0;
            Normal_vertex[i]._2 = 0;
        }else{
            Normal_vertex[i]._0 = Normal_vertex[i]._0 / modulo;
            Normal_vertex[i]._1 = Normal_vertex[i]._1 / modulo;
            Normal_vertex[i]._2 = Normal_vertex[i]._2 / modulo;
        }


    }

 glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::normal_sphere_creation(){

    float suma_normales_x = 0;
    float suma_normales_y = 0;
    float suma_normales_z = 0;

    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);

    //Limpiamos los vectores
    Normal_triangles.clear();
    Normal_vertex.clear();

    Normal_triangles.resize(Triangles.size()); //Dar tamaño a Normal_triangles
    Normal_vertex.resize(Vertices.size()); //Dar tamaño a Normal_vertex


    //NORMALES DE UN VECTOR DE VERTICES
    Normal_vertex = Vertices;


    //NORMALIZACION DEL VECTOR DE NORMALES DE VERTICES
    for (unsigned int i=0; i<Normal_vertex.size(); i++){

        float modulo = sqrt( pow(Normal_vertex[i]._0, 2) + pow(Normal_vertex[i]._1, 2) + pow(Normal_vertex[i]._2, 2) );

        if (modulo ==0){

            Normal_vertex[i]._0 = 0;
            Normal_vertex[i]._1 = 0;
            Normal_vertex[i]._2 = 0;

        }else{


            Normal_vertex[i]._0 = Normal_vertex[i]._0 / modulo;
            Normal_vertex[i]._1 = Normal_vertex[i]._1 / modulo;
            Normal_vertex[i]._2 = Normal_vertex[i]._2 / modulo;

        }
    }

    //NORMALES DE TRIANGLES
    for (unsigned int i=0; i<Triangles.size(); i++){
        suma_normales_x = 0;
        suma_normales_y = 0;
        suma_normales_z = 0;

        suma_normales_x += Normal_vertex[Triangles[i]._0]._0 + Normal_vertex[Triangles[i]._1]._0 + Normal_vertex[Triangles[i]._2]._0;
        suma_normales_y += Normal_vertex[Triangles[i]._0]._1 + Normal_vertex[Triangles[i]._1]._1 + Normal_vertex[Triangles[i]._2]._1;
        suma_normales_z += Normal_vertex[Triangles[i]._0]._2 + Normal_vertex[Triangles[i]._1]._2 + Normal_vertex[Triangles[i]._2]._2;
        Normal_triangles[i]._0 = suma_normales_x / 3;
        Normal_triangles[i]._1 = suma_normales_y / 3;
        Normal_triangles[i]._2 = suma_normales_z / 3;
    }

    //NORMALIZACION DEL VECTOR DE NORMALES DE TRIANGLES
    for (unsigned int i=0; i<Normal_triangles.size(); i++){

        float modulo = sqrt( pow(Normal_triangles[i]._0, 2) + pow(Normal_triangles[i]._1, 2) + pow(Normal_triangles[i]._2, 2) );

        if (modulo ==0){

            Normal_triangles[i]._0 = 0;
            Normal_triangles[i]._1 = 0;
            Normal_triangles[i]._2 = 0;

        }else{

            Normal_triangles[i]._0 = Normal_triangles[i]._0 / modulo;
            Normal_triangles[i]._1 = Normal_triangles[i]._1 / modulo;
            Normal_triangles[i]._2 = Normal_triangles[i]._2 / modulo;

        }
    }


}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_textura(bool flat, bool smooth){

    if(smooth)
        glShadeModel(GL_SMOOTH);
    else if (flat)
        glShadeModel(GL_FLAT);

    glEnable(GL_TEXTURE_2D); //Se habilita el modo textura 2D
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0; i < Triangles.size(); ++i){

        if (smooth){

            glNormal3f(Normal_vertex[Triangles[i]._0]._0,Normal_vertex[Triangles[i]._0]._1,Normal_vertex[Triangles[i]._0]._2);
            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._0]); //Esto es lo nuevo, se llama al vector de texturas para pintar
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

            glNormal3f(Normal_vertex[Triangles[i]._1]._0,Normal_vertex[Triangles[i]._1]._1,Normal_vertex[Triangles[i]._1]._2);
            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

            glNormal3f(Normal_vertex[Triangles[i]._2]._0,Normal_vertex[Triangles[i]._2]._1,Normal_vertex[Triangles[i]._2]._2);
            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._2]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        }else if (flat){

            glNormal3f(Normal_triangles[i]._0,Normal_triangles[i]._1,Normal_triangles[i]._2);
            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._2]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

         }else {

            glColor3fv((GLfloat *) &WHITE);


            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

            glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._2]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        }

    }

    glEnd();
    glDisable(GL_TEXTURE_2D);

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_textura_extra(bool flat, bool smooth, int tapas_cant){

    if(smooth)
        glShadeModel(GL_SMOOTH);
    else if (flat)
        glShadeModel(GL_FLAT);

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0; i < Triangles.size(); ++i){

        if (smooth){

            if( i >= Triangles.size() - tapas_cant ){

                glColor3fv((GLfloat *) &BLACK); //tapaderas negras

                glNormal3f(Normal_vertex[Triangles[i]._0]._0,Normal_vertex[Triangles[i]._0]._1,Normal_vertex[Triangles[i]._0]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glNormal3f(Normal_vertex[Triangles[i]._1]._0,Normal_vertex[Triangles[i]._1]._1,Normal_vertex[Triangles[i]._1]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glNormal3f(Normal_vertex[Triangles[i]._2]._0,Normal_vertex[Triangles[i]._2]._1,Normal_vertex[Triangles[i]._2]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            }else{

                glNormal3f(Normal_vertex[Triangles[i]._0]._0,Normal_vertex[Triangles[i]._0]._1,Normal_vertex[Triangles[i]._0]._2);
                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

                glNormal3f(Normal_vertex[Triangles[i]._1]._0,Normal_vertex[Triangles[i]._1]._1,Normal_vertex[Triangles[i]._1]._2);
                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

                glNormal3f(Normal_vertex[Triangles[i]._2]._0,Normal_vertex[Triangles[i]._2]._1,Normal_vertex[Triangles[i]._2]._2);
                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._2]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            }

        }else if (flat){

            if( i >= Triangles.size() - tapas_cant ){

                glColor3fv((GLfloat *) &BLACK); //tapaderas negras

                glNormal3f(Normal_triangles[i]._0,Normal_triangles[i]._1,Normal_triangles[i]._2);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            }else{

                glNormal3f(Normal_triangles[i]._0,Normal_triangles[i]._1,Normal_triangles[i]._2);
                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._2]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            }

         }else {

            glColor3fv((GLfloat *) &WHITE);

            if( i >= Triangles.size() - tapas_cant ){

                glColor3fv((GLfloat *) &BLACK); //tapaderas negras

                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            } else {

                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

                glTexCoord2fv((GLfloat *) &Textura[Triangles[i]._2]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

            }



      }

    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_selection()
{
    //Creamos un elemento con 3 floats para almacenar el color (R,G,B)
    _vertex3f id_color;
    //Creamos un elemento con 4 floats para almacenar el color con 4 bytes (XRGB) como se almacena un entero (XYZW)
    _vertex4f color;

    //Cogido del fill
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);

    //Para todos los triangulos de la figura
    for (unsigned int i=0;i<Triangles.size();i++){

            id_color.r = (i & 0x00FF0000) >> 16;
            id_color.g = (i & 0x0000FF00) >> 8;
            id_color.b = i & 0x000000FF;
            id_color /= 255.0;
            color = _vertex4f(id_color.r,id_color.g,id_color.b,1); //Como glColor3fv recibe un vector de 3 elementos (rgb) pongo 0 al final que no servira (en el paso inverso es desplazado y los ultimos 8 bits desaparecen)

            glColor3fv((GLfloat *) &color);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);


    }
    glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_selection_nuevo(int i)
{

    _vertex3f id_color;
    _vertex4f color;

    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonOffset(-1,1);
    glBegin(GL_TRIANGLES);

        id_color.r = (i & 0x00FF0000) >> 16;
        id_color.g = (i & 0x0000FF00) >> 8;
        id_color.b = i & 0x000000FF;
        id_color /= 255.0;
        color = _vertex4f(id_color.r,id_color.g,id_color.b,0);


        for (unsigned int j=0;j<Triangles.size();j++){
            glColor3fv((GLfloat *) &color);
            glVertex3fv((GLfloat *) &Vertices[Triangles[j]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[j]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[j]._2]);

        }

    glEnd();

}





