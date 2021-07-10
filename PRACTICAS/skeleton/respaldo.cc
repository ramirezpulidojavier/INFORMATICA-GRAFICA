#include "respaldo.h"


_respaldo::_respaldo(){



}

void _respaldo::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //respaldo

        //glColor3f(0,0,0);
        glScalef(0.25,2.7,1);
        respaldo.draw_fill(flat, smooth);

    glPopMatrix();


}

void _respaldo::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //respaldo

        glScalef(0.25,2.7,1);
        respaldo.draw_chess(flat, smooth);

    glPopMatrix();

}

void _respaldo::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //respaldo

        glScalef(0.25,2.7,1);
        respaldo.draw_point();

    glPopMatrix();


}

void _respaldo::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //respaldo

        glScalef(0.25,2.7,1);
        respaldo.draw_line();

    glPopMatrix();


}
