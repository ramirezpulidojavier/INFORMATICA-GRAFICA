/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "matriz_ply.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_matriz_ply::_matriz_ply()
{
    vector<_ply> auxiliar; //Vector que contendra 4 figuras ply y sera insertado en la matriz 4 veces (haciendo una 4x4)

    interno.cargar_ply("./ply_models/beethoven.ply"); //Cargamos una figura
    auxiliar.push_back(interno);                      //La metemos en el vector auxiliar
    interno.cargar_ply("./ply_models/ant.ply");       //Cargamos otra figura para tener mas un objeto diferente
    auxiliar.push_back(interno);                      //La metemos en la fila
    interno.cargar_ply("./ply_models/cow.ply");       //Cargamos otra figura para tener mas un objeto diferente
    auxiliar.push_back(interno);                      //La metemos en la fila
    interno.cargar_ply("./ply_models/big_dodge.ply"); //Cargamos otra figura para tener mas un objeto diferente
    auxiliar.push_back(interno);                      //La metemos en la fila


    //Metemos la fila 4 veces. Con esto queda creada la matriz con los 16 objetos dentro
    for(int i = 0; i < 4 ; i++){

        matriz.push_back(auxiliar);

    }

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _matriz_ply::draw_matriz_fill(bool flat, bool smooth)
{
    //Contador para saber por que objeto vamos pintando de la matriz
    int contador = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            glPushMatrix();
                //Se mueve cada figura para que no choquen entre ellas
                glTranslatef(i*20.0, 0, -j*20.0);
                //Se pintan todas en azul excepto si el objeto que va a pintar es el seleccionado con el pick, que se pintara de color amarillo
                if(contador==Selected_triangle){ glColor3f(1,1,0);} else {glColor3f(0,0,1);}
                    matriz[i][j].draw_selected_objeto(flat, smooth);

            glPopMatrix();
            contador++;
        }
    }

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _matriz_ply::draw_matriz_chess(bool flat, bool smooth)
{

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            glPushMatrix();
                glTranslatef(i*20.0, 0, -j*20.0);
                matriz[i][j].draw_chess(flat, smooth);

            glPopMatrix();
        }
    }

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _matriz_ply::draw_matriz_line()
{

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            glPushMatrix();
                glTranslatef(i*20.0, 0, -j*20.0); //Se deja un espacio
                matriz[i][j].draw_line();         //Se pintan con lineas

            glPopMatrix();
        }
    }

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _matriz_ply::draw_matriz_points()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            glPushMatrix();
                glTranslatef(i*20.0, 0, -j*20.0);
                matriz[i][j].draw_point();

            glPopMatrix();

        }
    }

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _matriz_ply::draw_selection_matriz()
{
    int contador=0;
    for(int i = 0 ; i < 4; i++){
      for(int j = 0 ; j < 4 ; j++){
          glPushMatrix();
              glTranslatef(i*20.0, 0, -j*20.0);
              //Se llama por cada a objeto a la funcion que los pinta en los buffers invisibles cada uno de un color
              matriz[i][j].draw_selection_nuevo(contador);
          glPopMatrix();
          contador++;
      }
    }

}



