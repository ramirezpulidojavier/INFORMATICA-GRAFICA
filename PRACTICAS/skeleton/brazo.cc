#include "brazo.h"
#include <math.h>

_brazo::_brazo(){


}

void _brazo::draw_fill(float libertad_codo_brazo, float libertad_pala, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //viga

         glTranslatef(-(((4*sin(libertad_codo_brazo*M_PI/180))/2)-0.1),0,0);    //libertad_codo_brazo controla la amplitud de apertura de la grua trasera
         glRotatef(-libertad_codo_brazo,0,0,1);
         viga.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //pala

         glTranslatef(-(4*sin(libertad_codo_brazo*M_PI/180)),-((4*sin((90-libertad_codo_brazo)*M_PI/180))/2),0); //libertad_codo_brazo controla la amplitud de apertura de la grua trasera
         glRotatef(libertad_pala,0,0,1);   //Libertad_pala controla la rotacion de la pala (vaciar y llenar)
         glTranslatef(0.5,-0.5,0);
         pala.draw_fill(flat, smooth);

    glPopMatrix();

}

void _brazo::draw_chess(float libertad_codo_brazo, float libertad_pala, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //viga

         glTranslatef(-(((4*sin(libertad_codo_brazo*M_PI/180))/2)-0.1),0,0);    //libertad_codo_brazo controla la amplitud de apertura de la grua trasera
         glRotatef(-libertad_codo_brazo,0,0,1);
         viga.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //pala

         glTranslatef(-(4*sin(libertad_codo_brazo*M_PI/180)),-((4*sin((90-libertad_codo_brazo)*M_PI/180))/2),0); //libertad_codo_brazo controla la amplitud de apertura de la grua trasera
         glRotatef(libertad_pala,0,0,1);   //Libertad_pala controla la rotacion de la pala (vaciar y llenar)
         glTranslatef(0.5,-0.5,0);
         pala.draw_chess(flat, smooth);

    glPopMatrix();


}

void _brazo::draw_point(float libertad_codo_brazo, float libertad_pala){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //viga

         glTranslatef(-(((4*sin(libertad_codo_brazo*M_PI/180))/2)-0.1),0,0);    //libertad_codo_brazo controla la amplitud de apertura de la grua trasera
         glRotatef(-libertad_codo_brazo,0,0,1);
         viga.draw_point();

    glPopMatrix();

    glPushMatrix(); //pala

         glTranslatef(-(4*sin(libertad_codo_brazo*M_PI/180)),-((4*sin((90-libertad_codo_brazo)*M_PI/180))/2),0); //libertad_codo_brazo controla la amplitud de apertura de la grua trasera
         glRotatef(libertad_pala,0,0,1);   //Libertad_pala controla la rotacion de la pala (vaciar y llenar)
         glTranslatef(0.5,-0.5,0);
         pala.draw_point();

    glPopMatrix();



}

void _brazo::draw_line(float libertad_codo_brazo, float libertad_pala){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //viga

         glTranslatef(-(((4*sin(libertad_codo_brazo*M_PI/180))/2)-0.1),0,0);    //libertad_codo_brazo controla la amplitud de apertura de la grua trasera
         glRotatef(-libertad_codo_brazo,0,0,1);
         viga.draw_line();

    glPopMatrix();

    glPushMatrix(); //pala

         glTranslatef(-(4*sin(libertad_codo_brazo*M_PI/180)),-((4*sin((90-libertad_codo_brazo)*M_PI/180))/2),0); //libertad_codo_brazo controla la amplitud de apertura de la grua trasera
         glRotatef(libertad_pala,0,0,1);   //Libertad_pala controla la rotacion de la pala (vaciar y llenar)
         glTranslatef(0.5,-0.5,0);
         pala.draw_line();

    glPopMatrix();


}
