#include "mastil.h"


_mastil::_mastil(){




}

void _mastil::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //mastil

          //glColor3f(1,0.8,0);
          glScalef(0.5,4,0.5);
          mastil.draw_fill(flat, smooth);

    glPopMatrix();


}

void _mastil::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //mastil

          glScalef(0.5,4,0.5);
          mastil.draw_chess(flat, smooth);

    glPopMatrix();


}

void _mastil::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //mastil

          glColor3f(1,0.8,0);
          glScalef(0.5,4,0.5);
          mastil.draw_point();

    glPopMatrix();


}

void _mastil::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //mastil

          glScalef(0.5,4,0.5);
          mastil.draw_line();

    glPopMatrix();

}
