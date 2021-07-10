#include "limpiaparabrisas.h"


_limpiaparabrisas::_limpiaparabrisas(){



}


void _limpiaparabrisas::draw_fill(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //limpiaparabrisas
        glColor3f(0,0,0);
        glRotatef(90,1,0,0);
        glScalef(0.05,0.75,0.05);
        limpiaparabrisas.draw_fill();
    glPopMatrix();


}

void _limpiaparabrisas::draw_chess(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //limpiaparabrisas
        glColor3f(0,0,0);
        glRotatef(90,1,0,0);
        glScalef(0.05,0.75,0.05);
        limpiaparabrisas.draw_chess();
    glPopMatrix();

}
void _limpiaparabrisas::draw_point(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //limpiaparabrisas
        glColor3f(0,0,0);
        glRotatef(90,1,0,0);
        glScalef(0.05,0.75,0.05);
        limpiaparabrisas.draw_point();
    glPopMatrix();

}
void _limpiaparabrisas::draw_line(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //limpiaparabrisas
        glColor3f(0,0,0);
        glRotatef(90,1,0,0);
        glScalef(0.05,0.75,0.05);
        limpiaparabrisas.draw_line();
    glPopMatrix();

}
