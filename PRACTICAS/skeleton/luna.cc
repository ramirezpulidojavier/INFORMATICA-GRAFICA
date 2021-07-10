#include "luna.h"


_luna::_luna(){



}

void _luna::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luna

        //glColor3f(1,1,0);
        glScalef(0.2,3,2);
        luna.draw_fill(flat, smooth);

    glPopMatrix();


}

void _luna::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luna

        glScalef(0.2,3,2);
        luna.draw_chess(flat, smooth);

    glPopMatrix();

}

void _luna::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luna

        glScalef(0.2,3,2);
        luna.draw_point();

    glPopMatrix();

}

void _luna::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luna

        glScalef(0.2,3,2);
        luna.draw_line();

    glPopMatrix();

}
