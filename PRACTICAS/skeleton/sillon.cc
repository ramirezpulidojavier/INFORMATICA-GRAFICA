#include "sillon.h"


_sillon::_sillon(){



}

void _sillon::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //sillon

        //glColor3f(0,0,0);
        glScalef(0.5,1.08,1);
        sillon.draw_fill(flat, smooth);

    glPopMatrix();


}

void _sillon::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //sillon

        glScalef(0.5,1.08,1);
        sillon.draw_chess(flat, smooth);

    glPopMatrix();

}

void _sillon::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //sillon

        glScalef(0.5,1.08,1);
        sillon.draw_point();

    glPopMatrix();

}

void _sillon::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //sillon

        glScalef(0.5,1.08,1);
        sillon.draw_line();

    glPopMatrix();

}
