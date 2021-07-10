/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QFrame>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QTimer>

#include "window.h"
#include "glwidget.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_window::_window()
{

    QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);

   //Creamos un widget central (el principal) y lo ponemos con el set
   QWidget *Central_widget = new QWidget(this);
   setCentralWidget(Central_widget);

   //Ponemos un titulo a la ventana
   setWindowTitle(tr("Prácticas IG Javier Ramirez"));

   //Redimensionamos la ventana
   resize(800,800);

   //Definimos el puntero que creamos en el .h
   GL_widget = new _gl_widget(this);
   GL_widget->setSizePolicy(Q);


   //Creamos el layout horizontal
   QHBoxLayout *horizontal_layout = new QHBoxLayout;

   //Asignamos el layout creado al widget central
   Central_widget -> setLayout(horizontal_layout);

   //Creamos el widget de las pestanias de la derecha
   QTabWidget *pestanias = new QTabWidget;
   pestanias -> setMaximumWidth(200); //le damos un ancho maximo

   //Aniadimos al layout horizontal el glwidget de toda la practica
   horizontal_layout->addWidget(GL_widget);

   //Le añadimos a la derecha las petanias que queremos
   horizontal_layout -> addWidget(pestanias);

   //Creamos los widgets que llevaran las pestanias
   QWidget *visualization_widget = new QWidget;
   QWidget *objetos_widget = new QWidget;

   //Los aniadimos a pestanias
   pestanias->addTab(visualization_widget, "Visualizacion");
   pestanias->addTab(objetos_widget, "Objetos");

   //Nueva layout para la pestania de los MODOS
   QGridLayout *gridLayout_visualization = new QGridLayout;

   //Layout vertical para la distribucion del nombre de los modelos
   QVBoxLayout *visualization_layout = new QVBoxLayout;

   //Nueva layout para la pestania de los OBJETOS
   QGridLayout *gridLayout_objetos = new QGridLayout;

   //Layout vertical para la distribucion del nombre de los objetos
   QVBoxLayout *objects_layout = new QVBoxLayout;

   //Layout para la pestanias de PLY de los OBJETOS
   QGridLayout *ply_visualization = new QGridLayout;

   //PESTANIA DE MODOS

   //Creamos labels para dar nombre a los checbox
   QLabel *lineas_label = new QLabel("Lineas (L)");
   QLabel *puntos_label = new QLabel("Puntos (P)");
   QLabel *fill_label = new QLabel("Fill (F1)");
   QLabel *chess_label = new QLabel("Chess  (F2)");


   gridLayout_visualization->addWidget(lineas_cb,0,0,Qt::AlignLeft); //primero checkbox
   QPixmap pixLineas ("./icons/lineas_javi.png");
   lineas_label->setPixmap(pixLineas);
   gridLayout_visualization->addWidget(lineas_label,0,1); //debajo su label

   gridLayout_visualization->addWidget(puntos_cb,1,0,Qt::AlignLeft); //checkbox
   QPixmap pixPuntos ("./icons/puntos_javi.png");
   puntos_label->setPixmap(pixPuntos);
   gridLayout_visualization->addWidget(puntos_label,1,1); //debajo su label...

   gridLayout_visualization->addWidget(fill_cb,2,0,Qt::AlignLeft);
   QPixmap pixFill ("./icons/fill_javi.png");
   fill_label->setPixmap(pixFill);
   gridLayout_visualization->addWidget(fill_label,2,1);

   gridLayout_visualization->addWidget(chess_cb,3,0,Qt::AlignLeft);
   QPixmap pixChess ("./icons/chess_javi.png");
   chess_label->setPixmap(pixChess);
   gridLayout_visualization->addWidget(chess_label,3,1);



   //Widget auxiliar para poder hacer el stretch que con un gridLayout no se puede
   QGroupBox *vis_aux = new QGroupBox("Modelos");

   vis_aux->setLayout(gridLayout_visualization);

   visualization_layout->addWidget(vis_aux);
   visualization_layout->addStretch(); //quitamos huecos de por medio

   visualization_widget->setLayout(visualization_layout);


   //Vamos a indicar que por defecto el checkbox de lineas esta marcado
   //lineas_cb -> setCheckState(Qt::Checked);


   //PESTANIA DE OBJETOS


   //Creamos labels para dar nombre a los checbox
   QLabel *tetra_label = new QLabel("Tetraedro (1)");
   QLabel *cubo_label = new QLabel("Cubo (2)");
   QLabel *cilindro_label = new QLabel("Cilindro (4)");
   QLabel *cono_label = new QLabel("Cono (3)");
   QLabel *esfera_label = new QLabel("Esfera (5)");
   QLabel *hierarchical_label = new QLabel("Hierarchical (7)");
   QLabel *ply_perfil_label = new QLabel("PLY con perfil (9)");

   QLabel *ply_label = new QLabel("Ply (6)");
   QLabel *matriz_label = new QLabel("Matriz (9)");
   QLabel *tablero_label = new QLabel("Tablero (8)");
   QLabel *textura_label = new QLabel("Textura (F5)");
   QLabel *solid_label = new QLabel("Solid (F)");
   QLabel *flat_label = new QLabel("Flat (F3)");
   QLabel *smooth_label = new QLabel("Smooth (F4)");
   QLabel *flat_textura_label = new QLabel("Textura con Flat (F6)");
   QLabel *smooth_textura_label = new QLabel("Tex. con Smooth (F7)");
   QLabel *luz_blanca_label = new QLabel("Luz Blanca (J)");
   QLabel *luz_magenta_label = new QLabel("Luz Magenta (K)");
   QLabel *frustrum_label = new QLabel("Proy. Perspectiva (C)");
   QLabel *orthogonal_label = new QLabel("Proy. ortogonal (V)");

   gridLayout_visualization->addWidget(textura,4,0,Qt::AlignLeft); //primero checkbox
//    QPixmap pixTextura ("./icons/ply_javi.png");
//   textura_label->setPixmap(pixTextura);
   gridLayout_visualization->addWidget(textura_label,4,1); //debajo su label

   gridLayout_visualization->addWidget(solid,5,0,Qt::AlignLeft); //primero checkbox
//    QPixmap pixSolid ("./icons/solid_javi.png");
//   solid_label->setPixmap(pixSolid);
   gridLayout_visualization->addWidget(solid_label,5,1); //debajo su label

   gridLayout_visualization->addWidget(flat,6,0,Qt::AlignLeft); //primero checkbox
//    QPixmap pixFlat ("./icons/flat_javi.png");
//   flat_label->setPixmap(pixFlat);
   gridLayout_visualization->addWidget(flat_label,6,1); //debajo su label

   gridLayout_visualization->addWidget(smooth,7,0,Qt::AlignLeft); //primero checkbox
//    QPixmap pixSmooth ("./icons/smooth_javi.png");
//   smooth_label->setPixmap(pixSmooth);
   gridLayout_visualization->addWidget(smooth_label,7,1); //debajo su label

   gridLayout_visualization->addWidget(flat_textura,8,0,Qt::AlignLeft); //primero checkbox
//    QPixmap pixFlat_textura ("./icons/flat_textura_javi.png");
//   flat_textura_label->setPixmap(pixFlat_textura);
   gridLayout_visualization->addWidget(flat_textura_label,8,1); //debajo su label

   gridLayout_visualization->addWidget(smooth_textura,9,0,Qt::AlignLeft); //primero checkbox
//    QPixmap pixSmooth_textura ("./icons/smooth_textura_javi.png");
//   Smooth_textura_label->setPixmap(pixSmooth_textura);
   gridLayout_visualization->addWidget(smooth_textura_label,9,1); //debajo su label

   gridLayout_visualization->addWidget(luz_blanca,10,0,Qt::AlignLeft); //primero checkbox
   QPixmap pixluz_blanca ("./icons/luz_blanca_javi.png");
   luz_blanca_label->setPixmap(pixluz_blanca);
   gridLayout_visualization->addWidget(luz_blanca_label,10,1); //debajo su label

   gridLayout_visualization->addWidget(luz_magenta,11,0,Qt::AlignLeft); //primero checkbox
   QPixmap pixluz_magenta ("./icons/luz_magenta_javi.png");
   luz_magenta_label->setPixmap(pixluz_magenta);
   gridLayout_visualization->addWidget(luz_magenta_label,11,1); //debajo su label

   gridLayout_visualization->addWidget(frustrum,12,0,Qt::AlignLeft); //primero checkbox
   gridLayout_visualization->addWidget(frustrum_label,12,1); //debajo su label

   gridLayout_visualization->addWidget(orthogonal,13,0,Qt::AlignLeft); //primero checkbox
   gridLayout_visualization->addWidget(orthogonal_label,13,1); //debajo su label






   //Creamos checkbox para modos lineas y puntos y lo aniadimos al layout



   gridLayout_objetos->addWidget(tetra_cb,0,0,Qt::AlignLeft); //primero checkbox
   QPixmap mypix ("./icons/tetra_javi.png");
   tetra_label->setPixmap(mypix);
   gridLayout_objetos->addWidget(tetra_label,0,1); //debajo su label


   gridLayout_objetos->addWidget(cubo_cb,1,0,Qt::AlignLeft); //checkbox
   QPixmap mypix2 ("./icons/cubo_javi.png");
   cubo_label->setPixmap(mypix2);
   gridLayout_objetos->addWidget(cubo_label,1,1); //debajo su label...

   gridLayout_objetos->addWidget(cono_cb,2,0,Qt::AlignLeft);
   QPixmap mypix3 ("./icons/cono_javi.png");
   cono_label->setPixmap(mypix3);
   gridLayout_objetos->addWidget(cono_label,2,1);

   gridLayout_objetos->addWidget(cilindro_cb,3,0,Qt::AlignLeft);
   QPixmap mypix4 ("./icons/cilindro_javi.png");
   cilindro_label->setPixmap(mypix4);
   gridLayout_objetos->addWidget(cilindro_label,3,1);

   gridLayout_objetos->addWidget(esfera_cb,4,0,Qt::AlignLeft);
   QPixmap mypix5 ("./icons/esfera_javi.png");
   esfera_label->setPixmap(mypix5);
   gridLayout_objetos->addWidget(esfera_label,4,1);

   gridLayout_objetos->addWidget(ply,5,0,Qt::AlignLeft);
   QPixmap mypixply ("./icons/ply_javi.png");
   ply_label->setPixmap(mypixply);
   gridLayout_objetos->addWidget(ply_label,5,1);

   gridLayout_objetos->addWidget(hierarchical_cb,6,0,Qt::AlignLeft);
   QPixmap mypix6 ("./icons/jerarquia_javi.png");
   hierarchical_label->setPixmap(mypix6);
   gridLayout_objetos->addWidget(hierarchical_label,6,1);

   gridLayout_objetos->addWidget(tablero,7,0,Qt::AlignLeft);
   QPixmap mypixtablero ("./icons/tablero_javi.png");
   tablero_label->setPixmap(mypixtablero);
   gridLayout_objetos->addWidget(tablero_label,7,1);

   gridLayout_objetos->addWidget(ply_perfil_cb,8,0,Qt::AlignLeft);
   gridLayout_objetos->addWidget(ply_perfil_label,8,1);

   gridLayout_objetos->addWidget(matriz,9,0,Qt::AlignLeft);
   QPixmap mypixmatriz ("./icons/matriz_javi.png");
   matriz_label->setPixmap(mypixmatriz);
   gridLayout_objetos->addWidget(matriz_label,9,1);



   //Widget auxiliar para poder hacer el stretch que con un gridLayout no se puede
   QGroupBox *obj_aux = new QGroupBox("Objetos");

   obj_aux->setLayout(gridLayout_objetos);

   objects_layout->addWidget(obj_aux);

   objetos_widget->setLayout(objects_layout);


   //Vamos a crear una lista con los PLY para seleccionarlos mas facilemente
   QGroupBox *grupo_ply = new QGroupBox("PLY");
   QComboBox *lista_ply = new QComboBox;

   grupo_ply->setLayout(ply_visualization); //aniadimos el grupo al layout de modos
   objects_layout->addWidget(grupo_ply);
   ply_visualization->addWidget(lista_ply); //aniadimos la lista dentro del layout nuevo que hemos creado
   objects_layout->addStretch();


   //Aniadimos los elementos a la lista
   lista_ply->addItem("Vacio");
   lista_ply->addItem("Beethoven");
   lista_ply->addItem("Hormiga");
   lista_ply->addItem("Big Dodge");
   lista_ply->addItem("Sandalia");
   lista_ply->addItem("Vaca");


   //Acciones para el menu "File"
   QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
   Exit->setShortcut(tr("Ctrl+Q"));
   Exit->setToolTip(tr("Exit the application"));
   connect(Exit, SIGNAL(triggered()), this, SLOT(close()));

   //Menus
   QMenu *File_menu = menuBar()->addMenu(tr("&File"));
   File_menu->addAction(Exit);
   File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

   //Conectar combobox
   connect(lista_ply, SIGNAL(currentIndexChanged(int)), GL_widget, SLOT(leerCombobox(int)));

   connect(tetra_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(tetra_cb_slot(int)));
   connect(cubo_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(cubo_cb_slot(int)));
   connect(cono_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(cono_cb_slot(int)));
   connect(cilindro_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(cilindro_cb_slot(int)));
   connect(esfera_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(esfera_cb_slot(int)));
   connect(hierarchical_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(hierarchical_cb_slot(int)));
   connect(ply_perfil_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(ply_perfil_cb_slot(int)));
   connect(puntos_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(puntos_cb_slot(int)));
   connect(lineas_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(lineas_cb_slot(int)));
   connect(fill_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(fill_cb_slot(int)));
   connect(chess_cb, SIGNAL(stateChanged(int)), GL_widget, SLOT(chess_cb_slot(int)));

   frustrum->setChecked(true);

   connect(ply, SIGNAL(stateChanged(int)), GL_widget, SLOT(ply_cb_slot(int)));
   connect(tablero , SIGNAL(stateChanged(int)), GL_widget, SLOT(tablero_cb_slot(int)));
   connect(matriz, SIGNAL(stateChanged(int)), GL_widget, SLOT(matriz_cb_slot(int)));
   connect(solid, SIGNAL(stateChanged(int)), GL_widget, SLOT(solid_cb_slot(int)));
   connect(textura, SIGNAL(stateChanged(int)), GL_widget, SLOT(textura_cb_slot(int)));
   connect(flat, SIGNAL(stateChanged(int)), GL_widget, SLOT(flat_cb_slot(int)));
   connect(smooth, SIGNAL(stateChanged(int)), GL_widget, SLOT(smooth_cb_slot(int)));
   connect(flat_textura, SIGNAL(stateChanged(int)), GL_widget, SLOT(flat_textura_cb_slot(int)));
   connect(smooth_textura, SIGNAL(stateChanged(int)), GL_widget, SLOT(smooth_textura_cb_slot(int)));
   connect(luz_blanca, SIGNAL(stateChanged(int)), GL_widget, SLOT(luz_blanca_cb_slot(int)));
   connect(luz_magenta, SIGNAL(stateChanged(int)), GL_widget, SLOT(luz_magenta_cb_slot(int)));
   connect(frustrum, SIGNAL(stateChanged(int)), GL_widget, SLOT(frustrum_cb_slot(int)));
   connect(orthogonal, SIGNAL(stateChanged(int)), GL_widget, SLOT(orthogonal_cb_slot(int)));
   connect(materiales, SIGNAL(released()), GL_widget, SLOT(materiales()));

   QLabel *material_label = new QLabel("Material");

   gridLayout_visualization->addWidget(materiales,14,0,Qt::AlignLeft);
   gridLayout_visualization->addWidget(material_label,14,1);

//-----------------------------------------------------------------------------------------------------------
//   QTimer *mi_timer2 = new QTimer;
//   mi_timer2->start(5); //el numero de milisegundos antes de que haga una accion
//   connect(mi_timer2, SIGNAL(timeout()), GL_widget, SLOT( animacion_limpiaparabrisas()));

//   QTimer *mi_timer3 = new QTimer;
//   mi_timer3->start(100); //el numero de milisegundos antes de que haga una accion
//   connect(mi_timer3, SIGNAL(timeout()), GL_widget, SLOT( animacion_ventanilla()));

//   QTimer *mi_timer4 = new QTimer;
//   mi_timer4->start(20); //el numero de milisegundos antes de que haga una accion
//   connect(mi_timer4, SIGNAL(timeout()), GL_widget, SLOT( animacion_pendulo()));

//   QTimer *mi_timer5 = new QTimer;
//   mi_timer5->start(100); //el numero de milisegundos antes de que haga una accion
//   connect(mi_timer5, SIGNAL(timeout()), GL_widget, SLOT( animacion_bolacuerda()));

//   QTimer *mi_timer6 = new QTimer;
//   mi_timer6->start(30); //el numero de milisegundos antes de que haga una accion
//   connect(mi_timer6, SIGNAL(timeout()), GL_widget, SLOT( animacion_mastil()));

//   QTimer *mi_timer7 = new QTimer;
//   mi_timer7->start(100); //el numero de milisegundos antes de que haga una accion
//   connect(mi_timer7, SIGNAL(timeout()), GL_widget, SLOT( animacion_mov_camion()));
//-----------------------------------------------------------------------------------------------------------



}

void _window::cambiarcheckbox_objeto(_gl_widget_ne::_object objeto, _gl_widget_ne::_object objeto_antiguo){

    tetra_cb->setChecked(false);
    cubo_cb->setChecked(false);
    cono_cb->setChecked(false);
    cilindro_cb->setChecked(false);
    esfera_cb->setChecked(false);
    hierarchical_cb->setChecked(false);
    ply_perfil_cb->setChecked(false);
    ply->setChecked(false);
    tablero->setChecked(false);
    matriz->setChecked(false);

    if(objeto != objeto_antiguo)
        switch (objeto){
            case _gl_widget_ne::OBJECT_TETRAHEDRON:tetra_cb->setChecked(true);break;
            case _gl_widget_ne::OBJECT_CUBE:cubo_cb->setChecked(true);break;
            case _gl_widget_ne::OBJECT_PLY:ply->setChecked(true);break;
            case _gl_widget_ne::OBJECT_CILINDRO:cilindro_cb->setChecked(true);break;
            case _gl_widget_ne::OBJECT_CONO:cono_cb->setChecked(true);break;
            case _gl_widget_ne::OBJECT_ESFERA:esfera_cb->setChecked(true);break;
            case _gl_widget_ne::OBJECT_PLY_PERFIL:ply_perfil_cb->setChecked(true);break;
            case _gl_widget_ne::OBJECT_TABLERO:tablero->setChecked(true);break;
            case _gl_widget_ne::OBJECT_MATRIZ:matriz->setChecked(true);break;
            case _gl_widget_ne::OBJECT_HIERARCHICAL:hierarchical_cb->setChecked(true);break;
            default:break;
        }



}

void _window::cambiarcheckbox_pintado(int tecla){


    switch(tecla){

            case Qt::Key_P:if(puntos_cb->checkState())puntos_cb->setChecked(false); else puntos_cb->setChecked(true); break;
            case Qt::Key_L:if(lineas_cb->checkState())lineas_cb->setChecked(false); else lineas_cb->setChecked(true); break;
            case Qt::Key_F:

                if(solid->checkState()){

                    solid->setChecked(false);
                    fill_cb->setChecked(false);
                    chess_cb->setChecked(false);
                    flat->setChecked(false);
                    smooth->setChecked(false);
                    flat_textura->setChecked(false);
                    smooth_textura->setChecked(false);
                    textura->setChecked(false);
                    luz_blanca->setChecked(false);
                    luz_magenta->setChecked(false);
                }

                else
                    solid->setChecked(true);

            break;

            case Qt::Key_F1:
                if(solid->checkState() && !fill_cb->checkState()){
                    chess_cb->setChecked(false);
                    textura->setChecked(false);
                    flat_textura->setChecked(false);
                    smooth_textura->setChecked(false);
                    fill_cb->setChecked(true);

                }
                else
                    fill_cb->setChecked(false);

            break;

            case Qt::Key_F2:
                if(solid->checkState() && !chess_cb->checkState()){
                    fill_cb->setChecked(false);
                    textura->setChecked(false);
                    flat_textura->setChecked(false);
                    smooth_textura->setChecked(false);
                    chess_cb->setChecked(true);

                }
                else
                    chess_cb->setChecked(false);
            break;

            case Qt::Key_F3:
                if(solid->checkState() && !flat->checkState()){
                    smooth->setChecked(false);
                    textura->setChecked(false);
                    flat_textura->setChecked(false);
                    smooth_textura->setChecked(false);
                    flat->setChecked(true);
                }
                else{
                    flat->setChecked(false);
                    luz_blanca->setChecked(false);
                    luz_magenta->setChecked(false);
                }

            break;
            case Qt::Key_F4:
                if(solid->checkState() && !smooth->checkState()){
                    flat->setChecked(false);
                    textura->setChecked(false);
                    flat_textura->setChecked(false);
                    smooth_textura->setChecked(false);
                    smooth->setChecked(true);

                }
                else{
                    smooth->setChecked(false);
                    luz_blanca->setChecked(false);
                    luz_magenta->setChecked(false);
                }
            break;

            case Qt::Key_F5:
                if(solid->checkState() && !textura->checkState()){
                    fill_cb->setChecked(false);
                    chess_cb->setChecked(false);
                    flat->setChecked(false);
                    smooth->setChecked(false);
                    smooth_textura->setChecked(false);
                    flat_textura->setChecked(false);
                    luz_blanca->setChecked(false);
                    luz_magenta->setChecked(false);
                    textura->setChecked(true);

                }
                else
                    textura->setChecked(false);
            break;

            case Qt::Key_F6:
                if(solid->checkState() && !flat_textura->checkState()){
                    fill_cb->setChecked(false);
                    chess_cb->setChecked(false);
                    smooth_textura->setChecked(false);
                    flat->setChecked(false);
                    smooth->setChecked(false);
                    textura->setChecked(false);
                    flat_textura->setChecked(true);
                }
                else{
                    luz_blanca->setChecked(false);
                    luz_magenta->setChecked(false);
                    flat_textura->setChecked(false);
                }
            break;

            case Qt::Key_F7:
                if(solid->checkState() && !smooth_textura->checkState()){
                    fill_cb->setChecked(false);
                    chess_cb->setChecked(false);
                    flat_textura->setChecked(false);
                    flat->setChecked(false);
                    smooth->setChecked(false);
                    textura->setChecked(false);
                    smooth_textura->setChecked(true);


                }
                else{
                    smooth_textura->setChecked(false);
                    luz_blanca->setChecked(false);
                    luz_magenta->setChecked(false);

                }
            break;

            case Qt::Key_J:
                if((flat->checkState() || smooth->checkState() || flat_textura->checkState() || smooth_textura->checkState())  && !luz_blanca->checkState()){
                    luz_blanca->setChecked(true);
                }
                else
                    luz_blanca->setChecked(false);
            break;


            case Qt::Key_K:
                if((flat->checkState() || smooth->checkState() || flat_textura->checkState() || smooth_textura->checkState())  && !luz_magenta->checkState()){
                    luz_magenta->setChecked(true);
                }
                else
                    luz_magenta->setChecked(false);
            break;

            case Qt::Key_C:

                frustrum->setChecked(false);
                orthogonal->setChecked(true);

                    if (orthogonal->checkState()){
                        frustrum->setChecked(true);
                        orthogonal->setChecked(false);
                    }

            break;

            case Qt::Key_V:
                if (frustrum->checkState()){
                    frustrum->setChecked(false);
                    orthogonal->setChecked(true);
                }

            break;

        }

}
