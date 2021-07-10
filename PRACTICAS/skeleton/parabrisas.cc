#include "parabrisas.h"


_parabrisas::_parabrisas(){



}

void _parabrisas::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //parabrisas

        //glColor3f(0,0,0.75);
        glScalef(0.3,2.8,1.6);
        parabrisas.draw_fill(flat, smooth);

    glPopMatrix();


}

void _parabrisas::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //parabrisas

        glScalef(0.3,2.8,1.6);
        parabrisas.draw_chess(flat, smooth);

    glPopMatrix();

}

void _parabrisas::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //parabrisas

        glScalef(0.3,2.8,1.6);
        parabrisas.draw_point();

    glPopMatrix();

}

void _parabrisas::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //parabrisas

        glScalef(0.3,2.8,1.6);
        parabrisas.draw_line();

    glPopMatrix();

}
