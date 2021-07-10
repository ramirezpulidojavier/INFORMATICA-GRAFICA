#include "viga.h"


_viga::_viga(){




}

void _viga::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //viga

          //glColor3f(1,0.8,0);
          glScalef(0.5,4,0.5);
          viga.draw_fill(flat, smooth);

    glPopMatrix();

}

void _viga::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //viga

          glScalef(0.5,4,0.5);
          viga.draw_chess(flat, smooth);

    glPopMatrix();

}

void _viga::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //viga

          glScalef(0.5,4,0.5);
          viga.draw_point();

    glPopMatrix();

}

void _viga::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //viga

          glScalef(0.5,4,0.5);
          viga.draw_line();

    glPopMatrix();


}
