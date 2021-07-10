#include "ventanilla.h"


_ventanilla::_ventanilla(){



}

void _ventanilla::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //ventanilla

        //glColor3f(0,0,1);
        glScalef(0.6,1.3,0.195);
        ventanilla.draw_fill(flat, smooth);

    glPopMatrix();


}

void _ventanilla::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //ventanilla

        glScalef(0.6,1.3,0.195);
        ventanilla.draw_chess(flat, smooth);

    glPopMatrix();

}

void _ventanilla::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //ventanilla

        glScalef(0.6,1.3,0.195);
        ventanilla.draw_point();

    glPopMatrix();

}

void _ventanilla::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //ventanilla

        glScalef(0.6,1.3,0.195);
        ventanilla.draw_line();

    glPopMatrix();

}
