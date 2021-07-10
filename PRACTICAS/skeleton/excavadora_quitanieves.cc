#include "excavadora_quitanieves.h"


_excavadora_quitanieves::_excavadora_quitanieves(){



}

void _excavadora_quitanieves::draw_fill(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //excavadora

        glTranslatef(-1,0,0);
        excavadora.draw_fill( libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_puerta,  libertad_ventanilla,  libertad_entero, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //quitanieves

        glTranslatef(3.2,-1.5,0);
        glRotatef(libertad_quitanieves, 0,0,1); //libertad_quitanieves controla la subida y bajada del quitanieves
        glTranslatef((2+libertad_estirar_quitanieves)/2,0,0); //libertad_estirar_quitanieves controla la longitud a la que se estira el quitanieves
        quitanieves.draw_fill(libertad_estirar_quitanieves, flat, smooth);

    glPopMatrix();

}

void _excavadora_quitanieves::draw_chess(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //excavadora

        glTranslatef(-1,0,0);
        excavadora.draw_chess(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_puerta,  libertad_ventanilla,  libertad_entero, flat, smooth);

    glPopMatrix();

    glPushMatrix(); //quitanieves

        glTranslatef(3.20,-1.5,0);
        glRotatef(libertad_quitanieves, 0,0,1); //libertad_quitanieves controla la subida y bajada del quitanieves
        glTranslatef((2+libertad_estirar_quitanieves)/2,0,0); //libertad_estirar_quitanieves controla la longitud a la que se estira el quitanieves
        quitanieves.draw_chess(libertad_estirar_quitanieves, flat, smooth);

    glPopMatrix();

}

void _excavadora_quitanieves::draw_point(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //excavadora

        glTranslatef(-1,0,0);
        excavadora.draw_point(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_puerta,  libertad_ventanilla,  libertad_entero);

    glPopMatrix();

    glPushMatrix(); //quitanieves

        glTranslatef(3.20,-1.5,0);
        glRotatef(libertad_quitanieves, 0,0,1); //libertad_quitanieves controla la subida y bajada del quitanieves
        glTranslatef((2+libertad_estirar_quitanieves)/2,0,0); //libertad_estirar_quitanieves controla la longitud a la que se estira el quitanieves
        quitanieves.draw_point(libertad_estirar_quitanieves);

    glPopMatrix();

}

void _excavadora_quitanieves::draw_line(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //excavadora

        glTranslatef(-1,0,0);
        excavadora.draw_line(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_puerta,  libertad_ventanilla,  libertad_entero);

    glPopMatrix();

    glPushMatrix(); //quitanieves

        glTranslatef(3.20,-1.5,0);
        glRotatef(libertad_quitanieves, 0,0,1); //libertad_quitanieves controla la subida y bajada del quitanieves
        glTranslatef((2+libertad_estirar_quitanieves)/2,0,0); //libertad_estirar_quitanieves controla la longitud a la que se estira el quitanieves
        quitanieves.draw_line(libertad_estirar_quitanieves);

    glPopMatrix();

}
