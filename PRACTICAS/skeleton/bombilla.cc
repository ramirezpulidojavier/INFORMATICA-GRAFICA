#include "bombilla.h"


_bombilla::_bombilla(){



}

void _bombilla::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //bombilla

        //glColor3f(1,0,0);       //color rojo (en la p5 lo pinta todo en azul para el pick)
        glRotatef(-90, 0,0,1);
        glScalef(0.5,0.25,0.25);
        bombilla.draw_fill(flat, smooth);

    glPopMatrix();


}

void _bombilla::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //bombilla

        glRotatef(-90, 0,0,1);
        glScalef(0.5,0.25,0.25);
        bombilla.draw_chess(flat, smooth);

    glPopMatrix();

}

void _bombilla::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //bombilla

        glRotatef(-90, 0,0,1);
        glScalef(0.5,0.25,0.25);
        bombilla.draw_point();

    glPopMatrix();

}

void _bombilla::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //bombilla

        glRotatef(-90, 0,0,1);
        glScalef(0.5,0.25,0.25);
        bombilla.draw_line();

    glPopMatrix();

}
