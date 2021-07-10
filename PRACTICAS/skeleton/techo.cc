#include "techo.h"


_techo::_techo(){




}

void _techo::draw_fill(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //techo

        //glColor3f(1,1,0);
        glScalef(0.6, 0.2, 2);
        techo.draw_fill(flat, smooth);

    glPopMatrix();


}

void _techo::draw_chess(bool flat, bool smooth){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //techo

        glScalef(0.6, 0.2, 2);
        techo.draw_chess(flat, smooth);

    glPopMatrix();

}

void _techo::draw_point(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //techo

        glScalef(0.6, 0.2, 2);
        techo.draw_point();

    glPopMatrix();

}

void _techo::draw_line(){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //techo

        glScalef(0.6, 0.2, 2);
        techo.draw_line();

    glPopMatrix();
}
