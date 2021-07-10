#include "sistema_puertasventanilla.h"


_sistema_puertasventanilla::_sistema_puertasventanilla(){




}

void _sistema_puertasventanilla::draw_fill(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta_ventanilla1

        glTranslatef(0.5,0,0.9);
        glRotatef(libertad_puerta,0,1,0); //libertad_puerta controla el angulo de apertura de la puerta
        glTranslatef(-0.5,0,0);
        puerta_ventanilla.draw_fill(libertad_ventanilla, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //puerta_ventanilla2

        glTranslatef(0.5,0,-0.9);
        glRotatef(-libertad_puerta,0,1,0);  //libertad_puerta controla el angulo de apertura de la puerta
        glTranslatef(-0.5,0,0);
        puerta_ventanilla.draw_fill(libertad_ventanilla, flat, smooth);

    glPopMatrix();



}

void _sistema_puertasventanilla::draw_chess(float libertad_puerta, float libertad_ventanilla, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta_ventanilla1

        glTranslatef(0.5,0,0.9);
        glRotatef(libertad_puerta,0,1,0);   //libertad_puerta controla el angulo de apertura de la puerta
        glTranslatef(-0.5,0,0);
        puerta_ventanilla.draw_chess(libertad_ventanilla, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //puerta_ventanilla2

        glTranslatef(0.5,0,-0.9);
        glRotatef(-libertad_puerta,0,1,0);  //libertad_puerta controla el angulo de apertura de la puerta
        glTranslatef(-0.5,0,0);
        puerta_ventanilla.draw_chess(libertad_ventanilla, flat, smooth);

    glPopMatrix();


}

void _sistema_puertasventanilla::draw_point(float libertad_puerta, float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta_ventanilla1

        glTranslatef(0.5,0,0.9);
        glRotatef(libertad_puerta,0,1,0);   //libertad_puerta controla el angulo de apertura de la puerta
        glTranslatef(-0.5,0,0);
        puerta_ventanilla.draw_point(libertad_ventanilla);

    glPopMatrix();

    glPushMatrix(); //puerta_ventanilla2

        glTranslatef(0.5,0,-0.9);
        glRotatef(-libertad_puerta,0,1,0);  //libertad_puerta controla el angulo de apertura de la puerta
        glTranslatef(-0.5,0,0);
        puerta_ventanilla.draw_point(libertad_ventanilla);

    glPopMatrix();


}

void _sistema_puertasventanilla::draw_line(float libertad_puerta, float libertad_ventanilla){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //puerta_ventanilla1

        glTranslatef(0.5,0,0.9);
        glRotatef(libertad_puerta,0,1,0);   //libertad_puerta controla el angulo de apertura de la puerta
        glTranslatef(-0.5,0,0);
        puerta_ventanilla.draw_line(libertad_ventanilla);

    glPopMatrix();

    glPushMatrix(); //puerta_ventanilla2

        glTranslatef(0.5,0,-0.9);
        glRotatef(-libertad_puerta,0,1,0);  //libertad_puerta controla el angulo de apertura de la puerta
        glTranslatef(-0.5,0,0);
        puerta_ventanilla.draw_line(libertad_ventanilla);

    glPopMatrix();

}
