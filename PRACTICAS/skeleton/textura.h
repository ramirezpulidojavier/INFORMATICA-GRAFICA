#include "stdlib.h"
#include "stdio.h"
#include <ctype.h>
#include <QImage>
#include <iostream>
#include "object3d.h"
#include "tablero.h"

#ifndef TEXTURA_H
#define TEXTURA_H


class _textura :public _object3D
{
private:
    QImage Imagen;
    int ntot;



public:
    _textura(int tam);
    void cargarTablero(int nfilcol);
    void activarT1(const string &File_name);
    void activarT2(const string &File_name);
    void activarT3(const string &File_name);

};

#endif // TEXTURA_H
