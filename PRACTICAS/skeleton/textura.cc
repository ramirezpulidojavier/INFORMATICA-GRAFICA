#include "textura.h"

_textura::_textura(int tam)
{
    cargarTablero(tam);
    ntot=tam;
}

void _textura::cargarTablero( int nfilcol){

     Vertices.resize((nfilcol+1)*(nfilcol+1));
     t.Vertices.resize((nfilcol+1)*(nfilcol+1));
     int n=0;

     for (int i=0; i < nfilcol+1; i++){
         for (int j=0; j < nfilcol+1; j++){
             Vertices[n] = _vertex3f(j, i, 0);
             t.Vertices[n] = _vertex3f(j, i, 0);
             n++;
         }
     }

     for (int i=0, j=nfilcol+1; i< nfilcol*(nfilcol+1); i+=nfilcol+1, j+=nfilcol+1){
          for (int k=0; k<nfilcol;k++){
              Triangles.push_back(_vertex3ui(i+k, i+1+k, j+k));
              Triangles.push_back(_vertex3ui(j+1+k, j+k, i+1+k));
              t.Triangles.push_back(_vertex3ui(i+k, i+1+k, j+k));
              t.Triangles.push_back(_vertex3ui(j+1+k, j+k, i+1+k));
          }
     }

    normal_creation_triangles_vertex();
    t.normal_creation_triangles_vertex();
}



void _textura::activarT1(const string &File_name)
{
    if (Imagen.load(File_name.c_str())==false) cout << "Image not loaded" << endl;
    // reflejo vertical
    Imagen=Imagen.mirrored(false,true);
    //
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // parametros de aplicacion de la textura
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // asignacion de la textura
    glTexImage2D(GL_TEXTURE_2D,0,4,Imagen.width(),Imagen.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Imagen.bits());

glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f(Vertices[0].x,Vertices[0].y,Vertices[0].z);
    glTexCoord2f(1,0);
    glVertex3f(Vertices[ntot].x,Vertices[ntot].y,Vertices[ntot].z);
    glTexCoord2f(1,1);
    glVertex3f(Vertices[ntot*(ntot+1)+ntot].x,Vertices[ntot*(ntot+1)+ntot].y,Vertices[ntot*(ntot+1)+ntot].z);
    glTexCoord2f(0,1);
    glVertex3f(Vertices[ntot*(ntot+1)].x,Vertices[ntot*(ntot+1)].y,Vertices[ntot*(ntot+1)].z);

      glEnd();

glDisable(GL_TEXTURE_2D);
}

void _textura::activarT2(const string &File_name)
{
    if (Imagen.load(File_name.c_str())==false) cout << "Image not loaded" << endl;
    // reflejo vertical
    Imagen=Imagen.mirrored(false,true);
    //
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // parametros de aplicacion de la textura
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // asignacion de la textura
    glTexImage2D(GL_TEXTURE_2D,0,4,Imagen.width(),Imagen.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Imagen.bits());

glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);
glEnable(GL_TEXTURE_2D);
glBegin(GL_QUADS);
glTexCoord2f(0,0);
glVertex3f(Vertices[14].x,Vertices[14].y,Vertices[14].z);
glTexCoord2f(1,0);
glVertex3f(Vertices[15].x,Vertices[15].y,Vertices[15].z);
glTexCoord2f(1,1);
glVertex3f(Vertices[21].x,Vertices[21].y,Vertices[21].z);
glTexCoord2f(0,1);
glVertex3f(Vertices[20].x,Vertices[20].y,Vertices[20].z);

  glEnd();

glDisable(GL_TEXTURE_2D);
}

void _textura::activarT3(const string &File_name)
{
    if (Imagen.load(File_name.c_str())==false) cout << "Image not loaded" << endl;
    // reflejo vertical
    Imagen=Imagen.mirrored(false,true);
    //
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // parametros de aplicacion de la textura
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // asignacion de la textura
    glTexImage2D(GL_TEXTURE_2D,0,4,Imagen.width(),Imagen.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Imagen.bits());

glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);

glEnable(GL_TEXTURE_2D);
glBegin(GL_QUADS);
glTexCoord2f(0,0.5);
glVertex3f(Vertices[0].x,Vertices[0].y,Vertices[0].z);

glTexCoord2f(1,0.5);
glVertex3f(Vertices[ntot].x,Vertices[ntot].y,Vertices[ntot].z);
glTexCoord2f(1,1);
glVertex3f(Vertices[17].x,Vertices[17].y,Vertices[17].z);
glTexCoord2f(0,1);

glVertex3f(Vertices[12].x,Vertices[12].y,Vertices[12].z);

  glEnd();

glDisable(GL_TEXTURE_2D);
}
