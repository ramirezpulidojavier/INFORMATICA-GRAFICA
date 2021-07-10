#include "rueda.h"


_rueda::_rueda(){




}

void _rueda::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //rueda

        //glColor3f(0,0,0);
        glRotatef(90,1,0,0);
        glScalef(1,0.25,1);
        rueda.draw_fill(flat, smooth);

    glPopMatrix();


}

void _rueda::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //rueda

        glRotatef(90,1,0,0);
        glScalef(1,0.25,1);
        rueda.draw_chess(flat, smooth);

    glPopMatrix();


}

void _rueda::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //rueda

        glRotatef(90,1,0,0);
        glScalef(1,0.25,1);
        rueda.draw_point();

    glPopMatrix();



}

void _rueda::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //rueda

        glRotatef(90,1,0,0);
        glScalef(1,0.25,1);
        rueda.draw_line();

    glPopMatrix();


}
