#include "excavadora.h"
#include <math.h>

_excavadora::_excavadora(){



}

void _excavadora::draw_fill(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_puerta, float libertad_ventanilla, float libertad_entero, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //coche

        glTranslatef(2.73,0,0);
        coche.draw_fill(libertad_puerta,  libertad_ventanilla,  libertad_entero, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //grua

        glTranslatef(1.43,-0.315,0);
        glRotatef(libertad_brazo_entero,0,0,1); //Libertad_brazo_entero controla el movimiento de levantar toda la grua por la union al coche
        glTranslatef(-(4*sin(libertad_codo_brazo*M_PI/180)),(4*sin((90-libertad_codo_brazo)*M_PI/180))/2,0); //Libertad_codo_brazo controla la amplitud al estirar o encoger la grua por codo
        grua.draw_fill(libertad_codo_brazo, libertad_pala, flat, smooth);

    glPopMatrix();

}

void _excavadora::draw_chess(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_puerta, float libertad_ventanilla, float libertad_entero, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //coche

        glTranslatef(2.73,0,0);
        coche.draw_chess(libertad_puerta,  libertad_ventanilla,  libertad_entero, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //grua

        glTranslatef(1.43,-0.315,0);
        glRotatef(libertad_brazo_entero,0,0,1); //Libertad_brazo_entero controla el movimiento de levantar toda la grua por la union al coche
        glTranslatef(-(4*sin(libertad_codo_brazo*M_PI/180)),(4*sin((90-libertad_codo_brazo)*M_PI/180))/2,0); //Libertad_codo_brazo controla la amplitud al estirar o encoger la grua por codo
        grua.draw_chess(libertad_codo_brazo,  libertad_pala, flat, smooth);

    glPopMatrix();

}

void _excavadora::draw_point(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_puerta, float libertad_ventanilla, float libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //coche

        glTranslatef(2.73,0,0);
        coche.draw_point(libertad_puerta,  libertad_ventanilla,  libertad_entero);

    glPopMatrix();

    glPushMatrix(); //grua

        glTranslatef(1.43,-0.315,0);
        glRotatef(libertad_brazo_entero,0,0,1); //Libertad_brazo_entero controla el movimiento de levantar toda la grua por la union al coche
        glTranslatef(-(4*sin(libertad_codo_brazo*M_PI/180)),(4*sin((90-libertad_codo_brazo)*M_PI/180))/2,0); //Libertad_codo_brazo controla la amplitud al estirar o encoger la grua por codo
        grua.draw_point(libertad_codo_brazo,  libertad_pala);

    glPopMatrix();

}

void _excavadora::draw_line(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_puerta, float libertad_ventanilla, float libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //coche

        glTranslatef(2.73,0,0);
        coche.draw_line(libertad_puerta,  libertad_ventanilla,  libertad_entero);

    glPopMatrix();

    glPushMatrix(); //grua

        glTranslatef(1.43,-0.315,0);
        glRotatef(libertad_brazo_entero,0,0,1); //Libertad_brazo_entero controla el movimiento de levantar toda la grua por la union al coche
        glTranslatef(-(4*sin(libertad_codo_brazo*M_PI/180)),(4*sin((90-libertad_codo_brazo)*M_PI/180))/2,0); //Libertad_codo_brazo controla la amplitud al estirar o encoger la grua por codo
        grua.draw_line(libertad_codo_brazo,  libertad_pala);

    glPopMatrix();

}
