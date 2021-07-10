#include "eje_rueda.h"


_eje_rueda::_eje_rueda(){




}

void _eje_rueda::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Eje

        eje.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //Rueda1

        glTranslatef(0,0,1.125);
        rueda.draw_fill(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //Rueda2

        glTranslatef(0,0,-1.125);
        rueda.draw_fill(flat, smooth);

    glPopMatrix();

}

void _eje_rueda::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Eje

        eje.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //Rueda1

        glTranslatef(0,0,1.125);
        rueda.draw_chess(flat, smooth);

    glPopMatrix();

    glPushMatrix(); //Rueda2

        glTranslatef(0,0,-1.125);
        rueda.draw_chess(flat, smooth);

    glPopMatrix();


}

void _eje_rueda::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Eje

        eje.draw_point();

    glPopMatrix();

    glPushMatrix(); //Rueda1

        glTranslatef(0,0,1.125);
        rueda.draw_point();

    glPopMatrix();

    glPushMatrix(); //Rueda2

        glTranslatef(0,0,-1.125);
        rueda.draw_point();

    glPopMatrix();



}

void _eje_rueda::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Eje

        eje.draw_line();

    glPopMatrix();

    glPushMatrix(); //Rueda1

        glTranslatef(0,0,1.125);
        rueda.draw_line();

    glPopMatrix();

    glPushMatrix(); //Rueda2

        glTranslatef(0,0,-1.125);
        rueda.draw_line();

    glPopMatrix();

}
