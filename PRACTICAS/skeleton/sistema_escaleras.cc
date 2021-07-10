#include "sistema_escaleras.h"


_sistema_escaleras::_sistema_escaleras(){




}

void _sistema_escaleras::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

        glTranslatef(0,0,1);
        escaleras.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(0,0,-1);
        escaleras.draw_fill(flat, smooth);

    glPopMatrix();



}

void _sistema_escaleras::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

        glTranslatef(0,0,1);
        escaleras.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix();

        glTranslatef(0,0,-1);
        escaleras.draw_chess(flat, smooth);

    glPopMatrix();


}

void _sistema_escaleras::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

        glTranslatef(0,0,1);
        escaleras.draw_point();

    glPopMatrix();

    glPushMatrix();

        glTranslatef(0,0,-1);
        escaleras.draw_point();

    glPopMatrix();


}

void _sistema_escaleras::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

        glTranslatef(0,0,1);
        escaleras.draw_line();

    glPopMatrix();

    glPushMatrix();

        glTranslatef(0,0,-1);
        escaleras.draw_line();

    glPopMatrix();

}
