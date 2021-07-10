#include "sistema_ruedas.h"


_sistema_ruedas::_sistema_ruedas(){




}

void _sistema_ruedas::draw_fill(bool libertad_entero, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Eje_rueda1

        glTranslatef(-1,0,0);
        glRotatef(libertad_entero*10,0,0,1); //libertad_entero controla el movimiento de la figura entero y la rotacion de las ruedas
        eje_rueda.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //Eje_rueda2

        glTranslatef(1,0,0);
        glRotatef(libertad_entero*10,0,0,1); //libertad_entero controla el movimiento de la figura entero y la rotacion de las ruedas
        eje_rueda.draw_fill(flat, smooth);

    glPopMatrix();



}

void _sistema_ruedas::draw_chess(bool libertad_entero, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Eje_rueda1

        glTranslatef(-1,0,0);
        glRotatef(libertad_entero*10,0,0,1); //libertad_entero controla el movimiento de la figura entero y la rotacion de las ruedas
        eje_rueda.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //Eje_rueda2

        glTranslatef(1,0,0);
        glRotatef(libertad_entero*10,0,0,1); //libertad_entero controla el movimiento de la figura entero y la rotacion de las ruedas
        eje_rueda.draw_chess(flat, smooth);

    glPopMatrix();


}

void _sistema_ruedas::draw_point(bool libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Eje_rueda1

        glTranslatef(-1,0,0);
        glRotatef(libertad_entero*10,0,0,1); //libertad_entero controla el movimiento de la figura entero y la rotacion de las ruedas
        eje_rueda.draw_point();

    glPopMatrix();

    glPushMatrix(); //Eje_rueda2

        glTranslatef(1,0,0);
        glRotatef(libertad_entero*10,0,0,1); //libertad_entero controla el movimiento de la figura entero y la rotacion de las ruedas
        eje_rueda.draw_point();

    glPopMatrix();



}

void _sistema_ruedas::draw_line(bool libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Eje_rueda1

        glTranslatef(-1,0,0);
        glRotatef(libertad_entero*10,0,0,1); //libertad_entero controla el movimiento de la figura entero y la rotacion de las ruedas
        eje_rueda.draw_line();

    glPopMatrix();

    glPushMatrix(); //Eje_rueda2

        glTranslatef(1,0,0);
        glRotatef(libertad_entero*10,0,0,1); //libertad_entero controla el movimiento de la figura entero y la rotacion de las ruedas
        eje_rueda.draw_line();

    glPopMatrix();

}
