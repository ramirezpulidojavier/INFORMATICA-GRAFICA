/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDialog>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGuiApplication>
#include <QCheckBox>
#include <QPushButton>

#include "glwidget.h"

class _gl_widget;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _window : public QMainWindow
{
    Q_OBJECT

public:
    _window();
    //Cambia los checkboxs de la forma de pintado al pulsar unos u otros
    void cambiarcheckbox_pintado(int tecla);
    //Cambia los checkboxs de los objetos a pintar al pulsar unos u otros
    void cambiarcheckbox_objeto(_gl_widget_ne::_object objeto, _gl_widget_ne::_object objeto_antiguo);

private:
  _gl_widget *GL_widget;
  QCheckBox *puntos_cb = new QCheckBox;
  QCheckBox *lineas_cb = new QCheckBox;
  QCheckBox *fill_cb = new QCheckBox;
  QCheckBox *chess_cb = new QCheckBox;
  QCheckBox *tetra_cb = new QCheckBox;
  QCheckBox *cubo_cb = new QCheckBox;
  QCheckBox *cilindro_cb = new QCheckBox;
  QCheckBox *cono_cb = new QCheckBox;
  QCheckBox *esfera_cb = new QCheckBox;
  QCheckBox *hierarchical_cb = new QCheckBox;
  QCheckBox *ply_perfil_cb = new QCheckBox;
  QCheckBox *ply = new QCheckBox;
  QCheckBox *tablero = new QCheckBox;
  QCheckBox *matriz = new QCheckBox;
  QCheckBox *solid = new QCheckBox;
  QCheckBox *textura = new QCheckBox;
  QCheckBox *flat = new QCheckBox;
  QCheckBox *smooth = new QCheckBox;
  QCheckBox *flat_textura = new QCheckBox;
  QCheckBox *smooth_textura = new QCheckBox;
  QCheckBox *luz_blanca = new QCheckBox;
  QCheckBox *luz_magenta = new QCheckBox;
  QCheckBox *frustrum = new QCheckBox;
  QCheckBox *orthogonal = new QCheckBox;
  QPushButton *materiales = new QPushButton;

};

#endif
