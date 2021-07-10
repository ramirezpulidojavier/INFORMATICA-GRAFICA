#include "luna_parabrisas.h"


_luna_parabrisas::_luna_parabrisas(){




}

void _luna_parabrisas::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luna

        luna.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //parabrisas

        glTranslatef(0,-0.1,0);
        parabrisas.draw_fill(flat, smooth);

    glPopMatrix();


}

void _luna_parabrisas::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luna

        luna.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //parabrisas

        glTranslatef(0,-0.1,0);
        parabrisas.draw_chess(flat, smooth);

    glPopMatrix();

}

void _luna_parabrisas::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luna

        luna.draw_point();

    glPopMatrix();

    glPushMatrix(); //parabrisas

        glTranslatef(0,-0.1,0);
        parabrisas.draw_point();

    glPopMatrix();

}

void _luna_parabrisas::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luna

        luna.draw_line();

    glPopMatrix();

    glPushMatrix(); //parabrisas

        glTranslatef(0,-0.1,0);
        parabrisas.draw_line();

    glPopMatrix();

}
