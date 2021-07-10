/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>
#include <GL/glu.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QOpenGLTexture>
#include <QTimer>
#include <QImageReader>
#include <iostream>
#include <stdio.h>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
//nuevas añadidas
#include "cube.h"
#include "ply.h"
#include "rev.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"
#include "ply_perfil.h"
#include "hierarchical.h"
#include "lighting.h"
#include "material.h"
#include "tablero.h"
#include "matriz_ply.h"

namespace _gl_widget_ne {

    //Apertura del campo de vision por el lado izquierdo (X_MIN) y derecho (X_MAX)
    const float X_MIN=-.1;  //(si disminuye, abre el campo por la izquiera y la imagen se aprieta a la derecha)
    const float X_MAX=.1;   //(si aumenta, abre el campo por la derecha y la imagen se aprieta a la izquierda)
    //Apertura del campo de vision por la parte superior (Y_MIN) e inferior (Y_MAX)
    const float Y_MIN=-.1;  //(si disminuye, abre el campo por abajo y la imagen se aprieta hacia arriba)
    const float Y_MAX=.1;   //(si aumenta, abre el campo por arriba y la imagen se aprieta hacia abajo)

    //Son los planos de la escena para la proyeccion perspectiva, uno delantero donde se veran las imagenes y uno trasero
    const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;    //Distancia desde tu posicion al plano frontal (siempre positiva)
    const float BACK_PLANE_PERSPECTIVE=1000;                //Distancia desde tu posicion al plano trasero (siempre positiva)

    //Son los planos de la escena para la proyeccion ortogonal ("camara" en el infinito), ambos planon recogen en medio lo que se verá
    const float FRONT_PLANE_PARALLEL=-5000; //Distancia desde tu posicion al plano frontal. Si es negativo esta detras tuya
    const float BACK_PLANE_PARALLEL=5000;   //Distancia desde tu posicion al plano trasero

    //Distancia por defecto del observador
    const float DEFAULT_DISTANCE=BACK_PLANE_PERSPECTIVE/100;

    //Angulo de giro de la vista alrededor del objeto (usado con flechas del teclado para modificarlas)
    const float ANGLE_STEP=1;

    //Valor por el que multiplico la distancia del observador o scale_factor (dependiendo de la proyeccion) cuando los modific con el zoom
    const float DISTANCE_FACTOR=1.2;

    //Valor para inicializar Scale_factor por defecto
    const float DEFAULT_SCALE_FACTOR=100;

    //Enum para el nombre de las proyecciones
    typedef enum {PERSPECTIVE_PROJECTION,PARALLEL_PROJECTION} _projection_type;
    //Enum para el modo de dibujado pero que no se utiliza
    typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
     //Enum para el nombre de los objetos del proyecto
    typedef enum {OBJECT_VACIO, OBJECT_TETRAHEDRON,OBJECT_CUBE, OBJECT_PLY_MENU1, OBJECT_PLY_MENU2, OBJECT_PLY_MENU3, OBJECT_PLY_MENU4, OBJECT_PLY_MENU5, OBJECT_MATRIZ, OBJECT_PLY, OBJECT_CILINDRO, OBJECT_CONO, OBJECT_ESFERA, OBJECT_PLY_PERFIL, OBJECT_HIERARCHICAL, OBJECT_TABLERO} _object;

}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget{

    Q_OBJECT
    public:

      //Constructor
      _gl_widget(_window *Window1);

      //(DADA) Funcion que limpia la ventana
      void clear_window();
      //(DADA) Funcion que cambia el modo de proyeccion
      void change_projection();
      //(DADA) Funcion que cambia la vision del observador
      void change_observer();
      //(DADA) Funcion que pinta los ejes (no esta implementada, se pintan con Axis.draw_line() en glwidget.cc)
      void draw_axis();
      //(DADA) Funcion que pinta los objetos
      void draw_objects();

    protected:
      //Para la seleccion de un triangulo del objeto
      void pick();
      //Para inicializar la imagen de la textura (practica 4)
      void inicializarTexturas();
      //(DADA) Reajusta el tamanio de la ventana
      void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
      //(DADA) limpia la ventana, cambia las proyecciones y vistas y llama a la funcion de pintado
      void paintGL() Q_DECL_OVERRIDE;
      //(DADA) Inicializa todos los atributos de glwidget
      void initializeGL() Q_DECL_OVERRIDE;
      //(DADA) Recibe una tecla como entrada y realiza una accion
      void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
      //Accion de mover el raton, usada para mover la camara
      void mouseMoveEvent(QMouseEvent *evento) override;
      //Accion de rotar la rueda del raton, usada para el zoom
      void wheelEvent(QWheelEvent *evento) override;
      //Accion de pulsar con el raton (cualquiera de los botones que se espcifique), usada para pick
      void mousePressEvent(QMouseEvent *evento) override;
      //Accion de soltar un boton del raton (cualquiera de los botones que se espcifique), usada para pick
      void mouseReleaseEvent(QMouseEvent *Event) override;
      //Para mover la camara desde donde queramos a donde queramos
      void transformar_camara(float x_posicion, float y_posicion,float z_posicion,float x_objetivo, float y_objetivo,float z_objetivo, float u_x, float u_y, float u_z);

    //Funciones para los slots (asociadas a los widgets de la interfaz)
    public slots:
        void puntos_cb_slot(int State);         //Checkbox para pintar los puntos
        void lineas_cb_slot(int State);         //Checkbox para pintar las lineas
        void fill_cb_slot(int State);           //Checkbox para pintar modo fill
        void chess_cb_slot(int State);          //Checkbox para pintar modo chess
        void tetra_cb_slot(int State);          //Checkbox para pintar el tetraedro
        void cubo_cb_slot(int State);           //Checkbox para pintar el cubo
        void cono_cb_slot(int State);           //Checkbox para pintar el cono
        void cilindro_cb_slot(int State);       //Checkbox para pintar el cilindro
        void esfera_cb_slot(int State);         //Checkbox para pintar la esfera
        void hierarchical_cb_slot(int State);   //Checkbox para pintar la figura jerarquica
        void ply_perfil_cb_slot(int State);     //Checkbox para pintar el ply_perfil
        void ply_cb_slot(int State);            //Checkbox para pintar el ply
        void tablero_cb_slot(int State);        //Checkbox para pintar el tablero
        void matriz_cb_slot(int State);         //Checkbox para pintar la matriz
        void solid_cb_slot(int State);          //Checkbox para pintar en modo solido
        void textura_cb_slot(int State);        //Checkbox para pintar en modo textura
        void flat_cb_slot(int State);           //Checkbox para pintar en modo flat
        void smooth_cb_slot(int State);         //Checkbox para pintar en modo smooth
        void flat_textura_cb_slot(int State);   //Checkbox para pintar en modo flat con textura
        void smooth_textura_cb_slot(int State); //Checkbox para pintar en modo smooth con textura
        void luz_blanca_cb_slot(int State);     //Checkbox para encender la luz blanca
        void luz_magenta_cb_slot(int State);    //Checkbox para encender la luz magenta
        void frustrum_cb_slot(int State);       //Checkbox para poner la proyeccion perspectiva
        void orthogonal_cb_slot(int State);     //Checkbox para poner la proyeccion paralela
        void leerCombobox(int State);           //Listado de plys para seleccionar
        void materiales();                      //Funcion que cambia los materiales al pulsar su boton en la interfaz

    //Funcion accionada al activar el QTimer que llamara al resto de animaciones de la figura
    void animacion();
        void animacion_puerta();            //Abre y cierra las puertas
        void animacion_pala();              //Vacia y llena la pala
        void animacion_ventanilla();        //Baja y sube las ventanillas
        void animacion_quitanieves();       //Sube y baja el quitanieves
        void animacion_estira_quitanieves();//Estira y encoge el quitanieves
        void animacion_codo();              //Amplia y encoge la apertura del brazo por el codo
        void animacion_brazo();             //Sube y baja el brazo completo por la union con el resto de figura
        void animacion_entero();            //Mueve el objeto entero hacia denlante y atras y rota las ruedas en concordancia
        void animacion_luz();               //Rota la luz alrededor del objeto


    private:

      _window *Window;  //Ventana
      _axis Axis;       //Ejes

      //Objetos basicos
      _tetrahedron Tetrahedron;
      _cube Cube=_cube(1);
      _cilindro Cilindro = _cilindro(20,2,1,3); //_cilindro(rotaciones, eje (x:1, y:2, z:3), tamanio, tapaderas a mostrar)
      _cono Cono = _cono(20,2,1,3);             //_cono(rotaciones, eje (x:1, y:2, z:3), tamanio, tapaderas a mostrar)
      _esfera Esfera = _esfera(100,2,1,20,3);   //_esfera(rotaciones, eje (x:1, y:2, z:3), tamanio, puntos en el perfil, tapaderas a mostrar)

      //PLY's
      _ply Ply = _ply(" ");    //Inicializo a vacio originalmente
          _ply Ply_menu_1 = _ply(" "); //Para el combobox, primer objeto
          _ply Ply_menu_2 = _ply(" "); //Para el combobox, segundo objeto
          _ply Ply_menu_3 = _ply(" "); //Para el combobox, tercer objeto
          _ply Ply_menu_4 = _ply(" "); //Para el combobox, cuarto objeto
          _ply Ply_menu_5 = _ply(" "); //Para el combobox, quinto objeto
      _ply_perfil PlyPerfil = _ply_perfil(" "); //Inicializo a vacio originalmente

      //Objeto de la jerarquia
      _hierarchical Grua ;

      //Tablero para las texturas
      _tablero tablero =  _tablero(1);

      //Matriz de objeto para la practica 5 (seleccion de un objeto en otro color)
      _matriz_ply matriz = _matriz_ply();

      //Luces practica 5. Excepto estas dos, el resto (0-7) tiene valores por defecto
      _lighting luz0 = _lighting(0);    //La 0 es la blanca
      _lighting luz1 =  _lighting(1);   //La 1 es la magenta

      //Material para ver la luz
      _material material = _material();

      _gl_widget_ne::_object Object;
      _gl_widget_ne::_object Object_antiguo;


      //Booleanos que controlan el modo de dibujado activado
      bool Draw_solid;      //Para los solidos (F1, F2, F3...)
      bool Draw_point;      //Puntos
      bool Draw_line;       //Lineas
      bool Draw_fill;       //Fill (relleno)
      bool Draw_chess;      //Chess (modo ajedrez)
      bool Draw_textura;    //Textura (practica 4)

      //Para saber si la animacion esta activa o no
      bool Animation = false;

      //Booleanos sobre las luces
      bool luz_activada=false;  //Activa o desactiva la luz en general
      bool interruptor0=false;  //Activa o desactiva la luz0
      bool interruptor1=false;  //Activa o desactiva la luz1
          //booleanos del modo de luz para ver la superficie de los objetos y la luz.
          bool flat=false;   //para la luz plana
          bool smooth=false; //para la luz suave

      //booleanos del modo de luz para verlo con la textura
      bool flat_textura=false;   //para la luz plana
      bool smooth_textura=false; //para la luz suave

      //Como la luz magenta tiene que rotar alrededor del objeto, creamos los angulos para controlar la rotacion
      float angx_luz1=0;//Angulo de la luz 1 en el eje x
      float angy_luz1=0;//Angulo de la luz 1 en el eje y
      float angz_luz1=0;//Angulo de la luz 1 en el eje z

      //Para permitir cambiar las 3 texturas consecutivas
      int contador_color=0;

      //PRACTICA 5 CAMARA
      //Guardan la posicion para que al mover la camara con el raton, tras soltar y volver al pulsar no pierda la continuidad
      //Los difx y dify contienen la diferencia entre la ultima posicion del raton y la nueva, que sera cuanto movamos el objeto
      int savedx = 0, difx = 0;
      int savedy = 0, dify = 0;

      int Selection_position_x; //Guarda la coordenada x en el pick al pulsar un pixel
      int Selection_position_y; //Guarda la coordenada y en el pick al pulsar un pixel
      int Window_width;         //Ancho de la ventana principal
      int Window_height;        //Alto de la ventana principal
      float Scale_factor;       //Para que al reducir y ampliar la vista con el zoom en la proyeccion ortoginal se mantenga que el
                                //campo de vision es un cuadrado, es por ello que se multiplica despues por cada amplitud de la camara

      int Selected_triangle;    //Guarda la posicion del triangulo seleccionado
      int Selected_triangle_aux;//Guarda la posicion del anterior triangulo seleccionado, por si pulsas el mismo que seleccionaste, deseleccionarlo

      //(DADO) Para el pick
      GLuint FBO;
      GLuint Color_texture;
      GLuint Depth_texture;

      _gl_widget_ne::_projection_type Projection_type;

      //Creacion de Qtimer para las animaciones
      QTimer *timer_animacion = new QTimer;

      //Atributos para la posicion del observador. Se cambian con las flechas del teclado
      float Observer_angle_x;
      float Observer_angle_y;
      //Distancia del observador, se modifica con el zoom
      float Observer_distance;


      //Para que el brazo de la grua se estire y se encoja [agarre_quitanieves.cc] [excavadora_quitanieves.cc]
      float libertad_estirar_quitanieves = 0;
      float velocidad_estirar_quitanieves = 0.1;
            bool estirando_agarre_quitanieves = false; //Si el codo se esta estirando
            bool encogiendo_agarre_quitanieves = false; //Si el codo se esta estirando
            bool agarre_quitanieves_fin = false; //Si el codo ha terminado

      //Para que el brazo de la grua se estire y se encoja [brazo.cc] [excavadora.cc]
      float libertad_codo_brazo = 45;
      float velocidad_codo_brazo = 0.5;
            bool abriendo_codo = false; //Si el codo se esta estirando
            bool cerrando_codo = false; //Si el codo se esta estirando
            bool codo_fin = false; //Si el codo ha terminado

      //Para que la pala se mueva sin mover el brazo [grua.cc]
      float libertad_pala = 0;
      float velocidad_pala = 0.5;
              bool vaciando_pala = false; //Si la pala esta retrocediendo
              bool llenando_pala = false; //Si la pala esta avanzando hacia la figura
              bool pala_fin = false; //Si la pala ha terminado

      //Para que el brazo y la pala suban y bajen rotando sobre el punto de apoyo en el coche [excavadora.cc]
      float libertad_brazo_entero = 0;
      float velocidad_brazo_entero = 0.5;
              bool subiendo_brazo = false; //Si el brazo esta subiendo entero
              bool bajando_brazo = false; //Si el brazo esta bajando entero
              bool brazo_fin = false; //Si el brazo ha terminado

      //Para que suba y baje el quitanieves de delante [excavadora_quitanieves.cc]
      float libertad_quitanieves = 0;
      float velocidad_quitanieves = 0.5;
              bool subiendo_quitanieves = false; //esta subiendo el quitanieves
              bool bajando_quitanieves = false; //se esta bajando
              bool quitanieves_fin = false ; //ha terminado su animacion

      //Para que se abran y cierren las puertas [sistema_puertasventanilla.cc]
      float libertad_puerta = 0;
      float velocidad_puerta = 0.5;
              bool abriendo_puerta = true; //se esta abriendo
              bool puerta_fin = false ; //ha terminado su animacion

      //Para que suban y bajen las ventanillas [puerta_ventanilla.cc]
      float libertad_ventanilla = 0;
      float velocidad_ventanilla = 0.005;
              bool bajando_ventanilla = false; //esta bajando la ventanilla
              bool ventanilla_fin = false; //ventanilla ha terminado

      //Para que la figura entera avance y giren las ruedas [sistema_ruedas.cc][hierarchical.cc]
      float libertad_entero = 0;
      float velocidad_entero = 0.05;
              bool avanzando_entero = false;        //la figura entera avanza
              bool retrocediendo_entero = false;    //la figura entera retrocede
              bool entero_fin = false;              //la figura entera ha terminado de moverse


};

#endif
