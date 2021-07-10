#include "material.h"

_material::_material()
{}

void _material::setColor1()
{
    //Establece los valores para el material segun los creados en los atributos
    glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &brass_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &brass_diffuse);
    glMaterialfv(GL_FRONT,GL_SHININESS,&brass_shininess);
    glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &brass_specular);
}

void _material::setColor2()
{
    //Establece los valores para el material segun los creados en los atributos
    glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &cyan_rubber_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &cyan_rubber_diffuse);
    glMaterialfv(GL_FRONT,GL_SHININESS,&cyan_rubber_shininess);
    glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &cyan_rubber_specular);
}

void _material::setColor3()
{
    //Establece los valores para el material segun los creados en los atributos
    glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &blanco_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &blanco_diffuse);
    glMaterialfv(GL_FRONT,GL_SHININESS,&blanco_shininess);
    glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &blanco_specular);

}

