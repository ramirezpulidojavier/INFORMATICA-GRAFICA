/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include <math.h>
#include "window.h"
#include <iostream>

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{

  //Establece el tamanio minimo que puede tener la ventana principal
  setMinimumSize(300, 300);
  //Para que acepte entradas del teclado y del raton
  setFocusPolicy(Qt::StrongFocus);

  //Cargamos los plys aqui para evitar hacerlo varias veces por tema de eficiencia
  Ply.cargar_ply("./ply_models/beethoven.ply");
  Ply_menu_1.cargar_ply("./ply_models/beethoven.ply");
  Ply_menu_2.cargar_ply("./ply_models/ant.ply");
  Ply_menu_3.cargar_ply("./ply_models/big_dodge.ply");
  Ply_menu_4.cargar_ply("./ply_models/sandal.ply");
  Ply_menu_5.cargar_ply("./ply_models/cow.ply");
  PlyPerfil.cargar_ply_perfil("./ply_models/cuenco.ply");

}

/*****************************************************************************//**
 * FUNCIONES PARA LOS SLOTS
 *****************************************************************************/

//Para que funcione el checkbox de los puntos
void _gl_widget::ply_cb_slot(int State){
    if(State)
        Object = OBJECT_PLY;
    else
        Object = OBJECT_VACIO;
    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::matriz_cb_slot(int State){
    if(State)
        Object = OBJECT_MATRIZ;
    else
        Object = OBJECT_VACIO;
    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::tablero_cb_slot(int State){
    if(State)
        Object = OBJECT_TABLERO;
    else
        Object = OBJECT_VACIO;
    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::solid_cb_slot(int State){
    if(State)
        Draw_solid = true;
    else
        Draw_solid = false;

    if(!Draw_solid){

        Draw_textura=false;
        flat = false;
        smooth=false;
        Draw_chess=false;
        Draw_fill=false;

    }

    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::textura_cb_slot(int State){

    if(Draw_solid){

        flat = false;
        smooth=false;
        Draw_chess=false;
        Draw_fill=false;

        if(State)
                Draw_textura=true;

        else

            Draw_textura=false;


    }

    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::flat_cb_slot(int State){

    if(Draw_solid){

        if(State){
            flat = true;
            smooth = false;
        }else
            flat = false;

        if(flat)luz_activada=true;
        else luz_activada=false;
    }
    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::smooth_cb_slot(int State){
    if(Draw_solid){

        if(State){
            smooth = true;
            flat = false;
        }else
            smooth = false;

        if(smooth)luz_activada=true;
        else luz_activada=false;
    }
    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::flat_textura_cb_slot(int State){

    if(Draw_solid){

        if(State){
            flat_textura = true;
        }else
            flat_textura = false;

        flat=false;
        smooth=false;
        Draw_chess=false;
        Draw_fill=false;
        Draw_textura=true;

        if(flat_textura)luz_activada=true;
        else{Draw_textura=false;luz_activada=false;}
    }


    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::smooth_textura_cb_slot(int State){

    if(Draw_solid){

        if(State){
            smooth_textura = true;
        }else
            smooth_textura = false;

        flat=false;
        smooth=false;
        Draw_chess=false;
        Draw_fill=false;
        Draw_textura=true;

        if(smooth_textura)luz_activada=true;
        else{ Draw_textura=false;luz_activada=false;}
    }

    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::luz_blanca_cb_slot(int State){
    if(State )
        interruptor0=true;
    else
        interruptor0=false;


    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::luz_magenta_cb_slot(int State){
    if(State)
        interruptor1=true;
    else
        interruptor1=false;

    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::frustrum_cb_slot(int State){
    if(State)
        Projection_type=PERSPECTIVE_PROJECTION;
    else
        Projection_type=PARALLEL_PROJECTION;

    update(); //para que se dibuje cada vez y se actualice

}

//Para que funcione el checkbox de los puntos
void _gl_widget::orthogonal_cb_slot(int State){
    if(State)
        Projection_type=PARALLEL_PROJECTION;
    else
        Projection_type=PERSPECTIVE_PROJECTION;

    update(); //para que se dibuje cada vez y se actualice

}

void _gl_widget::materiales(){
    contador_color++;
    update();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de los puntos
void _gl_widget::puntos_cb_slot(int State){
    if(State)Draw_point=true;
    else Draw_point=false;
    update(); //para que se dibuje cada vez y se actualice

}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de las lineas
void _gl_widget::lineas_cb_slot(int State){
    if(State)Draw_line=true;
    else Draw_line=false;
    update();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de fill
void _gl_widget::fill_cb_slot(int State){

    if(Draw_solid){

        Draw_chess=false;

        if(State)
            Draw_fill=true;

        else
            Draw_fill=false;

    }
    update();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de chess
void _gl_widget::chess_cb_slot(int State){
    if(Draw_solid){

        Draw_fill=false;

        if(State)
            Draw_chess=true;

        else
            Draw_chess=false;

    }
    update();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de tetraedro
void _gl_widget::tetra_cb_slot(int State){
    if(State)
        Object = OBJECT_TETRAHEDRON;
    else
        Object = OBJECT_VACIO;
    update();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de cubo
void _gl_widget::cubo_cb_slot(int State){
    if(State)
        Object=OBJECT_CUBE;
    else
        Object = OBJECT_VACIO;

    update();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de cono
void _gl_widget::cono_cb_slot(int State){
    if(State)
        Object=OBJECT_CONO;
    else
        Object = OBJECT_VACIO;

    update();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de cilindro
void _gl_widget::cilindro_cb_slot(int State){
    if(State)
        Object=OBJECT_CILINDRO;
    else
        Object = OBJECT_VACIO;

    update();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

//Para que funcione el checkbox de esfera
void _gl_widget::esfera_cb_slot(int State){
    if(State)
        Object=OBJECT_ESFERA;
    else
        Object = OBJECT_VACIO;

    update();
}

/*****************************************************************************//**
 * Para que funcione el checkbox de hierarchical
 *****************************************************************************/

void _gl_widget::hierarchical_cb_slot(int State){
    if(State)
        Object=OBJECT_HIERARCHICAL;
    else
        Object = OBJECT_VACIO;

    update();
}

/*****************************************************************************//**
 * Para que funcione el checkbox de ply dado un perfil
 *****************************************************************************/

void _gl_widget::ply_perfil_cb_slot(int State){
    if(State)
        Object=OBJECT_PLY_PERFIL;
    else
        Object = OBJECT_VACIO;

    update();
}

/*****************************************************************************//**
 * LISTADO DE PLYS QUE SE ABREN DESDE LA INTERFAZ
 *****************************************************************************/

void _gl_widget::leerCombobox(int State){

    //Segun el elemento de la lista que elijamos, indica que es un objeto u otro
    switch (State) {
        case 0: Object=OBJECT_VACIO;     update(); break;
        case 1: Object=OBJECT_PLY_MENU1; update(); break;
        case 2: Object=OBJECT_PLY_MENU2; update(); break;
        case 3: Object=OBJECT_PLY_MENU3; update(); break;
        case 4: Object=OBJECT_PLY_MENU4; update(); break;
        case 5: Object=OBJECT_PLY_MENU5; update(); break;
    }

}

/*****************************************************************************//**
 * FUNCION ACTIVADA POR EL QTIMER ENCARGADA DE LLAMAR A TODAS LAS ANIMACIONES DE LA FIGURA
 * TODAS LAS ANIMACIONES OCURREN UNA DETRAS DE OTRA, EXCEPTO LA LUZ QUE ES CONSTANTE
 *****************************************************************************/

void _gl_widget::animacion(){

    animacion_puerta();             //Abre y cierra las puertas (con las ventanillas)
    animacion_ventanilla();         //Sube y baja las ventanillas
    animacion_quitanieves();        //Sube y baja el quitanieves
    animacion_estira_quitanieves(); //Estira y recoge el quitanieves
    animacion_codo();               //Estira y recoge la grua por la articulacion del codo
    animacion_brazo();              //Sube y baja la grua completa por su union con el coche
    animacion_pala();               //Vacia y llena la pala
    animacion_entero();             //Mueve la figura completa hacia delante y atras (con el giro de las ruedas correspondiente)
    animacion_luz();                //Rota la luz alrededor de la figura

}

/*****************************************************************************//**
 * FUNCION QUE ABRE Y CIERRA LAS PUERTAS
 *****************************************************************************/

void _gl_widget::animacion_puerta(){

    //Se abre hasta 70 grados para simular el movimiento real de una puerta
    if(libertad_puerta+velocidad_puerta < 70.0 && abriendo_puerta && !puerta_fin)
        libertad_puerta+=velocidad_puerta;

    //Cuando llega al tope indica que ya no esta abriendo la puerta, que es la condicion para que empiece a cerrarla
    else if(libertad_puerta+velocidad_puerta >= 70.0 && abriendo_puerta)
        abriendo_puerta=false;

    //Si ya no esta abiendo la puerta, la cierra hasta volver a la posicion original
    else if(libertad_puerta-velocidad_puerta >= 0.0 && !abriendo_puerta)
        libertad_puerta-=velocidad_puerta;

    //Cuando llega a la posicion original indica que este movimiento ha terminado y comienza el siguiente (ventanillas)
    else if(libertad_puerta-velocidad_puerta < 0.0 && !abriendo_puerta && !puerta_fin){
        libertad_puerta=0;
        puerta_fin = true;
    }

    update();
}

/*****************************************************************************//**
 * FUNCION QUE ACTIVA LA BAJADA Y SUBIDA DE VENTANILLAS (AL TERMINAR EL MOVIMIENTO DE PUERTAS)
 *****************************************************************************/

void _gl_widget::animacion_ventanilla(){

    //1.3 Va en relacion al tamanio de las puertas y ventanillas para que baje simulando una ventanilla real sin asomar por debajo
    if((libertad_ventanilla+velocidad_ventanilla) <= 1.3 && bajando_ventanilla && puerta_fin)
        libertad_ventanilla+=velocidad_ventanilla;

    //Si llega al limite marca que ya no esta bajando las ventanillas, condicion necesaria para empezar a subirlas
    else if((libertad_ventanilla+velocidad_ventanilla) > 1.3 && bajando_ventanilla && puerta_fin )
        bajando_ventanilla=false;

    //Si ya no esta bajando la ventanilla, sube hasta llegar a la posicion original
    else if(libertad_ventanilla-velocidad_ventanilla >= 0.0 && !bajando_ventanilla && puerta_fin)
        libertad_ventanilla-=velocidad_ventanilla;

    //Cuando llega a la posicion original indica que este movimiento ha termiando
    else if(libertad_ventanilla-velocidad_ventanilla < 0 && !bajando_ventanilla && puerta_fin && !ventanilla_fin){
        bajando_ventanilla=true;
        ventanilla_fin = true;

    //Si este movimiento ha termiando y estoy en la posicion original indico el comienzo del movimiento del quitanieves
    }else if (ventanilla_fin && libertad_ventanilla+velocidad_ventanilla <= 1.3 && !subiendo_quitanieves && !bajando_quitanieves)
        subiendo_quitanieves = true ;


    update();
}

/*****************************************************************************//**
 * FUNCION QUE SUBE Y BAJA EL QUITANIEVES CUANDO EL MOVIMIENTO DE LAS VENTANILLAS TERMINA
 *****************************************************************************/

void _gl_widget::animacion_quitanieves(){

    //50 es el angulo maximo que puede subir sin atravesar el morro de la figura
    if(libertad_quitanieves+velocidad_quitanieves <= 50 && subiendo_quitanieves && !bajando_quitanieves && ventanilla_fin)
        libertad_quitanieves+=velocidad_quitanieves;

    //Cuando llega a la posicion maxima indica que ya no esta subiendo el quitanieves sino que lo esta bajando
    else if(libertad_quitanieves+velocidad_quitanieves > 50 && subiendo_quitanieves && !bajando_quitanieves && ventanilla_fin){
        subiendo_quitanieves=false;
        bajando_quitanieves = true;

    //Si esta bajando el quitanieves lo devuelve a la posicion original
    }else if(libertad_quitanieves-velocidad_quitanieves >= 0 && !subiendo_quitanieves && bajando_quitanieves && ventanilla_fin)
        libertad_quitanieves-=velocidad_quitanieves;

    //Si vuelve a la posicion original marca que el movimiento del quitanieves ha terminado
    else if(libertad_quitanieves-velocidad_quitanieves < 0 && !subiendo_quitanieves && bajando_quitanieves && ventanilla_fin && !quitanieves_fin)
        quitanieves_fin=true;

    //Si este movimiento ha terminado y estoy en la posicion original pongo a verdadera la condicion que inicia el siguiente movimiento
    else if (quitanieves_fin && libertad_quitanieves+velocidad_quitanieves <= 50 && !abriendo_codo && !cerrando_codo && !codo_fin && !bajando_brazo && !subiendo_brazo  && !brazo_fin && !vaciando_pala && !llenando_pala && !pala_fin && !estirando_agarre_quitanieves && !encogiendo_agarre_quitanieves && !agarre_quitanieves_fin){
        estirando_agarre_quitanieves = true ;

    }

    update();
}

/*****************************************************************************//**
 * FUNCION QUE ESTIRA Y ENCOGE EL QUITANIEVES CUANDO ESTE HA DEJADO DE SUBIR Y BAJAR
 *****************************************************************************/

void _gl_widget::animacion_estira_quitanieves(){

    //5 Es el maximo que llega a estirar el quitanieves para que no llegue incoherentemente lejos
    if(libertad_estirar_quitanieves+velocidad_estirar_quitanieves <= 5 && estirando_agarre_quitanieves && quitanieves_fin)
        libertad_estirar_quitanieves+=velocidad_estirar_quitanieves;

    //Cuando ha estirado lo suficiente marca que ya no lo esta estirando
    else if(libertad_estirar_quitanieves+velocidad_estirar_quitanieves > 5 && estirando_agarre_quitanieves && quitanieves_fin )
        estirando_agarre_quitanieves=false;

    //Si ya no esta estirando empieza a devolverlo a la posicion original
    else if(libertad_estirar_quitanieves-velocidad_estirar_quitanieves >= 0 && !estirando_agarre_quitanieves && quitanieves_fin)
        libertad_estirar_quitanieves-=velocidad_estirar_quitanieves;

    //Cuando llega a la posicion original marca que el movimiento de estirar el quitanieves ha terminado
    else if(libertad_estirar_quitanieves-velocidad_estirar_quitanieves < 0 && !estirando_agarre_quitanieves && quitanieves_fin && !agarre_quitanieves_fin){
        estirando_agarre_quitanieves=true;
        agarre_quitanieves_fin = true;

    //Si este movimiento ha terminado y el quitanieves esta en la posicion original, se da paso al siguiente movimiento
    }else if (agarre_quitanieves_fin && libertad_estirar_quitanieves-velocidad_estirar_quitanieves < 0 && !abriendo_codo && !cerrando_codo && !codo_fin && !bajando_brazo && !subiendo_brazo  && !brazo_fin && !vaciando_pala && !llenando_pala && !pala_fin)
        abriendo_codo = true ;

    update();
}

/*****************************************************************************//**
 * FUNCION QUE ESTIRA Y ENCOGE LA EXCAVADORA TRASERA POR LA ARTICULACION DEL CODO
 *****************************************************************************/

void _gl_widget::animacion_codo(){

    //70 es el angulo necesario con el que mover esta parte sin que atraviese la figura al combinarlo con otros movimientos
    if(libertad_codo_brazo+velocidad_codo_brazo <= 70 && quitanieves_fin && abriendo_codo && !cerrando_codo && !codo_fin && !bajando_brazo && !subiendo_brazo  && !brazo_fin && !vaciando_pala && !llenando_pala && !pala_fin)
        libertad_codo_brazo+=velocidad_codo_brazo;

    //Si llega a la posicion maxima indica que ya no esta abriendo el brazo y da paso al siguiente movimiento (no vuelve al origen aun)
    else if(libertad_codo_brazo+velocidad_codo_brazo > 70 && quitanieves_fin && abriendo_codo && !cerrando_codo && !codo_fin && !bajando_brazo && !subiendo_brazo  && !brazo_fin && !vaciando_pala && !llenando_pala && !pala_fin ){
        abriendo_codo=false;
        subiendo_brazo = true;

    //Si han terminado los movimientos previos (llenar y vaciar pala, subir y bajar brazo entero) empieza la vuelta a posicion original
    }else if(libertad_codo_brazo-velocidad_codo_brazo >= 20 && cerrando_codo && pala_fin && brazo_fin)
        libertad_codo_brazo-=velocidad_codo_brazo;

    //Si ha vuelto a la posicion original guarda que ya no esta cerrando el codo y activa el siguiente movimiento (figura completa)
    else if(libertad_codo_brazo-velocidad_codo_brazo < 20 && cerrando_codo && pala_fin && brazo_fin){
        codo_fin=true;
        cerrando_codo=false;
        avanzando_entero =true;
    }

    update();
}

/*****************************************************************************//**
 * FUNCION QUE SUBE Y BAJA EL BRAZO ENTERO USANDO COMO EJE LA UNION DEL BRAZO CON EL RESTO DE FIGURA
 *****************************************************************************/

void _gl_widget::animacion_brazo(){

    //-50 Es el angulo adecuado para que este movimiento combinado con otros no atraviese un suelo imaginario ni la propia figura
    if(libertad_brazo_entero-velocidad_brazo_entero >= -50  && !abriendo_codo && !cerrando_codo && !codo_fin && !bajando_brazo && subiendo_brazo  && !brazo_fin && !vaciando_pala && !llenando_pala && !pala_fin){
        libertad_brazo_entero-=velocidad_brazo_entero;

    //Si ha llegado al maximo indica que ya no esta subiendo el brazo y da pie al siguiente movimiento (vaciar la pala)
    }else if(libertad_brazo_entero-velocidad_brazo_entero < -50 && !abriendo_codo && !cerrando_codo && !codo_fin && !bajando_brazo && subiendo_brazo  && !brazo_fin && !vaciando_pala && !llenando_pala && !pala_fin){
        subiendo_brazo=false;
        vaciando_pala=true;

    //Si han terminado los movimientos necesarios (vaciar pala) empieza el regreso a la posicion original (bajar el brazo)
    }else if(libertad_brazo_entero+velocidad_brazo_entero <= 0 &&  !abriendo_codo && !cerrando_codo && !codo_fin && bajando_brazo && !subiendo_brazo  && !brazo_fin && !vaciando_pala && !llenando_pala && !pala_fin ){
        libertad_brazo_entero+=velocidad_brazo_entero;

    //Cuando esta en la posicion original indica que ha terminado este movimiento y da paso al siguiente (llenar la pala)
    }else if(libertad_brazo_entero+velocidad_brazo_entero > 0 &&  !abriendo_codo && !cerrando_codo && !codo_fin && bajando_brazo && !subiendo_brazo  && !brazo_fin && !vaciando_pala && !llenando_pala && !pala_fin ){
        brazo_fin=true;
        llenando_pala = true;
        bajando_brazo=false;
    }

    update();
}

/*****************************************************************************//**
 * FUNCION QUE VACIA Y LLENA LA PALA
 *****************************************************************************/

void _gl_widget::animacion_pala(){

    //-80 Es el angulo correcto para que no haga movimientos incoherentes
    if(libertad_pala-velocidad_pala > -80 && !abriendo_codo && !cerrando_codo && !codo_fin && !bajando_brazo && !subiendo_brazo  && !brazo_fin && vaciando_pala && !llenando_pala && !pala_fin ){
        libertad_pala-=velocidad_pala;

    //Si llega al maximo indica que ya no esta vaciando la pala y da paso al siguiente movimiento (bajar el brazo)
    }else if(libertad_pala-velocidad_pala <= -80 && !abriendo_codo && !cerrando_codo && !codo_fin && !bajando_brazo && !subiendo_brazo  && !brazo_fin && vaciando_pala && !llenando_pala && !pala_fin ){
        vaciando_pala=false;
        bajando_brazo=true;

    //Si han terminado los movimientos previos (bajar el brazo) vuelve al origen (llenar la pala)
    }else if(libertad_pala+velocidad_pala < 0 && llenando_pala && brazo_fin ){
        libertad_pala+=velocidad_pala;

    //Si ha terminado el movimiento lo indica y da paso al siguiente (que cierre el codo)
    }else if(libertad_pala+velocidad_pala >= 0 && llenando_pala && brazo_fin ){
        pala_fin=true;
        cerrando_codo = true;
        llenando_pala = false;

    }


    update();
}

/*****************************************************************************//**
 * FUNCION QUE MUEVE LA FIGURA COMPLETA HACIA DELANTE Y DETRAS Y GIRA LAS RUEDAS EN CONCORDANCIA
 *****************************************************************************/

void _gl_widget::animacion_entero(){

    //20 es la distancia que he elegido para que avance
    if(libertad_entero+velocidad_entero < 20 && codo_fin && pala_fin && brazo_fin && avanzando_entero){
        libertad_entero+=velocidad_entero;

    //Si llega a la distancia maxima indica que ya no esta avanzando sino retrocediendo
    }else if(libertad_entero+velocidad_entero >= 20 && codo_fin && pala_fin && brazo_fin && avanzando_entero  ){
        avanzando_entero=false;
        retrocediendo_entero = true;

    //Si esta retrocediento se mueve hacia el origen
    }else if(libertad_entero-velocidad_entero > 0 && codo_fin && pala_fin && brazo_fin && retrocediendo_entero){
        libertad_entero-=velocidad_entero;

    //Al llegar al origen indica que este movimiento (el ultimo) ha terminado
    }else if(libertad_entero-velocidad_entero <= 0 && codo_fin && pala_fin && brazo_fin && retrocediendo_entero){
        entero_fin=true;
    }

    //Al ser el ultimo movimiento, cuando termina reestablece los valores para que comience de nuevo en bucle
    if(codo_fin && brazo_fin && pala_fin && entero_fin && agarre_quitanieves_fin && puerta_fin && ventanilla_fin && quitanieves_fin){
                abriendo_codo = false;
                cerrando_codo = false;
                codo_fin = false;
                vaciando_pala = false;
                llenando_pala = false;
                pala_fin = false;
                subiendo_brazo = false;
                bajando_brazo = false;
                brazo_fin = false;
                subiendo_quitanieves = false;
                bajando_quitanieves = false;
                quitanieves_fin = false ;
                abriendo_puerta = true;
                puerta_fin = false ;
                bajando_ventanilla = false;
                ventanilla_fin = false;
                avanzando_entero = false;
                retrocediendo_entero = false;
                entero_fin = false;
                estirando_agarre_quitanieves =false;
                encogiendo_agarre_quitanieves =false;
                agarre_quitanieves_fin =false;
    }

    update();
}

/*****************************************************************************//**
 * FUNCION QUE MANTIENE LA LUZ MAGENTA (POSICIONAL, LUZ1) GIRANDO CONSTANTEMENTE SOBRE LA FIGURA
 *****************************************************************************/

void _gl_widget::animacion_luz(){

    //Aumenta el angulo sobre el que gira del centro
    //angx_luz1+=1;
    angy_luz1+=1;
    //angz_luz1+=1;

    update();
}

/*****************************************************************************//**
 * Evento tecla pulsada
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent){

  switch(Keyevent->key()){

        //Objetos
        case Qt::Key_1:Object=OBJECT_TETRAHEDRON;Window->cambiarcheckbox_objeto(Object, Object_antiguo);break;
        case Qt::Key_2:Object=OBJECT_CUBE;Window->cambiarcheckbox_objeto(Object , Object_antiguo);break;
        case Qt::Key_3:Object=OBJECT_CONO;Window->cambiarcheckbox_objeto(Object , Object_antiguo);break;
        case Qt::Key_4:Object=OBJECT_CILINDRO;Window->cambiarcheckbox_objeto(Object, Object_antiguo);break;
        case Qt::Key_5:Object=OBJECT_ESFERA;Window->cambiarcheckbox_objeto(Object, Object_antiguo);break;
        case Qt::Key_6:Object=OBJECT_PLY;Window->cambiarcheckbox_objeto(Object, Object_antiguo);break;
        case Qt::Key_7:Object=OBJECT_HIERARCHICAL;Window->cambiarcheckbox_objeto(Object, Object_antiguo);break;
        case Qt::Key_8:Object=OBJECT_TABLERO;Window->cambiarcheckbox_objeto(Object, Object_antiguo);break;
        case Qt::Key_9:Object=OBJECT_PLY_PERFIL;Window->cambiarcheckbox_objeto(Object, Object_antiguo);break;
        case Qt::Key_0:Object=OBJECT_MATRIZ;Window->cambiarcheckbox_objeto(Object, Object_antiguo);break;

        //Modo de dibujado
        case Qt::Key_P:Draw_point=!Draw_point; Window->cambiarcheckbox_pintado(Keyevent->key());break;
        case Qt::Key_L:Draw_line=!Draw_line;Window->cambiarcheckbox_pintado(Keyevent->key());break;
        case Qt::Key_F:Draw_solid=!Draw_solid;

                       if(!Draw_solid){
                           Draw_fill = false;
                           Draw_chess = false;
                           flat =false;
                           Draw_textura = false;
                           smooth = false;
                           luz_activada = false;
                       }Window->cambiarcheckbox_pintado(Keyevent->key());break;

        case Qt::Key_F1: if(Draw_solid){ Draw_chess=false;Draw_fill=!Draw_fill;}Window->cambiarcheckbox_pintado(Keyevent->key());break;
        case Qt::Key_F2: if(Draw_solid){ Draw_fill=false;Draw_chess=!Draw_chess;}Window->cambiarcheckbox_pintado(Keyevent->key());break;

        //Mover la vista del observador con las flechas
        case Qt::Key_Left:    Observer_angle_y-=ANGLE_STEP;break;
        case Qt::Key_Right:   Observer_angle_y+=ANGLE_STEP;break;
        case Qt::Key_Up:      Observer_angle_x-=ANGLE_STEP;break;
        case Qt::Key_Down:    Observer_angle_x+=ANGLE_STEP;break;

        //Teclas para el zoom
        case Qt::Key_PageUp:
            if (Projection_type == PERSPECTIVE_PROJECTION) Observer_distance*=DISTANCE_FACTOR;
            else Scale_factor*=DISTANCE_FACTOR;
        break;

        case Qt::Key_PageDown:
            if (Projection_type == PERSPECTIVE_PROJECTION) Observer_distance/=DISTANCE_FACTOR;
            else Scale_factor/=DISTANCE_FACTOR;
        break;

        //Movimientos jerarquicos
        //GRADO DE ESTIRAR EL QUITANIEVES--------------------------------
        case Qt::Key_Q: //Encoge el quitanieves
            if(libertad_estirar_quitanieves+velocidad_estirar_quitanieves < 5){
                libertad_estirar_quitanieves+=velocidad_estirar_quitanieves;
            }else{
                libertad_estirar_quitanieves= 5;
            }
         break;

        case Qt::Key_W: //Estira el quitanieves
            if(libertad_estirar_quitanieves-velocidad_estirar_quitanieves > 0){
                libertad_estirar_quitanieves-=velocidad_estirar_quitanieves;
            }else{
                libertad_estirar_quitanieves=0;
            }
        break;

         //GRADO DEL QUITANIEVES--------------------------------
         case Qt::Key_S: //Sube el quitanieves
              if(libertad_quitanieves + velocidad_quitanieves < 55)
                  libertad_quitanieves += velocidad_quitanieves;
              else
                  libertad_quitanieves=55;
         break;

        case Qt::Key_D: //Baja el quitanieves
              if(libertad_quitanieves - velocidad_quitanieves > 0)
                  libertad_quitanieves -= velocidad_quitanieves;
              else
                  libertad_quitanieves=0;
        break;

       //GRADO DEL CODO--------------------------------
       case Qt::Key_Z: //Abre el codo
          if(libertad_codo_brazo + velocidad_codo_brazo < 70)
              libertad_codo_brazo += velocidad_codo_brazo;
          else
              libertad_codo_brazo=70;
       break;

       case Qt::Key_X: //Cierra el codo
          if(libertad_codo_brazo - velocidad_codo_brazo > 20)
              libertad_codo_brazo -= velocidad_codo_brazo;
          else
              libertad_codo_brazo=20;
       break;

        //VELOCIDAD DE CODO--------------------------------
        case Qt::Key_R:velocidad_codo_brazo+=0.1;
            break;
        case Qt::Key_E:
            if(velocidad_codo_brazo > 0)
                velocidad_codo_brazo-=0.1;
        break;

        //VELOCIDAD QUITANIEVES--------------------------------
        case Qt::Key_Y:velocidad_quitanieves+=0.1;
            break;
        case Qt::Key_T:
            if(velocidad_quitanieves > 0)
                velocidad_quitanieves-=0.1;
        break;

            //VELOCIDAD ESTIRAR EL QUITANIEVES--------------------------------
        case Qt::Key_I:velocidad_estirar_quitanieves+=0.1;
          break;
        case Qt::Key_U:
            if(velocidad_estirar_quitanieves > 0)
                velocidad_estirar_quitanieves-=0.1;
        break;

/*
        //GRADO DE LA PALA--------------------------------
        case Qt::Key_Q: //Sube la pala (la llena)
            if(libertad_pala-velocidad_pala > -160){
                libertad_pala-=velocidad_pala;
            }else{
                libertad_pala= -160;
            }
            break;

        case Qt::Key_W: //Baja la pala (la vacia)
            if(libertad_pala+velocidad_pala < 5){
                libertad_pala+=velocidad_pala;
            }else{
                libertad_pala=5;
            }
            break;

        //GRADO DEL BRAZO ENTERO--------------------------------
        case Qt::Key_H: //Baja el brazo
            if(libertad_brazo_entero + velocidad_brazo_entero < 5)
                libertad_brazo_entero += velocidad_brazo_entero;
            else
                libertad_brazo_entero=5;
            break;

        case Qt::Key_G://Sube el brazo
            if(libertad_brazo_entero - velocidad_brazo_entero > -20)
                libertad_brazo_entero -= velocidad_brazo_entero;
            else
                libertad_brazo_entero=-20;
            break;
        //VELOCIDAD DEL BRAZO ENTERO--------------------------------
        case Qt::Key_N:velocidad_brazo_entero+=0.1;
          break;
        case Qt::Key_B:
          if(velocidad_brazo_entero > 0)
            velocidad_brazo_entero-=0.1;
        break;
        //VELOCIDAD PALA--------------------------------
        case Qt::Key_I:velocidad_pala+=0.1;
          break;
        case Qt::Key_U:
            if(velocidad_pala > 0)
                velocidad_pala-=0.1;
        break;
    */

        //Animacion
        case Qt::Key_A:
            Animation=!Animation;

            if(Animation==true){
                timer_animacion->start(1); //el numero de milisegundos antes de que haga una accion
                connect(timer_animacion, SIGNAL(timeout()), this, SLOT( animacion()), Qt::UniqueConnection);
            }else timer_animacion->stop();

        break;

        //PRACTICA 4 LUCES
        //Encender y apagar luz0 blanca
        case Qt::Key_J:if(flat||smooth)interruptor0=!interruptor0;Window->cambiarcheckbox_pintado(Keyevent->key()); break;
        //Encender y apagar luz1 magenta
        case Qt::Key_K:if (flat||smooth)interruptor1=!interruptor1;Window->cambiarcheckbox_pintado(Keyevent->key()); break;


        //Display flat mode
        case Qt::Key_F3:if(Draw_solid ){
              smooth=false;flat=!flat;
              if(flat)luz_activada=true;
              else luz_activada=false;}
            Window->cambiarcheckbox_pintado(Keyevent->key());
        break;
        //Display smooth mode
        case Qt::Key_F4:if(Draw_solid ){
              flat=false;smooth=!smooth;
              if(smooth)luz_activada=true;
              else luz_activada=false;}
            Window->cambiarcheckbox_pintado(Keyevent->key());
        break;
        //Display texturas con la luz apagada
        case Qt::Key_F5:if(Draw_solid){
              flat = false;
              smooth=false;
              Draw_chess=false;
              Draw_fill=false;
              Draw_textura=!Draw_textura;
            }
            Window->cambiarcheckbox_pintado(Keyevent->key());
        break;
        //Display texturas con flat
        case Qt::Key_F6:if(Draw_solid){
              flat_textura=!flat_textura;
              flat=smooth=Draw_fill=Draw_chess=false;
              Draw_textura=true;

              if(flat_textura)luz_activada=true;
              else{
                  luz_activada=false;
              }
        }
            Window->cambiarcheckbox_pintado(Keyevent->key());
        break;
        //Display texturas con smooth
        case Qt::Key_F7:if(Draw_solid){
               smooth_textura =! smooth_textura;
               flat=smooth=Draw_fill=Draw_chess=false;
               Draw_textura=true;

               if(smooth_textura)luz_activada=true;
               else{
                   luz_activada=false;
               }
        }
            Window->cambiarcheckbox_pintado(Keyevent->key());
        break;

        //Cambia el material consecutivo
        case Qt::Key_M:contador_color++;break;

        //Cambia la proyeccion
        case Qt::Key_C:Projection_type=PERSPECTIVE_PROJECTION;Window->cambiarcheckbox_pintado(Keyevent->key());break;
        case Qt::Key_V:Projection_type=PARALLEL_PROJECTION;Window->cambiarcheckbox_pintado(Keyevent->key());break;

        //Rotar la luz magenta alrededor del eje
        case Qt::Key_F8:angy_luz1++;break;
        case Qt::Key_F9:angy_luz1--;break;


  }

  Object_antiguo = Object;

  update(); //le decimos a qt que actualice el nuevo evento que tiene que hacer por cada tecla que hayamos pulsado
}

/*****************************************************************************//**
 * Limpiar ventana
 *****************************************************************************/

void _gl_widget::clear_window()
{
  //Limpia el valor de los buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *****************************************************************************/

void _gl_widget::change_projection(){

    //Establece la pila matriz para las operaciones posteriores con esta (GL_MODELVIEW, GL_PROJECTION, GL_TEXTURE, GL_COLOR)
    glMatrixMode(GL_PROJECTION); //Modo proyeccion
    //Transforma la matriz anterior en la matriz identidad que es equivalente pero mas eficiente
    glLoadIdentity();

    //Guarda la relacion de la ventana principal
    float Aspect=(float)Window_height/(float)Window_width;

    //Si el modo proyeccion seleccionado es perspectiva
    if (Projection_type==PERSPECTIVE_PROJECTION)
        //glFrustum(amplitud_izquierda, amplitud_derecha, amplitud_superior, amplitud_inferior, distancia al plano frontal, dist al plano trasero);
        glFrustum(X_MIN,X_MAX,Y_MIN*Aspect,Y_MAX*Aspect,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);

    //Si el modo proyeccion seleccionado es ortogonal
    else if (Projection_type==PARALLEL_PROJECTION)
        //glOrtho(amplitud_izquierda, amplitud_derecha, amplitud_superior, amplitud_inferior, distancia al plano frontal, dist al plano trasero);
        glOrtho(X_MIN*Scale_factor,X_MAX*Scale_factor,Y_MIN*Aspect*Scale_factor,Y_MAX*Aspect*Scale_factor,FRONT_PLANE_PARALLEL,BACK_PLANE_PARALLEL);

}

/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *****************************************************************************/

void _gl_widget::change_observer()
{

    //Establece la pila matriz para las operaciones posteriores con esta (GL_MODELVIEW, GL_PROJECTION, GL_TEXTURE, GL_COLOR)
    glMatrixMode(GL_MODELVIEW); //Modo vista del modelo
    //Transforma la matriz anterior en la matriz identidad que es equivalente pero mas eficiente
    glLoadIdentity();

    glTranslatef(0,0,10-Observer_distance);

    //Funcion para mover la camara a donde queramos
    //3 primeros argumentos: Donde estamos (VRP)
    //3 argumentos siguientes: Hacia donde miramos (VPN)
    //3 ultimos argumentos: Inclinacion de la camara (VUP)
    transformar_camara(0,0,10,0,0,0,0,1,0);

    //Para mover la posicion del observador. Tanto para acercarte y alejar con el zoom como para rotar con las flechas/raton
    //glTranslatef(0,0,-Observer_distance);
    glRotatef(Observer_angle_x,1,0,0);
    glRotatef(Observer_angle_y,0,1,0);

}

/*****************************************************************************//**
 * FUNCION PARA LA ACCION RELACIONADA CON EL MOVIMIENTO DEL RATON (MOVER LA CAMARA CON EL RATON)
 *****************************************************************************/

void _gl_widget::mouseMoveEvent(QMouseEvent *evento){

    //Si identifica que hay un click y es el boton izquierdo
    if((evento->buttons() & Qt::LeftButton) == Qt::LeftButton){

        //Calcula cuanto ha movido el raton con el ultimo movimiento y hacia donde (dependiendo de si da positivo o negativo)
        difx = evento->pos().x() - savedx;
        dify = evento->pos().y() - savedy;

        //Guarda estos valores para la proxima vez que hagamos click no tenga un fallo de discontinuidad
        savedx = evento->pos().x();
        savedy = evento->pos().y();

        //Mueve la camara tanto como haya movido el rato
        Observer_angle_x += dify;
        Observer_angle_y += difx;

    }

    update();

}

/*****************************************************************************//**
 * FUNCION PARA LA ACCION RELACIONADA CON EL GIRO DE LA RUEDA DEL RATON
 *****************************************************************************/

void _gl_widget::wheelEvent(QWheelEvent *evento){

    //Most mouse types work in steps of 15 degrees, in which case the delta value is a multiple of 120; i.e., 120 units * 1/8 = 15 degrees.

    //Como angleDelta devuelve los grados rotados de la rueda en multiplos de 8, al dividirlo obtenemos los grados que han sido (documentacion)
    const int degrees = evento->angleDelta().y() / 8;
    //Un grado normalmente tiene 15 pasos, por lo que para obtener cuantos pasos hemos girado la rueda dividimos entre 15
    int steps = degrees / 15;

    //Si la proyeccion es perspectiva...
    if (Projection_type==PERSPECTIVE_PROJECTION) {
        //...y giramos hacia delante estamos haciendo zoom, por lo que divimos la distancia tanto como pasos rotemos
        if (degrees > 0) Observer_distance /= steps*DISTANCE_FACTOR;
        //...y giramos hacia detras estamos quitando zoom, por lo que multiplicamos la distancia tanto como pasos rotemos
        else if (degrees < 0)  Observer_distance *= abs(steps*DISTANCE_FACTOR);

    //Si la proyeccion es ortogonal...
    }else if (Projection_type==PARALLEL_PROJECTION) {
        //...y giramos hacia delante estamos haciendo zoom, por lo que divimos la relacion de aspecto del campo de vision (a menor valor, mas grande se ve el objeto)
        if (degrees > 0) Scale_factor /= steps*DISTANCE_FACTOR;
        //...y giramos hacia detras estamos quitando zoom, por lo que aumentamos la relacion de aspecto del campo de vision (a mayor campo, mas pequeño es el objeto en comparacion)
        else if (degrees < 0)  Scale_factor *= abs(steps*DISTANCE_FACTOR);
    }

    //Acepta el evento para realizarlo
    evento->accept();
    update();

}

/*****************************************************************************//**
 * FUNCION PARA LA ACCION RELACIONADA CON EL CLICK DEL RATON
 *****************************************************************************/

void _gl_widget::mousePressEvent(QMouseEvent *event)
{
    //Si se identifica un click y es el boton derecho
    if ( event->buttons() & Qt::RightButton ) {
        Selection_position_x = event->x(); //La posicion x del cursor, relativa al widget pulsado
        Selection_position_y = height() - event->y();   //eso es porque el (0,0) esta arriba a la izquierda y la y aumenta conforme baja. Con esto hace que cuanto mas arriba pulses, mayor sea la y, para mantener la logica que seguimos nosotros
    }else{  //Si se identifica un click y es el boton izquierdo guarda la posicion pulsada para la continuidad de mover la camara
        savedx=event->pos().x();
        savedy=event->pos().y();
    }


}

/*****************************************************************************//**
 * FUNCION PARA LA ACCION RELACIONADA CON SOLTAR UN BOTON DEL RATON
 *****************************************************************************/

void _gl_widget::mouseReleaseEvent(QMouseEvent *Event){

    if (Draw_fill) { //Solo puedes seleccionar un triangulo en modo fill
        if ( Event->button() & Qt::RightButton ) { //Si se ha pulsado con el boton derecho
            pick();  //Funcion que identifica el triangulo seleccionado por su posicion y color y lo pinta diferente
            Selected_triangle_aux=Selected_triangle;    //Tras seleccionarlo, lo guardamos en el auxiliar para que este guarde el anterior siempre
            update();
        }
    }

}

void _gl_widget::transformar_camara(float x_posicion, float y_posicion,float z_posicion,float x_objetivo, float y_objetivo,float z_objetivo, float u_x, float u_y, float u_z){

    //Como la inclinacion de la camara rota sobre el eje z, esta se configura cambiando x e y, la z no cambia
    u_z=0;

    //Vector en direccion contraria a donde miramos (desde objeto hasta la camara)
    _vertex3f VPN = _vertex3f(x_posicion-x_objetivo,y_posicion-y_objetivo,z_posicion-z_objetivo);
    //Vector perpendicular a VPN que será VUP
    _vertex3f VUP = _vertex3f(0, 1, 0);
    if(VPN._1!=0){
        VUP._0=-VPN._0;
        VUP._1=(pow(VPN._0,2) + pow(VPN._2,2))/VPN._1;
        VUP._2=-VPN._2;
    }
    if(x_objetivo ==0 && z_objetivo==0 && y_objetivo!=0){

        if(y_objetivo<0) VUP._2=1;
        else VUP._2=-1;

    }

    //Modulo de la proyeccion de VPN que rotaremos sobre el eje x. Este valor es necesario para calcular cuanto girar sobre Y antes de girar sobre X
    float p = sqrt(pow(VPN._1,2)+pow(VPN._2,2));
    //Modulo para la rotacion sobre Z
    float p_up = sqrt(pow(VUP._1,2)+pow(VUP._2,2));
    float w = atan2(abs(VUP._1),abs(VUP._2)) * 180 / M_PI;

    float angulox = 0;

    if(u_x>0 && u_y<0){ //Si VPN sale positivo en Z y negativo en Y, este se movera hacia abajo (sentido natural de giro en el eje X), por lo que moveremos la escena en sentido contrario (en negativo)
        angulox = atan2f(abs(u_x),abs(u_y));
        angulox = 270 - (angulox *180)/M_PI;
    }else if(u_x>0 && u_y>0){ //Si VPN sale positivo en ambos, hay que levantarlo (sentido contrario al giro sobre X), por lo que hay que girar la escena en el sentido positivo del eje X
        angulox = atan2f(abs(u_x),abs(u_y));
        angulox = 270 + (angulox *180)/M_PI;
    }else if(u_x<0 && u_y>0){ //Si VPN sale negativo en la Z y positivo en la Y habra que girar VPN 180 por abajo (movimiento natural del eje) hasta estar en sentido opuesto y luego subirlo (natural tambien) el angulox calculado, que para la escena es al contrario, es girarlo 180 por arriba (en negativo) y el angulox calculado tambien en negativo
        angulox = atan2f(abs(u_x),abs(u_y));
        angulox = 90-(angulox *180)/M_PI;
    }else if(u_x<0 && u_y<0){ //Si VPN sale negativo en ambos habra que girar VPN 180 por abajo (movimiento natural del eje) hasta estar en sentido opuesto y luego retroceder (antinatural) el angulox calculado, que para la escena es al contrario, es girarlo 180 por arriba (en negativo) y el angulox calculado moverlo en el positivo(natural)
        angulox = atan2f(abs(u_x),abs(u_y));
        angulox = 90+(angulox *180)/M_PI;
    }else if(u_y==0){
        angulox = -90 * u_x;
    }else if(u_x==0 && u_y<0){
        angulox=180;
    }else if(u_x==0 && u_y>0){
        angulox=0;
    }else if(VPN._0 != 0 && VPN._1 !=0 && VPN._2==0){
        angulox=90;
    }

    glRotatef(-angulox,0,0,1);

    //Angulo que rotaran los vectores sobre X e Y
    float anguloy, anguloz;
    angulox = anguloy = anguloz = 0;

    //Debido a los 4 cuadrantes posibles, nos encontramos que la rotacion sobre X depende de los valores de Y y de Z
    if(VPN._2>0 && VPN._1<0){ //Si VPN sale positivo en Z y negativo en Y, este se movera hacia abajo (sentido natural de giro en el eje X), por lo que moveremos la escena en sentido contrario (en negativo)
        angulox = atan2f(abs(VPN._1),abs(VPN._2));
        angulox = -(angulox *180)/M_PI;
    }else if(VPN._2>0 && VPN._1>0){ //Si VPN sale positivo en ambos, hay que levantarlo (sentido contrario al giro sobre X), por lo que hay que girar la escena en el sentido positivo del eje X
        angulox = atan2f(abs(VPN._1),abs(VPN._2));
        angulox = (angulox *180)/M_PI;
    }else if(VPN._2<0 && VPN._1>0){ //Si VPN sale negativo en la Z y positivo en la Y habra que girar VPN 180 por abajo (movimiento natural del eje) hasta estar en sentido opuesto y luego subirlo (natural tambien) el angulox calculado, que para la escena es al contrario, es girarlo 180 por arriba (en negativo) y el angulox calculado tambien en negativo
        angulox = atan2f(abs(VPN._1),abs(VPN._2));
        angulox = -180-(angulox *180)/M_PI;
    }else if(VPN._2<0 && VPN._1<0){ //Si VPN sale negativo en ambos habra que girar VPN 180 por abajo (movimiento natural del eje) hasta estar en sentido opuesto y luego retroceder (antinatural) el angulox calculado, que para la escena es al contrario, es girarlo 180 por arriba (en negativo) y el angulox calculado moverlo en el positivo(natural)
        angulox = atan2f(abs(VPN._1),abs(VPN._2));
        angulox = -180+(angulox *180)/M_PI;
    }else if(VPN._0 == 0 && VPN._1 !=0 && VPN._2==0){
        angulox = 90;
        if(VPN._1<0) angulox *= -1;
    }else if(VPN._0 != 0 && VPN._1 !=0 && VPN._2==0){
        angulox = 90;
    }

    //Girar sobre Y lo necesario para luego girar sobre X
    if(VPN._0>0){ //Si el giro sobre Y de VPN es hacia el sentido natural de giro (x_vpn > 0), el giro de la escena sera al contrario
        anguloy =  atan2f(abs(VPN._0),p);
        anguloy = -(anguloy *180)/M_PI;

    }else{  //Si el giro sobre Y de VPN es hacia el sentido opuesto del giro (x_vpn < 0), el giro de la escena sera en el sentido positivo
        anguloy =  atan2f(abs(VPN._0),p);
        anguloy = (anguloy *180)/M_PI;
    }

    if(x_posicion==0 && y_posicion == 0 && z_posicion<0) anguloy=180;

    float s = 180 - (w+angulox);
    s = s * M_PI / 180;
    float A = p_up * sin(s);
    float x=0;
    if(anguloy!=90)
        x = abs(VUP._0) / sin((90-anguloy)*M_PI/180);

    anguloz = 90 - atan2(abs(A),abs(x)) * 180 / M_PI;

    //Girar la camara sobre Z para darle la inclinacion indicada con el VUP
    if(x_posicion>0)
        glRotatef(-anguloz,0,0,1);
    else if (x_posicion<0)
        glRotatef(anguloz,0,0,1);

    glRotatef(anguloy,0,1,0);
    glRotatef(angulox,1,0,0);

    //Movemos la camara a su posicion (negativo porque en realidad se mueve la escena con respecto a ti)
    glTranslatef(-x_posicion,-y_posicion,-z_posicion);

}

/*****************************************************************************//**
 * FUNCION QUE SELECCIONA UN TRIANGULO SEGUN LA POSICION EN LA QUE PULSES CON EL CLICK DERECHO
 * (GUIANDOSE POR UN COLO UNIVOCO QUE LO IDENTIFICA) Y PINTA ESTE DE OTRO COLOR
 *****************************************************************************/

void _gl_widget::pick(){

      //Se prepara para renderizar contenido OpenGL haciendo que el contexto sea actual y vinculando el framebuffer en ese contexto.
      makeCurrent();

      // Frame Buffer Object to do the off-screen rendering
      glGenFramebuffers(1,&FBO); //Se guarda en FBO un nombre unico para un framebuffer (1 por el primer parametro)
      glBindFramebuffer(GL_FRAMEBUFFER,FBO); //Asocia un objeto a ese identificador unico

      // Texture for drawing
      glGenTextures(1,&Color_texture);
      glBindTexture(GL_TEXTURE_2D,Color_texture);
      // RGBA8
      glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window_width,Window_height); //Especifica los requisitos de almacenamiento de la textura
      // this implies that there is not mip mapping
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); //Establece los parametros para la textura
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); //Establece los parametros para la textura

      // Texure for computing the depth
      glGenTextures(1,&Depth_texture);
      glBindTexture(GL_TEXTURE_2D,Depth_texture);
      // Float
      glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window_width,Window_height); //Especifica los requisitos de almacenamiento de la textura

      // Attatchment of the textures to the FBO
      glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
      glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

      // OpenGL will draw to these buffers (only one in this case)
      static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
      glDrawBuffers(1,Draw_buffers);

        /*************************/

        //Limpia la ventana
        clear_window();
        change_projection();
        change_observer();

        //Depende del objeto seleccionado pero lo que se pinta es la figura "invisible" que contendra cada triangulo de un color
        switch (Object){
          case OBJECT_TETRAHEDRON:Tetrahedron.draw_selection();break;
          case OBJECT_CONO:Cono.draw_selection();break;
          case OBJECT_CILINDRO:Cilindro.draw_selection();break;
          case OBJECT_ESFERA:Esfera.draw_selection();break;
          case OBJECT_PLY:Ply.draw_selection();break;
          case OBJECT_TABLERO:tablero.draw_selection();break;
          case OBJECT_MATRIZ: matriz.draw_selection_matriz();break;
          case OBJECT_CUBE:Cube.draw_selection();break;
          default:break;
        }

        /*************************/

        //Obtener el pixel
        int Color; //Creo un color que sera el que tenga un pixel al dar click sobre este
        glReadBuffer(GL_FRONT); //
        glPixelStorei(GL_PACK_ALIGNMENT,1);
        //Leemos un pixel por pantalla al hacer click derecho y obtenemos sus coordenadas y su color
        glReadPixels(Selection_position_x,Selection_position_y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);

        /*************************/

        // convertir de RGB a identificador

        uint B = uint((Color & 0x00FF0000) >> 16);
        uint G = uint(Color & 0x0000FF00);
        uint R = uint((Color & 0x000000FF) << 16);


        // actualizar el identificador de la parte seleccionada en el objeto
        Selected_triangle = R + G  + B;

        //Si seleccionas en blanco o en el mismo que estaba seleccionado ya, no seleccionas ninguno
        if (Selected_triangle == 16777215 || Selected_triangle==Selected_triangle_aux) Selected_triangle=-1;


        //Guardas en el Selected_triangle de cada objeto cual es el triangulo de este que ha sido pulsado
        switch (Object){
          case OBJECT_TETRAHEDRON:Tetrahedron.selected_triangle(Selected_triangle);break;
          case OBJECT_CONO:Cono.selected_triangle(Selected_triangle);break;
          case OBJECT_CILINDRO:Cilindro.selected_triangle(Selected_triangle);break;
          case OBJECT_ESFERA:Esfera.selected_triangle(Selected_triangle);break;
          case OBJECT_PLY:Ply.selected_triangle(Selected_triangle);break;
          case OBJECT_TABLERO:tablero.selected_triangle(Selected_triangle);break;
          case OBJECT_MATRIZ:matriz.selected_triangle(Selected_triangle);break;
          case OBJECT_CUBE:Cube.selected_triangle(Selected_triangle);break;
          default:break;
        }

        /*************************/

        glDeleteTextures(1,&Color_texture);
        glDeleteTextures(1,&Depth_texture);
        glDeleteFramebuffers(1,&FBO);
        // the normal framebuffer takes the control of drawing
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());

}

/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *****************************************************************************/

void _gl_widget::draw_objects(){

    //Pinta los ejes
    Axis.draw_line();

    //Si el objeto esta vacio, no hace nada
    if(Object !=OBJECT_VACIO){

        //Para cambiar entre los 3 materiales (se cambia con la M, cada setColor tiene unos parametros diferentes)
        if(contador_color%3==0)material.setColor1();
        else if(contador_color%3==1)material.setColor2();
        else material.setColor3();

        //Si se ha activado la luz general, la habilita (se pone a true al activar flat o smooth)
        if(luz_activada)glEnable(GL_LIGHTING);
        else glDisable(GL_LIGHTING);

        //LUZ BLANCA EN EL INFINITO
        glPushMatrix();
            if(interruptor0) luz0.encender(); //Enciende o apaga la luz blanca del infinito con J
            else luz0.apagar();
        glPopMatrix();

        //LUZ MAGENTA NO EN EL INFINITO
        glPushMatrix();
            glTranslatef(libertad_entero,0,0); //Cuando se mueve el objeto entero en el eje x hacia delante y detras, la luz le acompania
            glRotatef(angy_luz1,0,1,0);  //Para poder rotarla sobre el eje y (alrededor del objeto) en animacion y con los botones
            //glRotatef(angz_luz1,0,0,1);
            //glRotatef(angx_luz1,1,0,0);

            if(interruptor1) luz1.encender(); //Enciende o apaga la luz magenta posicional con K
            else luz1.apagar();
        glPopMatrix();


        if (Draw_point){ //Para pintar los puntos en negro de las figuras
            glPointSize(5);
            glColor3fv((GLfloat *) &BLACK);
            switch (Object){
                case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
                case OBJECT_CUBE:Cube.draw_point();break;
                case OBJECT_PLY:Ply.draw_point();break;
                case OBJECT_PLY_MENU1:Ply_menu_1.draw_point();break;
                case OBJECT_PLY_MENU2:Ply_menu_2.draw_point();break;
                case OBJECT_PLY_MENU3:Ply_menu_3.draw_point();break;
                case OBJECT_PLY_MENU4:Ply_menu_4.draw_point();break;
                case OBJECT_PLY_MENU5:Ply_menu_5.draw_point();break;
                case OBJECT_CILINDRO:Cilindro.draw_point();break;
                case OBJECT_CONO:Cono.draw_point();break;
                case OBJECT_ESFERA:Esfera.draw_point();break;
                case OBJECT_PLY_PERFIL:PlyPerfil.draw_point();break;
                case OBJECT_TABLERO:tablero.draw_point();break;
                case OBJECT_MATRIZ:matriz.draw_matriz_points();break;
                case OBJECT_HIERARCHICAL:Grua.draw_point(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_quitanieves,  libertad_puerta,  libertad_ventanilla,  libertad_entero, libertad_estirar_quitanieves);break;
                default:break;
            }
        }

        if (Draw_line){ //Para pintar las lineas en magenta de las figuras
            glLineWidth(3); //Ancho de las lineas
            glColor3fv((GLfloat *) &MAGENTA);
            switch (Object){
                case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
                case OBJECT_CUBE:Cube.draw_line();break;
                case OBJECT_PLY:Ply.draw_line();break;
                case OBJECT_PLY_MENU1:Ply_menu_1.draw_line();break;
                case OBJECT_PLY_MENU2:Ply_menu_2.draw_line();break;
                case OBJECT_PLY_MENU3:Ply_menu_3.draw_line();break;
                case OBJECT_PLY_MENU4:Ply_menu_4.draw_line();break;
                case OBJECT_PLY_MENU5:Ply_menu_5.draw_line();break;
                case OBJECT_CILINDRO:Cilindro.draw_line();break;
                case OBJECT_CONO:Cono.draw_line();break;
                case OBJECT_ESFERA:Esfera.draw_line();break;
                case OBJECT_PLY_PERFIL:PlyPerfil.draw_line();break;
                case OBJECT_TABLERO:tablero.draw_line();break;
                case OBJECT_MATRIZ:matriz.draw_matriz_line();break;
                case OBJECT_HIERARCHICAL:Grua.draw_line(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_quitanieves,  libertad_puerta,  libertad_ventanilla,  libertad_entero, libertad_estirar_quitanieves);break;
                default:break;
            }
        }

        if (Draw_fill){ //Para pintar el fill de los objetos
            switch (Object){
                case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill(flat, smooth);break;
                case OBJECT_CUBE:Cube.draw_fill(flat, smooth);break;
                case OBJECT_PLY:Ply.draw_fill(flat, smooth);break;
                case OBJECT_PLY_MENU1:Ply_menu_1.draw_fill(flat, smooth);break;
                case OBJECT_PLY_MENU2:Ply_menu_2.draw_fill(flat, smooth);break;
                case OBJECT_PLY_MENU3:Ply_menu_3.draw_fill(flat, smooth);break;
                case OBJECT_PLY_MENU4:Ply_menu_4.draw_fill(flat, smooth);break;
                case OBJECT_PLY_MENU5:Ply_menu_5.draw_fill(flat, smooth);break;
                case OBJECT_CILINDRO:Cilindro.draw_fill(flat,smooth);break;
                case OBJECT_CONO:Cono.draw_fill(flat, smooth);break;
                case OBJECT_ESFERA:Esfera.draw_fill(flat, smooth);break;
                case OBJECT_PLY_PERFIL:PlyPerfil.draw_fill(flat, smooth);break;
                case OBJECT_TABLERO:tablero.draw_fill(flat, smooth);break;
                case OBJECT_HIERARCHICAL:Grua.draw_fill(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_quitanieves,  libertad_puerta,  libertad_ventanilla,  libertad_entero, libertad_estirar_quitanieves, flat, smooth);break;
                case OBJECT_MATRIZ:matriz.draw_matriz_fill(flat, smooth);break;
                default:break;
            }
        }

        if (Draw_chess){ //Para pintar el modo ajedrez intercalandro azul y amarillo
            switch (Object){
                case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess(flat, smooth);break;
                case OBJECT_CUBE:Cube.draw_chess(flat, smooth);break;
                case OBJECT_PLY:Ply.draw_chess(flat, smooth);break;
                case OBJECT_PLY_MENU1:Ply_menu_1.draw_chess(flat, smooth);break;
                case OBJECT_PLY_MENU2:Ply_menu_2.draw_chess(flat, smooth);break;
                case OBJECT_PLY_MENU3:Ply_menu_3.draw_chess(flat, smooth);break;
                case OBJECT_PLY_MENU4:Ply_menu_4.draw_chess(flat, smooth);break;
                case OBJECT_PLY_MENU5:Ply_menu_5.draw_chess(flat, smooth);break;
                case OBJECT_CILINDRO:Cilindro.draw_chess(flat, smooth);break;
                case OBJECT_CONO:Cono.draw_chess(flat, smooth);break;
                case OBJECT_ESFERA:Esfera.draw_chess(flat, smooth);break;
                case OBJECT_PLY_PERFIL:PlyPerfil.draw_chess(flat, smooth);break;
                case OBJECT_TABLERO:tablero.draw_chess(flat, smooth);break;
                case OBJECT_MATRIZ:matriz.draw_matriz_chess(flat, smooth);break;
                case OBJECT_HIERARCHICAL:Grua.draw_chess(libertad_codo_brazo,  libertad_pala,  libertad_brazo_entero,  libertad_quitanieves,  libertad_puerta,  libertad_ventanilla,  libertad_entero, libertad_estirar_quitanieves, flat, smooth);break;
                default:break;
            }
        }

        if (Draw_textura){ //Pinta la textura
            switch (Object){
                case OBJECT_CILINDRO:Cilindro.draw_textura_extra(flat_textura, smooth_textura, Cilindro.get_tapas_cant());break;
                case OBJECT_ESFERA:Esfera.draw_textura_extra(flat_textura, smooth_textura, Esfera.get_tapas_cant());break;
                case OBJECT_TABLERO:tablero.draw_textura(flat, smooth);break;
                default:break;
            }

        }

    }

}

/*****************************************************************************//**
 * Evento de dibujado
 *****************************************************************************/

void _gl_widget::paintGL()
{
  //Primero limpia la ventana
  clear_window();
  //Cambia la proyeccion
  change_projection();
  //Cambia la vista del observador
  change_observer();
  //Llama al pintado de los objetos
  draw_objects();
}

/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  //Guarda los valores de la ventana tras reajustarla en las variable para calcular mas tarde Aspect
  Window_width=Width1;
  Window_height=Height1;
  //Se le pasan las coordenadas de la ventana. Las dos primeras abajo a la izq y las otras dos arriba drcha
  glViewport(0,0,Width1,Height1);
}

/*****************************************************************************//**
 * INICIALIZA LA TEXTURA. ABRE LA IMAGEN CON CODIGO DE PRADO
 *****************************************************************************/

void _gl_widget::inicializarTexturas(){

  //Especificas el nombre del archivo a abrir como imagen (su ruta)
  QString File_name("C:/Users/xaviv/Desktop/fotamen.jpeg");
  QImage Image;
  QImageReader Reader(File_name);
  Reader.setAutoTransform(true);
  Image = Reader.read();
  if (Image.isNull()) {
    QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                             tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
    exit(-1);
  }
  Image=Image.mirrored();
  Image=Image.convertToFormat(QImage::Format_RGB888);

  // Code to pass the image to OpenGL to form a texture 2D
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  // Code to control the application of the texture
  glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());
}

/*****************************************************************************//**
 * Inicialización de OpenGL
 *****************************************************************************/

void _gl_widget::initializeGL(){

//  const GLubyte* strm;

//  strm = glGetString(GL_VENDOR);
//  std::cerr << "Vendor: " << strm << "\n";
//  strm = glGetString(GL_RENDERER);
//  std::cerr << "Renderer: " << strm << "\n";
//  strm = glGetString(GL_VERSION);
//  std::cerr << "OpenGL Version: " << strm << "\n";

//  if (strm[0] == '1'){
//    std::cerr << "Only OpenGL 1.X supported!\n";
//    exit(-1);
//  }

//  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
//  std::cerr << "GLSL Version: " << strm << "\n";

//  int Max_texture_size=0;
//  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
//  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  //Especifica los valores de rojo, verde, azul y alfa cuando se limpia el buffer de colores
  glClearColor(1.0,1.0,1.0,1.0);
  //Si esta activado hace comparaciones de profundidad y actualiza el buffer de profundidad
  glEnable(GL_DEPTH_TEST);

  //Inicializa los valores del observador
  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  //Inicializa los valores del modo de pintado
  Draw_point=false;
  Draw_line=false;
  Draw_fill=false;
  Draw_chess=false;
  Draw_solid=false;
  Draw_textura=false;

  //Llama a la funcion que abre la imagen que ira puesta en texturas
  inicializarTexturas();

  //Inicializa los valores para las proyecciones
  Projection_type = PERSPECTIVE_PROJECTION;
  Scale_factor = DEFAULT_SCALE_FACTOR;
  Window_height=height();
  Window_width=width();

  //Si no se ha seleccionado ningun triangulo, el actual y su anterior son -1 (no corresponden con ningun triangulo)
  Selected_triangle=-1;
  Selected_triangle_aux=-1;

  Object_antiguo = OBJECT_VACIO;

  //Para quitar los errores de referencia a las funciones de glew
  glewInit();

}



