#include "grua.h"
#include <math.h>

_grua::_grua(){



}

void _grua::draw_fill(float libertad_codo_brazo, float libertad_pala, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //brazo

        brazo.draw_fill(libertad_codo_brazo,  libertad_pala, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //mastil

        glTranslatef(((4*sin(libertad_codo_brazo*M_PI/180))/2)+0.1,0,0); //libertad_codo_brazo controla la amplitud a la que se abre el codo de la excavadora
        glRotatef(libertad_codo_brazo,0,0,1); //Libertad_codo_brazo controla la amplitud a la que se abre el codo de la excavadora
        mastil.draw_fill(flat, smooth);

    glPopMatrix();


}

void _grua::draw_chess(float libertad_codo_brazo, float libertad_pala, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //brazo

        brazo.draw_chess(libertad_codo_brazo,  libertad_pala, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //mastil

        glTranslatef(((4*sin(libertad_codo_brazo*M_PI/180))/2)+0.1,0,0); //libertad_codo_brazo controla la amplitud a la que se abre el codo de la excavadora
        glRotatef(libertad_codo_brazo,0,0,1); //Libertad_codo_brazo controla la amplitud a la que se abre el codo de la excavadora
        mastil.draw_chess(flat, smooth);

    glPopMatrix();

}

void _grua::draw_point(float libertad_codo_brazo, float libertad_pala){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //brazo

        brazo.draw_point(libertad_codo_brazo,  libertad_pala);

    glPopMatrix();

    glPushMatrix(); //mastil

        glTranslatef(((4*sin(libertad_codo_brazo*M_PI/180))/2)+0.1,0,0); //libertad_codo_brazo controla la amplitud a la que se abre el codo de la excavadora
        glRotatef(libertad_codo_brazo,0,0,1); //Libertad_codo_brazo controla la amplitud a la que se abre el codo de la excavadora
        mastil.draw_point();

    glPopMatrix();
}

void _grua::draw_line(float libertad_codo_brazo, float libertad_pala){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //brazo

        brazo.draw_line(libertad_codo_brazo,  libertad_pala);

    glPopMatrix();

    glPushMatrix(); //mastil

        glTranslatef(((4*sin(libertad_codo_brazo*M_PI/180))/2)+0.1,0,0); //libertad_codo_brazo controla la amplitud a la que se abre el codo de la excavadora
        glRotatef(libertad_codo_brazo,0,0,1); //Libertad_codo_brazo controla la amplitud a la que se abre el codo de la excavadora
        mastil.draw_line();

    glPopMatrix();

}
