#include "hierarchical.h"


_hierarchical::_hierarchical(){




}

void _hierarchical::draw_fill(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //excavadora_quitanieves

        glTranslatef(libertad_entero,0,0); //Libertad_entero controla el movimiento entero del objeto y la rotacion de las ruedas para darle realismo
        excavadora_quitanieves.draw_fill(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_quitanieves,  libertad_puerta,  libertad_ventanilla,  libertad_entero, libertad_estirar_quitanieves, flat, smooth);

    glPopMatrix();


}

void _hierarchical::draw_chess(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves, bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //excavadora_quitanieves

        glTranslatef(libertad_entero,0,0); //Libertad_entero controla el movimiento entero del objeto y la rotacion de las ruedas para darle realismo
        excavadora_quitanieves.draw_chess(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_quitanieves,  libertad_puerta,  libertad_ventanilla,  libertad_entero, libertad_estirar_quitanieves, flat, smooth);

    glPopMatrix();

}

void _hierarchical::draw_point(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //excavadora_quitanieves

        glTranslatef(libertad_entero,0,0); //Libertad_entero controla el movimiento entero del objeto y la rotacion de las ruedas para darle realismo
        excavadora_quitanieves.draw_point(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_quitanieves,  libertad_puerta,  libertad_ventanilla,  libertad_entero, libertad_estirar_quitanieves);

    glPopMatrix();
}

void _hierarchical::draw_line(float libertad_codo_brazo, float libertad_pala, float libertad_brazo_entero, float libertad_quitanieves, float libertad_puerta, float libertad_ventanilla, float libertad_entero, float libertad_estirar_quitanieves){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //excavadora_quitanieves

        glTranslatef(libertad_entero,0,0); //Libertad_entero controla el movimiento entero del objeto y la rotacion de las ruedas para darle realismo
        excavadora_quitanieves.draw_line(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_quitanieves,  libertad_puerta,  libertad_ventanilla,  libertad_entero, libertad_estirar_quitanieves);

    glPopMatrix();

}


