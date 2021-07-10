#include "cabeza.h"


_cabeza::_cabeza(){



}

void _cabeza::draw_fill(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //techo

        glTranslatef(0,1.4,0);
        techo.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //sistema_puerta_ventanilla

        glTranslatef(0,-0.1,0);
        sistema_puerta_ventanilla.draw_fill(libertad_puerta,  libertad_ventanilla, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //tapa_izq

        glTranslatef(-0.4,0,0);
        tapa_izq.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //parabrisas

        glTranslatef(0.4,0,0 );
        parabrisas.draw_fill(flat, smooth);

    glPopMatrix();



}

void _cabeza::draw_chess(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //techo

        glTranslatef(0,1.4,0);
        techo.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //sistema_puerta_ventanilla

        glTranslatef(0,-0.1,0);
        sistema_puerta_ventanilla.draw_chess(libertad_puerta,  libertad_ventanilla, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //tapa_izq

        glTranslatef(-0.4,0,0);
        tapa_izq.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //parabrisas

        glTranslatef(0.4,0,0 );
        parabrisas.draw_chess(flat, smooth);

    glPopMatrix();


}

void _cabeza::draw_point(float libertad_puerta, float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //techo

        glTranslatef(0,1.4,0);
        techo.draw_point();

    glPopMatrix();

    glPushMatrix(); //sistema_puerta_ventanilla

        glTranslatef(0,-0.1,0);
        sistema_puerta_ventanilla.draw_point(libertad_puerta,  libertad_ventanilla);

    glPopMatrix();

    glPushMatrix(); //tapa_izq

        glTranslatef(-0.4,0,0);
        tapa_izq.draw_point();

    glPopMatrix();

    glPushMatrix(); //parabrisas

        glTranslatef(0.4,0,0 );
        parabrisas.draw_point();

    glPopMatrix();

}

void _cabeza::draw_line(float libertad_puerta, float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //techo

        glTranslatef(0,1.4,0);
        techo.draw_line();

    glPopMatrix();

    glPushMatrix(); //sistema_puerta_ventanilla

        glTranslatef(0,-0.1,0);
        sistema_puerta_ventanilla.draw_line(libertad_puerta,  libertad_ventanilla);

    glPopMatrix();

    glPushMatrix(); //tapa_izq

        glTranslatef(-0.4,0,0);
        tapa_izq.draw_line();

    glPopMatrix();

    glPushMatrix(); //parabrisas

        glTranslatef(0.4,0,0 );
        parabrisas.draw_line();

    glPopMatrix();

}
