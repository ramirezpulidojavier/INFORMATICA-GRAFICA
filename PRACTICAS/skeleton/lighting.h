#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include <cmath>


#ifndef LIGHTING_H
#define LIGHTING_H


class _lighting
{

private:

    //Atributos
    bool encendida; //booleano que especifica si una luz concreta esta encendida (un objeto de este tipo)
    GLenum luz;     //Contendra el tipo de luz que es (LIGHT0, LIGHT1, etc) de 0 a 7
    GLfloat ambiente[4];    //vector que contiene los valores del componente ambiental (los 3 primeros color y el ultimo intensidad)
    GLfloat especular[4];   //vector que contiene los valores del componente especular (los 3 primeros color y el ultimo intensidad)
    GLfloat difuso[4];      //vector que contiene los valores del componente difusion (los 3 primeros color y el ultimo intensidad)
    GLfloat pos[4];         //vector que contiene los valores de la posicion de la luz. Si es direccional los tres primeros son direccion y el ultimo 0
                                                                                      //Si es posicional los tres primeros son posicion y el ultimo 1

public:

    //Constructor que recibe un numero que indica el tipo de luz que queremos
    _lighting(int num);
    //Funcion que activa la luz actual
    void encender();
    //Funcion que apagar la luz actual
    void apagar();
    //Para modificar la componente ambiental de la luz
    void setAmbiente(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    //Para modificar la componente especular de la luz
    void setEspecular(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    //Para modificar la componente difusion de la luz
    void setDifuso(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    //Para modificar la posicion de la luz
    void setPos(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    //Para meter unos valores pro defecto en la luz
    void setValoresIniciales();


};

#endif // lightin_H
