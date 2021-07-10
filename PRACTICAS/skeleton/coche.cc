#include "coche.h"


_coche::_coche(){



}

void _coche::draw_fill(float libertad_puerta, float libertad_ventanilla, float libertad_entero, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //sistema de ruedas

        glTranslatef(0,-2,0);
        sistema_ruedas.draw_fill(libertad_entero, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //chasis

        glTranslatef(0,0.5,0);
        chasis.draw_fill(libertad_puerta, libertad_ventanilla, flat, smooth);

    glPopMatrix();


}

void _coche::draw_chess(float libertad_puerta, float libertad_ventanilla, float libertad_entero, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //sistema de ruedas

        glTranslatef(0,-2,0);
        sistema_ruedas.draw_chess(libertad_entero, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //chasis

        glTranslatef(0,0.5,0);
        chasis.draw_chess(libertad_puerta,  libertad_ventanilla, flat, smooth);

    glPopMatrix();


}

void _coche::draw_point(float libertad_puerta, float libertad_ventanilla, float libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //sistema de ruedas

        glTranslatef(0,-2,0);
        sistema_ruedas.draw_point(libertad_entero);

    glPopMatrix();

    glPushMatrix(); //chasis

        glTranslatef(0,0.5,0);
        chasis.draw_point(libertad_puerta,  libertad_ventanilla);

    glPopMatrix();

}

void _coche::draw_line(float libertad_puerta, float libertad_ventanilla, float libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //sistema de ruedas

        glTranslatef(0,-2,0);
        sistema_ruedas.draw_line(libertad_entero);

    glPopMatrix();

    glPushMatrix(); //chasis

        glTranslatef(0,0.5,0);
        chasis.draw_line(libertad_puerta,  libertad_ventanilla);

    glPopMatrix();

}
