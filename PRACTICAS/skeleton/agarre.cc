#include "agarre.h"


_agarre::_agarre(){



}

void _agarre::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Agarre

        //glColor3f(0,0,0);               //Para pintarlo en negro (en la P5 se anula porque se pinta todo en azul para el pick)
        glScalef(0.05,1.5,0.05);        //Para asignar el tamanio
        agarre.draw_fill(flat, smooth); //Pintamos

    glPopMatrix();


}

void _agarre::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Agarre

        glScalef(0.05,1.5,0.05);        //Para asignar el tamanio
        agarre.draw_chess(flat, smooth); //Pintamos

    glPopMatrix();

}

void _agarre::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Agarre

        glScalef(0.05,1.5,0.05);        //Para asignar el tamanio
        agarre.draw_point();            //Pintamos

    glPopMatrix();

}

void _agarre::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Agarre

        glScalef(0.05,1.5,0.05);        //Para asignar el tamanio
        agarre.draw_line();             //Pintamos

    glPopMatrix();

}
