#include "cabeza_rellena.h"


_cabeza_rellena::_cabeza_rellena(){




}

void _cabeza_rellena::draw_fill(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Cabeza

        cabeza.draw_fill(libertad_puerta, libertad_ventanilla, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //Asiento

        glTranslatef(-0.075,-0.14,0);
        asiento.draw_fill(flat, smooth);

    glPopMatrix();

}

void _cabeza_rellena::draw_chess(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Cabeza

        cabeza.draw_chess(libertad_puerta,  libertad_ventanilla, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //Asiento

        glTranslatef(-0.075,-0.14,0);
        asiento.draw_chess(flat, smooth);

    glPopMatrix();

}

void _cabeza_rellena::draw_point(float libertad_puerta, float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Cabeza

        cabeza.draw_point(libertad_puerta,  libertad_ventanilla);

    glPopMatrix();

    glPushMatrix(); //Asiento

        glTranslatef(-0.075,-0.14,0);
        asiento.draw_point();

    glPopMatrix();

}

void _cabeza_rellena::draw_line(float libertad_puerta, float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Cabeza

        cabeza.draw_line(libertad_puerta,  libertad_ventanilla);

    glPopMatrix();

    glPushMatrix(); //Asiento

        glTranslatef(-0.075,-0.14,0);
        asiento.draw_line();

    glPopMatrix();

}
