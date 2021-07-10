#include "agarre_quitanieves.h"


_agarre_quitanieves::_agarre_quitanieves(){



}

void _agarre_quitanieves::draw_fill(float libertad_estirar_quitanieves, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre1

          glTranslatef(0,0,0.5);
          glRotatef(90,0,0,1);
          glScalef(0.1,1+libertad_estirar_quitanieves,0.1); //Libertad_estirar_quitanieves controla poder estirar el quitanieves
          agarre.draw_fill(flat, smooth);                   //Pintamos

    glPopMatrix();

    glPushMatrix(); //agarre2

          glTranslatef(0,0,-0.5);
          glRotatef(90,0,0,1);
          glScalef(0.1,1+libertad_estirar_quitanieves,0.1); //Libertad_estirar_quitanieves controla poder estirar el quitanieves
          agarre.draw_fill(flat, smooth);                   //Pintamos

    glPopMatrix();


}

void _agarre_quitanieves::draw_chess(float libertad_estirar_quitanieves, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre1

          glTranslatef(0,0,0.5);
          glRotatef(90,0,0,1);
          glScalef(0.1,1+libertad_estirar_quitanieves,0.1); //Libertad_estirar_quitanieves controla poder estirar el quitanieves
          agarre.draw_chess(flat, smooth);                  //Pintamos

    glPopMatrix();

    glPushMatrix(); //agarre2

          glTranslatef(0,0,-0.5);
          glRotatef(90,0,0,1);
          glScalef(0.1,1+libertad_estirar_quitanieves,0.1); //Libertad_estirar_quitanieves controla poder estirar el quitanieves
          agarre.draw_chess(flat, smooth);                  //Pintamos

    glPopMatrix();

}

void _agarre_quitanieves::draw_point(float libertad_estirar_quitanieves){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre1

          glTranslatef(0,0,0.5);
          glRotatef(90,0,0,1);
          glScalef(0.1,1+libertad_estirar_quitanieves,0.1); //Libertad_estirar_quitanieves controla poder estirar el quitanieves
          agarre.draw_point();                              //Pintamos

    glPopMatrix();

    glPushMatrix(); //agarre2

          glTranslatef(0,0,-0.5);
          glRotatef(90,0,0,1);
          glScalef(0.1,1+libertad_estirar_quitanieves,0.1); //Libertad_estirar_quitanieves controla poder estirar el quitanieves
          agarre.draw_point();                              //Pintamos

    glPopMatrix();

}

void _agarre_quitanieves::draw_line(float libertad_estirar_quitanieves){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre1

          glTranslatef(0,0,0.5);
          glRotatef(90,0,0,1);
          glScalef(0.1,1+libertad_estirar_quitanieves,0.1); //Libertad_estirar_quitanieves controla poder estirar el quitanieves
          agarre.draw_line();                               //Pintamos

    glPopMatrix();

    glPushMatrix(); //agarre2

          glTranslatef(0,0,-0.5);
          glRotatef(90,0,0,1);
          glScalef(0.1,1+libertad_estirar_quitanieves,0.1); //Libertad_estirar_quitanieves controla poder estirar el quitanieves
          agarre.draw_line();                               //Pintamos

    glPopMatrix();

}
