#include "tapa_izq.h"


_tapa_izq::_tapa_izq(){



}

void _tapa_izq::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //tapa_izquierda

        //glColor3f(1,1,0);
        glScalef(0.2,3,2);
        tapa_izq.draw_fill(flat, smooth);

    glPopMatrix();


}

void _tapa_izq::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //tapa_izquierda

        glScalef(0.2,3,2);
        tapa_izq.draw_chess(flat, smooth);

    glPopMatrix();

}

void _tapa_izq::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //tapa_izquierda

        glScalef(0.2,3,2);
        tapa_izq.draw_point();

    glPopMatrix();

}

void _tapa_izq::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //tapa_izquierda

        glScalef(0.2,3,2);
        tapa_izq.draw_line();

    glPopMatrix();

}
