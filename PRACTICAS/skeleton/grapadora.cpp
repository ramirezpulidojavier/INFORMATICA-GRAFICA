#include "grapadora.h"

grapadora::grapadora()
{

}

void grapadora::draw_grapadora(int angle){
      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();//GRAPADORA

        glPushMatrix(); //BASE AZUL
          glTranslatef(0,-0.5,0);
          glRotatef(90,0,0,1);
          glScalef(1,5,1);
          base.draw_line();
        glPopMatrix();

        glColor3f(1,0,0);

        glTranslatef(-2.5,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(2,0,0);

        glPushMatrix(); //ROJIVERDE
          glPushMatrix(); //ROJO
              glTranslatef(0,0.5,0);
              glRotatef(90,0,0,1);
              glScalef(1,4,1);
              brazo.draw_line();
          glPopMatrix();
          glPushMatrix();  //VERDE
              glColor3f(0,1,0);
              glTranslatef(2.5,1,0);
              glScalef(1,2,1);
              cabeza.draw_line();
          glPopMatrix();
        glPopMatrix();

    //glPopMatrix();
    glPopMatrix();//FIN GRAPADORA
  }

