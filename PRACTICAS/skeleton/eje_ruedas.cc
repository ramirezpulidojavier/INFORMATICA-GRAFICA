#include "eje_ruedas.h"


_eje_ruedas::_eje_ruedas(){

}

void _eje_ruedas::draw_eje_ruedas_points(float libertad1, float libertad2, float libertad3, float libertad4, float libertad_puerta, float libertad_ventanilla, float libertad_limpia){

    glMatrixMode(GL_MODELVIEW);

    //eje
    glPushMatrix();
        eje.draw_eje_points(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();

    //rueda1
    glPushMatrix();
        glTranslatef(0, 0, 2);
        rueda.draw_rueda_points(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();

    //rueda2
    glPushMatrix();
        glTranslatef(0, 0, -2);
        rueda.draw_rueda_points(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();
}

void _eje_ruedas::draw_eje_ruedas_lines(float libertad1, float libertad2, float libertad3, float libertad4, float libertad_puerta, float libertad_ventanilla, float libertad_limpia){

    glMatrixMode(GL_MODELVIEW);

    //eje
    glPushMatrix();
        eje.draw_eje_lines(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();

    //rueda1
    glPushMatrix();
        glTranslatef(0, 0, 2);
        rueda.draw_rueda_lines(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();

    //rueda2
    glPushMatrix();
        glTranslatef(0, 0, -2);
        rueda.draw_rueda_lines(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();
}


void _eje_ruedas::draw_eje_ruedas_fill(float libertad1, float libertad2, float libertad3, float libertad4, float libertad_puerta, float libertad_ventanilla, float libertad_limpia){

    glMatrixMode(GL_MODELVIEW);

    //eje
    glPushMatrix();
        eje.draw_eje_fill(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();

    //rueda1
    glPushMatrix();
        glTranslatef(0, 0, 2);
        rueda.draw_rueda_fill(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();

    //rueda2
    glPushMatrix();
        glTranslatef(0, 0, -2);
        rueda.draw_rueda_fill(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();
}

void _eje_ruedas::draw_eje_ruedas_chess(float libertad1, float libertad2, float libertad3, float libertad4, float libertad_puerta, float libertad_ventanilla, float libertad_limpia){

    glMatrixMode(GL_MODELVIEW);

    //eje
    glPushMatrix();
        eje.draw_eje_chess(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();

    //rueda1
    glPushMatrix();
        glTranslatef(0, 0, 2);
        rueda.draw_rueda_chess(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();

    //rueda2
    glPushMatrix();
        glTranslatef(0, 0, -2);
        rueda.draw_rueda_chess(libertad1, libertad2, libertad3, libertad4, libertad_puerta, libertad_ventanilla, libertad_limpia);
    glPopMatrix();
}


