#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include <cmath>


#ifndef MATERIAL_H
#define MATERIAL_H


class _material
{
private:

    //Atributos para los materiales
    //MATERIAL1
    GLfloat brass_ambient[3]={0.329412,0.223529,0.027451};
    GLfloat brass_diffuse[3]={0.780392,0.568627,0.113725};
    GLfloat brass_specular[3]={0.992157,0.941176,0.807843};
    GLfloat brass_shininess = 128*0.9;
    //MATERIAL1
    GLfloat cyan_rubber_ambient[3]={0.0,0.05,0.0};
    GLfloat cyan_rubber_diffuse[3]={0.4,0.5,0.5};
    GLfloat cyan_rubber_specular[3]={0.04,0.7,0.7};
    GLfloat cyan_rubber_shininess = 128*0.07;
    //MATERIAL1
    GLfloat blanco_ambient[3]={.1,.1,.1};
    GLfloat blanco_diffuse[3]={0.9,0.9,0.9};
    GLfloat blanco_specular[3]={0.9,.9,.9};
    GLfloat blanco_shininess = 128;

public:
    _material();
    void setColor1();
    void setColor2();
    void setColor3();
};

#endif // MATERIAL_H
