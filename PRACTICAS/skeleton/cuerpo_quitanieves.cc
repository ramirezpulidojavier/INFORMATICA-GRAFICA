#include "cuerpo_quitanieves.h"


_cuerpo_quitanieves::_cuerpo_quitanieves(){




}

void _cuerpo_quitanieves::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //base

          //glColor3f(0.25,0.25,0.25);
          glTranslatef(0,-0.4,0);
          glScalef(1,0.2,2);
          base.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //lado1

          //glColor3f(0.5,0.5,0.5);
          glTranslatef(0,0,1.1);
          glScalef(1,1,0.2);
          lado.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //lado2

          //glColor3f(0.5,0.5,0.5);
          glTranslatef(0,0,-1.1);
          glScalef(1,1,0.2);
          lado.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //pared

          //glColor3f(0.75,0.75,0.75);
          glTranslatef(-0.6,0,0);
          glScalef(0.2,1,2.4);
          pared.draw_fill(flat, smooth);

    glPopMatrix();

}

void _cuerpo_quitanieves::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //base

          glTranslatef(0,-0.4,0);
          glScalef(1,0.2,2);
          base.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //lado1

          glTranslatef(0,0,1.1);
          glScalef(1,1,0.2);
          lado.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //lado2

          glTranslatef(0,0,-1.1);
          glScalef(1,1,0.2);
          lado.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //pared

          glTranslatef(-0.6,0,0);
          glScalef(0.2,1,2.4);
          pared.draw_chess(flat, smooth);

    glPopMatrix();

}

void _cuerpo_quitanieves::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //base

          glTranslatef(0,-0.4,0);
          glScalef(1,0.2,2);
          base.draw_point();

    glPopMatrix();

    glPushMatrix(); //lado1

          glTranslatef(0,0,1.1);
          glScalef(1,1,0.2);
          lado.draw_point();

    glPopMatrix();

    glPushMatrix(); //lado2

          glTranslatef(0,0,-1.1);
          glScalef(1,1,0.2);
          lado.draw_point();

    glPopMatrix();

    glPushMatrix(); //pared

          glTranslatef(-0.6,0,0);
          glScalef(0.2,1,2.4);
          pared.draw_point();

    glPopMatrix();


}

void _cuerpo_quitanieves::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //base

          glTranslatef(0,-0.4,0);
          glScalef(1,0.2,2);
          base.draw_line();

    glPopMatrix();

    glPushMatrix(); //lado1

          glTranslatef(0,0,1.1);
          glScalef(1,1,0.2);
          lado.draw_line();

    glPopMatrix();

    glPushMatrix(); //lado2

          glTranslatef(0,0,-1.1);
          glScalef(1,1,0.2);
          lado.draw_line();

    glPopMatrix();

    glPushMatrix(); //pared

          glTranslatef(-0.6,0,0);
          glScalef(0.2,1,2.4);
          pared.draw_line();

    glPopMatrix();

}
