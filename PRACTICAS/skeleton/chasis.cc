#include "chasis.h"


_chasis::_chasis(){



}

void _chasis::draw_fill(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cabeza

        glTranslatef(0,0.75,0);
        cabeza.draw_fill(libertad_puerta, libertad_ventanilla, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //cuerpo

        glTranslatef(0,-1.5,0);
        cuerpo.draw_fill(flat, smooth);

    glPopMatrix();


}

void _chasis::draw_chess(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cabeza

        glTranslatef(0,0.75,0);
        cabeza.draw_chess(libertad_puerta,  libertad_ventanilla, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //cuerpo

        glTranslatef(0,-1.5,0);
        cuerpo.draw_chess(flat, smooth);

    glPopMatrix();

}

void _chasis::draw_point(float libertad_puerta, float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cabeza

        glTranslatef(0,0.75,0);
        cabeza.draw_point(libertad_puerta,  libertad_ventanilla);

    glPopMatrix();

    glPushMatrix(); //cuerpo

        glTranslatef(0,-1.5,0);
        cuerpo.draw_point();

    glPopMatrix();

}

void _chasis::draw_line(float libertad_puerta, float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cabeza

        glTranslatef(0,0.75,0);
        cabeza.draw_line(libertad_puerta, libertad_ventanilla);

    glPopMatrix();

    glPushMatrix(); //cuerpo

        glTranslatef(0,-1.5,0);
        cuerpo.draw_line();

    glPopMatrix();

}
