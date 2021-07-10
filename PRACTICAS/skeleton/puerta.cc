#include "puerta.h"


_puerta::_puerta(){



}

void _puerta::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta

        //glColor3f(1,1,0);
        glScalef(0.6,1.5,0.2);
        puerta.draw_fill(flat, smooth);

    glPopMatrix();

}

void _puerta::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta

        glScalef(0.6,1.5,0.2);
        puerta.draw_chess(flat, smooth);

    glPopMatrix();

}

void _puerta::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta

        glScalef(0.6,1.5,0.2);
        puerta.draw_point();

    glPopMatrix();

}

void _puerta::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta

        glScalef(0.6,1.5,0.2);
        puerta.draw_line();

    glPopMatrix();

}
