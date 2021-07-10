#include "eje.h"


_eje::_eje(){




}

void _eje::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //eje

          //glColor3f(0.5,0.5,0.5);
          glRotatef(90,1,0,0);
          glScalef(0.2,2.6,0.2);
          eje.draw_fill(flat, smooth);

    glPopMatrix();


}

void _eje::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //eje

          glRotatef(90,1,0,0);
          glScalef(0.2,2.6,0.2);
          eje.draw_chess(flat, smooth);

    glPopMatrix();

}

void _eje::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //eje

          glRotatef(90,1,0,0);
          glScalef(0.2,2.6,0.2);
          eje.draw_point();

    glPopMatrix();

}

void _eje::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //eje

          glRotatef(90,1,0,0);
          glScalef(0.2,2.6,0.2);
          eje.draw_line();

    glPopMatrix();


}
