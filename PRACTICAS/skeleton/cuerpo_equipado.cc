#include "cuerpo_equipado.h"


_cuerpo_equipado::_cuerpo_equipado(){



}

void _cuerpo_equipado::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cuerpo

        //glColor3f(1,0.8,0);
        cuerpo.draw_fill( flat, smooth) ;

    glPopMatrix();

    glPushMatrix(); //sistema de escaleras

        escaleras.draw_fill(flat, smooth) ;

    glPopMatrix();

    glPushMatrix(); //luces

        glTranslatef(1.55,0.25,0);
        luces.draw_fill(flat, smooth) ;

    glPopMatrix();


}

void _cuerpo_equipado::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cuerpo

        glColor3f(1,0.8,0);
        cuerpo.draw_chess( flat, smooth);

    glPopMatrix();

    glPushMatrix(); //sistema de escaleras

        escaleras.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //luces

        glTranslatef(1.55,0.25,0);
        luces.draw_chess(flat, smooth);

    glPopMatrix();

}

void _cuerpo_equipado::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cuerpo

        cuerpo.draw_point();

    glPopMatrix();

    glPushMatrix(); //sistema de escaleras

        escaleras.draw_point();

    glPopMatrix();

    glPushMatrix(); //luces

        glTranslatef(1.55,0.25,0);
        luces.draw_point();

    glPopMatrix();

}

void _cuerpo_equipado::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //cuerpo

        cuerpo.draw_line();

    glPopMatrix();

    glPushMatrix(); //sistema de escaleras

        escaleras.draw_line();

    glPopMatrix();

    glPushMatrix(); //luces

        glTranslatef(1.55,0.25,0);
        luces.draw_line();

    glPopMatrix();

}
