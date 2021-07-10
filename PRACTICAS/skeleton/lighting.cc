#include "lighting.h"

    _lighting::_lighting(int num)
    {
        switch(num){
        case 0: luz=GL_LIGHT0; //Luz blanca
            setPos(100,100,100,0); //Es direccional y no posicional
            setEspecular(1,1,1,1);
            setAmbiente(1,1,1,0.8);
            setDifuso(1,1,1,1);
            break;
        case 1: luz=GL_LIGHT1; //Luz magenta
            setPos(100,100,100,1);  //Posicional y no direccional
            setEspecular(1,0,1,1);
            setAmbiente(1,0,1,0.1);
            setDifuso(1,0,1,1);
            break;
        case 2: luz=GL_LIGHT2;setValoresIniciales(); break;
        case 3: luz=GL_LIGHT3;setValoresIniciales(); break;
        case 4: luz=GL_LIGHT4;setValoresIniciales(); break;
        case 5: luz=GL_LIGHT5;setValoresIniciales(); break;
        case 6: luz=GL_LIGHT6;setValoresIniciales(); break;
        case 7: luz=GL_LIGHT7;setValoresIniciales(); break;
        default: luz=GL_LIGHT0; break;
        }


        encendida=false; //Al crearlas estan apagadas por defecto
    }

//Funcion que enciende la luz
void _lighting::encender()
{

    //Pone a true que esta encendido
    encendida=true;
    glEnable(luz);
    //Establece los valores que hemos inicializado en el constructor
    glLightfv(luz, GL_POSITION, pos);
    glLightfv(luz,GL_AMBIENT,ambiente);
    glLightfv(luz,GL_SPECULAR,especular);
    glLightfv(luz,GL_DIFFUSE,difuso);
}

//Funcion que apaga la luz
void _lighting::apagar()
{
    encendida=false;
    glDisable(luz);
}

//Funcion que establece los valores del componente ambiental
void _lighting::setAmbiente(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    ambiente[0]=x;
    ambiente[1]=y;
    ambiente[2]=z;
    ambiente[3]=w;

}

//Funcion que establece los valores del componente especular
void _lighting::setEspecular(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    especular[0]=x;
    especular[1]=y;
    especular[2]=z;
    especular[3]=w;

}

//Funcion que establece los valores del componente difuso
void _lighting::setDifuso(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    difuso[0]=x;
    difuso[1]=y;
    difuso[2]=z;
    difuso[3]=w;

}

//Funcion que establece la posicion
void _lighting::setPos(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    pos[0]=x;
    pos[1]=y;
    pos[2]=z;
    pos[3]=w;

}

//Mete valores por defecto
void _lighting::setValoresIniciales()
{
    setAmbiente(1.0,1.0,1.0,1.0);
    setDifuso(1.0,1.0,1.0,1.0);
    setEspecular(1.0,1.0,1.0,1.0);
    setPos(0.0,1.0,0.0,1); //Por defector en blanco y no en el infinito

}

