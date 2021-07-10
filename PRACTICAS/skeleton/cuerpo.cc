#include "cuerpo.h"


_cuerpo::_cuerpo(){



}

void _cuerpo::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cuerpo

        //glColor3f(1,0.8,0);
        glScalef(3,1.5,2);
        cuerpo.draw_fill(flat, smooth);

    glPopMatrix();

}

void _cuerpo::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cuerpo

        glScalef(3,1.5,2);
        cuerpo.draw_chess(flat, smooth);

    glPopMatrix();

}

void _cuerpo::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cuerpo

        glScalef(3,1.5,2);
        cuerpo.draw_point();

    glPopMatrix();

}

void _cuerpo::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cuerpo

        glScalef(3,1.5,2);
        cuerpo.draw_line();

    glPopMatrix();

}
