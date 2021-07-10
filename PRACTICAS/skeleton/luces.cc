#include "luces.h"


_luces::_luces(){



}

void _luces::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luz1

        //glColor3f(1,0,0);
        glTranslatef(0,0, 0.5);
        bombilla.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //luz2

        //glColor3f(1,0,0);
        glTranslatef(0,0,-0.5);
        bombilla.draw_fill(flat, smooth);

    glPopMatrix();


}

void _luces::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luz1

        glColor3f(1,0,0);
        glTranslatef(0,0, 0.5);
        bombilla.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //luz2

        glColor3f(1,0,0);
        glTranslatef(0,0,-0.5);
        bombilla.draw_chess(flat, smooth);

    glPopMatrix();

}

void _luces::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luz1

        glColor3f(1,0,0);
        glTranslatef(0,0, 0.5);
        bombilla.draw_point();

    glPopMatrix();

    glPushMatrix(); //luz2

        glColor3f(1,0,0);
        glTranslatef(0,0,-0.5);
        bombilla.draw_point();

    glPopMatrix();

}

void _luces::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //luz1

        glTranslatef(0,0, 0.5);
        bombilla.draw_line();

    glPopMatrix();

    glPushMatrix(); //luz2

        glTranslatef(0,0,-0.5);
        bombilla.draw_line();

    glPopMatrix();

}
