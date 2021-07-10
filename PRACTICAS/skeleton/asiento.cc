#include "asiento.h"


_asiento::_asiento(){



}

void _asiento::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //respaldo

        glTranslatef(-0.25,0,0);
        respaldo.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //sillon

        glTranslatef(0.125,-0.81,0);
        sillon.draw_fill(flat, smooth);

    glPopMatrix();


}

void _asiento::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //respaldo

        glTranslatef(-0.25,0,0);
        respaldo.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //sillon

        glTranslatef(0.125,-0.81,0);
        sillon.draw_chess(flat, smooth);

    glPopMatrix();

}

void _asiento::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //respaldo

        glTranslatef(-0.25,0,0);
        respaldo.draw_point();

    glPopMatrix();

    glPushMatrix(); //sillon

        glTranslatef(0.125,-0.81,0);
        sillon.draw_point();

    glPopMatrix();

}

void _asiento::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //respaldo

        glTranslatef(-0.25,0,0);
        respaldo.draw_line();

    glPopMatrix();

    glPushMatrix(); //sillon

        glTranslatef(0.125,-0.81,0);
        sillon.draw_line();

    glPopMatrix();

}
