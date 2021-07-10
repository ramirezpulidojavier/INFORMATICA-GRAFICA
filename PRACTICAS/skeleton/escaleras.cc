#include "escaleras.h"


_escaleras::_escaleras(){



}

void _escaleras::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre1

        glTranslatef(-0.5,0,0);
        agarre.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //agarre2

        glTranslatef(0.5,0,0);
        agarre.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //peldanio2

        glTranslatef(0,0,0);
        peldanio.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //peldanio1

        glTranslatef(0,-0.25,0);
        peldanio.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //peldanio3

        glTranslatef(0,0.25,0);
        peldanio.draw_fill(flat, smooth);

    glPopMatrix();


}

void _escaleras::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre1

        glTranslatef(-0.5,0,0);
        agarre.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //agarre2

        glTranslatef(0.5,0,0);
        agarre.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //peldanio2

        glTranslatef(0,0,0);
        peldanio.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //peldanio1

        glTranslatef(0,-0.25,0);
        peldanio.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //peldanio3

        glTranslatef(0,0.25,0);
        peldanio.draw_chess(flat, smooth);

    glPopMatrix();

}

void _escaleras::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre1

        glTranslatef(-0.5,0,0);
        agarre.draw_point();

    glPopMatrix();

    glPushMatrix(); //agarre2

        glTranslatef(0.5,0,0);
        agarre.draw_point();

    glPopMatrix();

    glPushMatrix(); //peldanio2

        glTranslatef(0,0,0);
        peldanio.draw_point();

    glPopMatrix();

    glPushMatrix(); //peldanio1

        glTranslatef(0,-0.25,0);
        peldanio.draw_point();

    glPopMatrix();

    glPushMatrix(); //peldanio3

        glTranslatef(0,0.25,0);
        peldanio.draw_point();

    glPopMatrix();

}

void _escaleras::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre1

        glTranslatef(-0.5,0,0);
        agarre.draw_line();

    glPopMatrix();

    glPushMatrix(); //agarre2

        glTranslatef(0.5,0,0);
        agarre.draw_line();

    glPopMatrix();

    glPushMatrix(); //peldanio2

        glTranslatef(0,0,0);
        peldanio.draw_line();

    glPopMatrix();

    glPushMatrix(); //peldanio1

        glTranslatef(0,-0.25,0);
        peldanio.draw_line();

    glPopMatrix();

    glPushMatrix(); //peldanio3

        glTranslatef(0,0.25,0);
        peldanio.draw_line();

    glPopMatrix();

}
