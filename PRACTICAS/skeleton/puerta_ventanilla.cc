#include "puerta_ventanilla.h"


_puerta_ventanilla::_puerta_ventanilla(){



}

void _puerta_ventanilla::draw_fill(float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta

        //glColor3f(1,1,0);
        glTranslatef(0,-0.65,0);
        puerta.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //ventanilla

        //glColor3f(0,0,1);
        glTranslatef(0.00005,0.75-libertad_ventanilla,0); //Libertad_ventanilla controla la subida y bajada de la ventanilla
        ventanilla.draw_fill(flat, smooth);

    glPopMatrix();


}

void _puerta_ventanilla::draw_chess(float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta

        glTranslatef(0,-0.65,0);
        puerta.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //ventanilla

        glTranslatef(0.00005,0.75-libertad_ventanilla,0); //Libertad_ventanilla controla la subida y bajada de la ventanilla
        ventanilla.draw_chess(flat, smooth);

    glPopMatrix();

}

void _puerta_ventanilla::draw_point(float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta

        glTranslatef(0,-0.65,0);
        puerta.draw_point();

    glPopMatrix();

    glPushMatrix(); //ventanilla

        glTranslatef(0.00005,0.75-libertad_ventanilla,0); //Libertad_ventanilla controla la subida y bajada de la ventanilla
        ventanilla.draw_point();

    glPopMatrix();

}

void _puerta_ventanilla::draw_line(float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta

        glTranslatef(0,-0.65,0);
        puerta.draw_line();

    glPopMatrix();

    glPushMatrix(); //ventanilla

        glTranslatef(0.00005,0.75-libertad_ventanilla,0); //Libertad_ventanilla controla la subida y bajada de la ventanilla
        ventanilla.draw_line();

    glPopMatrix();

}
