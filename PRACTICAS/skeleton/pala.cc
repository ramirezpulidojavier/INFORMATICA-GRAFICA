#include "pala.h"


_pala::_pala(){




}

void _pala::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //ladoizq

          //glColor3f(0.5,0.5,0.5);
          glTranslatef(-0.5,0,0);
          glScalef(0.2,1,2.2);
          lado.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //ladodrcha

          //glColor3f(0.5,0.5,0.5);
          glTranslatef(0.5,0,0);
          glScalef(0.2,1,2.2);
          lado.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //ladocerca

          //glColor3f(0.75,0.75,0.75);
          glTranslatef(0,0,1);
          glScalef(0.8,1,0.2);
          lado.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //ladolejos

          //glColor3f(0.75,0.75,0.75);
          glTranslatef(0,0,-1);
          glScalef(0.8,1,0.2);
          lado.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //base

          //glColor3f(0.25,0.25,0.25);
          glTranslatef(0,-0.4,0);
          glScalef(0.8,0.2,1.8);
          lado.draw_fill(flat, smooth);

    glPopMatrix();


}

void _pala::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //ladoizq

          glTranslatef(-0.5,0,0);
          glScalef(0.2,1,2.2);
          lado.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //ladodrcha

          glTranslatef(0.5,0,0);
          glScalef(0.2,1,2.2);
          lado.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //ladocerca

          glTranslatef(0,0,1);
          glScalef(0.8,1,0.2);
          lado.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //ladolejos

          glTranslatef(0,0,-1);
          glScalef(0.8,1,0.2);
          lado.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //base

          glTranslatef(0,-0.4,0);
          glScalef(0.8,0.2,1.8);
          lado.draw_chess(flat, smooth);

    glPopMatrix();

}

void _pala::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //ladoizq

          glTranslatef(-0.5,0,0);
          glScalef(0.2,1,2.2);
          lado.draw_point();

    glPopMatrix();

    glPushMatrix(); //ladodrcha

          glTranslatef(0.5,0,0);
          glScalef(0.2,1,2.2);
          lado.draw_point();

    glPopMatrix();

    glPushMatrix(); //ladocerca

          glTranslatef(0,0,1);
          glScalef(0.8,1,0.2);
          lado.draw_point();

    glPopMatrix();

    glPushMatrix(); //ladolejos

          glTranslatef(0,0,-1);
          glScalef(0.8,1,0.2);
          lado.draw_point();

    glPopMatrix();

    glPushMatrix(); //base

          glTranslatef(0,-0.4,0);
          glScalef(0.8,0.2,1.8);
          lado.draw_point();

    glPopMatrix();

}

void _pala::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //ladoizq

          glTranslatef(-0.5,0,0);
          glScalef(0.2,1,2.2);
          lado.draw_line();

    glPopMatrix();

    glPushMatrix(); //ladodrcha

          glTranslatef(0.5,0,0);
          glScalef(0.2,1,2.2);
          lado.draw_line();

    glPopMatrix();

    glPushMatrix(); //ladocerca

          glTranslatef(0,0,1);
          glScalef(0.8,1,0.2);
          lado.draw_line();

    glPopMatrix();

    glPushMatrix(); //ladolejos

          glTranslatef(0,0,-1);
          glScalef(0.8,1,0.2);
          lado.draw_line();

    glPopMatrix();

    glPushMatrix(); //base

          glTranslatef(0,-0.4,0);
          glScalef(0.8,0.2,1.8);
          lado.draw_line();

    glPopMatrix();

}
