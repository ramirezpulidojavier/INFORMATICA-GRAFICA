#include "peldanios.h"


_peldanios::_peldanios(){



}

void _peldanios::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //peldanio

        //glColor3f(0,0,0);
        glRotatef(90,0,0,1);
        glScalef(0.05,1,0.05);
        peldanio.draw_fill(flat, smooth);

    glPopMatrix();

}

void _peldanios::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //peldanio

        glRotatef(90,0,0,1);
        glScalef(0.05,1,0.05);
        peldanio.draw_chess(flat, smooth);

    glPopMatrix();

}

void _peldanios::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //peldanio

        glRotatef(90,0,0,1);
        glScalef(0.05,1,0.05);
        peldanio.draw_point();

    glPopMatrix();

}

void _peldanios::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //peldanio

        glRotatef(90,0,0,1);
        glScalef(0.05,1,0.05);
        peldanio.draw_line();

    glPopMatrix();

}
