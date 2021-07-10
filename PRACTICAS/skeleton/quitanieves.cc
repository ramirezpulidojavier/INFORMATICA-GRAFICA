#include "quitanieves.h"


_quitanieves::_quitanieves(){




}

void _quitanieves::draw_fill(float libertad_estirar_quitanieves, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre

          glTranslatef(-0.5,0,0);
          agarre.draw_fill(libertad_estirar_quitanieves, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //cuerpo

          glTranslatef(((2+libertad_estirar_quitanieves)/2)-0.5,0,0); //Libertad_estirar_quitanieves controla la longitud a la que se estira el quitanieves
          cuerpo.draw_fill(flat, smooth);

    glPopMatrix();


}

void _quitanieves::draw_chess(float libertad_estirar_quitanieves, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre

          glTranslatef(-0.5,0,0);
          agarre.draw_chess(libertad_estirar_quitanieves, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //cuerpo

          glTranslatef(((2+libertad_estirar_quitanieves)/2)-0.5,0,0); //Libertad_estirar_quitanieves controla la longitud a la que se estira el quitanieves
          cuerpo.draw_chess(flat, smooth);

    glPopMatrix();

}

void _quitanieves::draw_point(float libertad_estirar_quitanieves){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre

          glTranslatef(-0.5,0,0);
          agarre.draw_point(libertad_estirar_quitanieves);

    glPopMatrix();

    glPushMatrix(); //cuerpo

          glTranslatef(((2+libertad_estirar_quitanieves)/2)-0.5,0,0); //Libertad_estirar_quitanieves controla la longitud a la que se estira el quitanieves
          cuerpo.draw_point();

    glPopMatrix();


}

void _quitanieves::draw_line(float libertad_estirar_quitanieves){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //agarre

          glTranslatef(-0.5,0,0);
          agarre.draw_line(libertad_estirar_quitanieves);

    glPopMatrix();

    glPushMatrix(); //cuerpo

          glTranslatef(((2+libertad_estirar_quitanieves)/2)-0.5,0,0); //Libertad_estirar_quitanieves controla la longitud a la que se estira el quitanieves
          cuerpo.draw_line();

    glPopMatrix();



}
