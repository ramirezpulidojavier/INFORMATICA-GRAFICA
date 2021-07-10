/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "rev.h"
#include <math.h>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_rev::_rev()
{

}

/*****************************************************************************//**
 * Funcion que rota un perfil sobre el eje seleccionado para generar el resto de vertices y triangulos de la figura
 * verti -> vector que contiene el perfil a rotar
 * eje -> eje sobre el que girar el perfil
 * n -> numero de rotaciones sobre el eje elegido
 * tapas_elegidas -> numero de tapas que quiero mostra
 *
 *
 *****************************************************************************/

int _rev::circular_sweeping(vector <_vertex3f> verti, int eje, int n, int tapas_elegidas){

    //Creamos la matriz que almacenara los vertices de la figura para crear los triangulos (sin las tapas)
    vector <vector <unsigned int>> matriz;
    Vertices.clear();

    float alfa = 0;     //Angulo de rotacion del perfil sobre el eje especificado
    int cont = 0;       //Avanza con el iterador para saber en que posicion dentro del perfil se encuentran las tapaderas
    int posicion = -1;  //Almacena la posicion de la ultima tapadera encontrada (vale 0 o aux.size())

    vector<_vertex3f>::iterator it=verti.begin(); //iterador para recorrer el vertice que contiene el perfil original (aun con tapas)
    vector<_vertex3f> aux;                        //vector auxilar que contiene los vertices que corresponden con tapas (se borran de verti)

    //Para recorrer todo el vector del perfil original
    while(it!=verti.end()){

        if(eje == 1 || eje==3){ //Eje x y z. Para estos eje, las tapaderas tendran valor 0 en la y


            if(it->_1 == 0){ //comprobamos que la coordenada y=0

                _vertex3f nuevo;                //creacion de nuevo vertice
                nuevo = *it;                    //almacenamos en este el vertice encontrado (es una tapa)
                aux.insert(aux.begin(), nuevo); //aniadimos este vertice al vector que contiene todas las tapas

                verti.erase(verti.begin()+cont); //borramos del perfil la tapa para evitar triangulos degenerados
                posicion = cont;                 //Guardamos la posicion en la que hemos encontrado la tapa


            }else{  //Si no es una tapa, que avance el iterador y cont. No se avanza siempre, porque cuando se encuentra una tapa,
                    //esta se borra y todos los valores de verti se desplazan una posicion a la izquierda, por lo que si
                    //ademas avanzamos una nosotros, dejamos posiciones sin comprobar
                ++it;
                cont++;
            }

        }else if(eje==2){ //Eje y. Para este eje, las tapaderas tendran valor 0 en la x


            if(it->_0 == 0){ //comprobamos que la coordenada x=0

                _vertex3f nuevo;                //creacion de nuevo vertice
                nuevo = *it;                    //almacenamos en este el vertice encontrado (es una tapa)
                aux.insert(aux.begin(), nuevo); //aniadimos este vertice al vector que contiene todas las tapas

                verti.erase(verti.begin()+cont); //borramos del perfil la tapa para evitar triangulos degenerados
                posicion = cont;                 //Guardamos la posicion en la que hemos encontrado la tapa


            }else{  //Si no es una tapa, que avance el iterador y cont. No se avanza siempre, porque cuando se encuentra una tapa,
                    //esta se borra y todos los valores de verti se desplazan una posicion a la izquierda, por lo que si
                    //ademas avanzamos una nosotros, dejamos posiciones sin comprobar
                ++it;
                cont++;
            }

        }

    }

    //Rellenamos el vector Vertices con el resto de puntos del perfil (todos menos las tapaderas) y sus rotaciones
    //El numero de vertices que habra en toda la figura sin contar las tapaderas será (perfil-tapas)*rotaciones
    for (int i=0; i<(int)verti.size()*n; i++){

        //Metemos al principio todos los del perfil (sin las tapas) de golpe, sin tener que calcular sus rotaciones porque son los originales
        if(i < (int)verti.size())

            Vertices.push_back(verti[i]);

        else{   //Significa que ya estamos metiendo puntos nuevos, por lo que hay que calcular sus posiciones al rotarlos

            //Cuando hemos calculado todos los puntos de una rotacion, actualizamos el valor del angulo de rotacion
            //Todos los puntos de una rotacion tienen el mismo angulo de giro
            if(i%verti.size() == 0)

                alfa += 2*M_PI/n; //Es lo mismo que 360 / rotaciones para saber cuantos angulos son cada rotacion


            switch(eje){ //Dependiendo del eje, cada punto se calculara con senos y cosenos de una forma diferente

                case 1: //Eje x (permanece la x y cambian y y z)

                    Vertices.push_back(_vertex3f(Vertices[i%verti.size()]._0, Vertices[i%verti.size()]._1 * cos(alfa),
                                       -1 * (Vertices[i%verti.size()]._1) * sin(alfa)));
                    break;

                case 2: //Eje y (permanece la y y cambian x y z)

                    Vertices.push_back(_vertex3f(Vertices[i%verti.size()]._0 * cos(alfa), Vertices[i%verti.size()]._1,
                                       -1 * (Vertices[i%verti.size()]._0) * sin(alfa)));

                    break;

                case 3: //Eje z (permanece la z y cambian y y x)

                    Vertices.push_back(_vertex3f(-1 * (Vertices[i%verti.size()]._1) * sin(alfa), Vertices[i%verti.size()]._1 * cos(alfa),                    // y
                                       Vertices[i%verti.size()]._2));

                     break;

            }

        }

    }


    //Vaciamos la matriz por si tiene basura de otros objetos
    matriz.clear();

    vector<unsigned int> auxiliar; //Vector para inicializar la matriz y poder utilizarla con los corchetes para insertar cosas
    unsigned int contador = 0;      //para rellenar la matriz con valores consecutivos desde 0 hasta n*verti.size()

    //Hacemos un resize de n que es el numero de columnas que queremos que tenga la matriz
    auxiliar.resize(n);

    //Aniadimos a la matriz ese vector de tamanio n tantas veces como filas queremos que haya (verti.size tiene la cantidad de vertices
    //que hay en el perfil que no son tapas, precisamente aquellos que queremos en la matris)
    for(int i = 0; i < (int)verti.size() ; i++)

        matriz.push_back(auxiliar);


    //Bucle que mete en el orden ascendente y de izquierda a derecha los valores consecutivos de contador
    for( int i = 0 ; i < n ; i++){
        for( int j = (int)verti.size() - 1 ; j >= 0 ; j--){

            matriz[j][i] = contador;
            contador++;

        }
    }

    //Vaciamos triangles por si tiene basura de otro objeto
    Triangles.clear();

    //For que asigna vertices a los triangulos de forma automatica. Se recorre de abajo a arriba y de izq a derecha
    for( int i = 0; i < n; i++){

        //Cuando termina cada iteracion se han completado todos los triangulos de una cara
        for(int j = verti.size() - 1 ; j > 0 ; j--){

            //Triangulos hacia arriba
            Triangles.push_back(_vertex3ui(matriz[j][i],matriz[j][(i+1)%n],matriz[j-1][i]));

            //Triangulos hacia abajo
            Triangles.push_back(_vertex3ui(matriz[(verti.size()-1)-j][i],matriz[(verti.size()-1)-j][(i+1)%n],matriz[verti.size()-j][(i+1)%n]));

        }
    }

    //Bucle que introduce al final de vertices pero antes de las tapas los nuevos vertices que son identicos en coordenadas a los del perfil
    //original sin tapaderas. Esto es para cerrar la figura con puntos nuevos que contengan el final de la imagen (para textura)
    for(int i=0; i<(int)verti.size(); i++)
        Vertices.push_back(verti[i]);

    //Metemos las tapaderas en vertices segun las que hemos elegido mostrar
    if (tapas_elegidas == 3 && (int)aux.size()==2){ //Si hemos elegido ambas tapas y realmente se han identificado dos tapas
        Vertices.push_back(aux[0]);
        Vertices.push_back(aux[1]);
    }

    //Si se ha elegido la tapa inferior, la posicion de la ultima tapa que leimos es la de abajo y al menos se ha leido una tapa
    else if (tapas_elegidas == 2 && posicion == (int)verti.size() && aux.size()>=1)
        Vertices.push_back(aux[0]);

    //Si se ha elegido la tapa superior y, se han leido dos tapas o se ha leido solo una con posicion 0 (significa que es la primera)
    else if ( tapas_elegidas == 1 && (aux.size()==2 || (aux.size()==1 && posicion == 0)) )
        Vertices.push_back(aux[aux.size()-1]);

    int tapas_usables = 1; //Creo una variable que contendra el numero de tapas que he pedido que se muestren, no las que he identificado.

    if(tapas_elegidas == 0) tapas_usables=tapas_elegidas;
    else if(tapas_elegidas == 3) tapas_usables=2;


    //Rellenamos los triangulo de las tapaderas
    //Este for pinta la tapa inferior, la cual se pintara si:
        //He elegido mostrar las 2, realmente he encontrado dos y la ultima encontrada (posicion) es la de abajo
        //o he elegido mostrar solo la de abajo, he encontrado 1 o mas y la ultima que he encontrado es la de abajo
    if( ((tapas_elegidas == 3 && aux.size()==2) || tapas_elegidas == 2) && (aux.size() >=1 && posicion == (int) verti.size()) )
        //El for une la tapa con los vertices que se encuentran en la parte superior de la matriz
        for( int i = 0; i < n; i++)
            Triangles.push_back(_vertex3ui(Vertices.size()-tapas_usables,matriz[0][i],matriz[0][(i+1)%n]));

    //Este for pinta la tapa superior, la cual se pintara si:
        //He elegido mostrar las 2, realmente he encontrado dos (significa que la de arriba esta si o si)
        //o he elegido mostrar solo la de abajo, he encontrado 1 unicamente y es la de arriba (posicion==0)
    if ( ((tapas_elegidas == 3 && aux.size()==2)|| tapas_elegidas == 1) && (aux.size()==2 || (aux.size()==1 && posicion == 0)) )
        //El for une la tapa con los vertices que se encuentran en la parte superior de la matriz
        for( int i = 0; i < n; i++)
            Triangles.push_back(_vertex3ui(Vertices.size()-1, matriz[verti.size()-1][i], matriz[verti.size()-1][(i+1)%n]));


    return aux.size(); //Devolvemos la cantidad de vertices que hemos identificado como tapas (para tener en cuenta en texturas)

}

/*****************************************************************************//**
 * Funcion que convierte los puntos de un perfil adaptados al giro sobre un eje a otro perfil con los mismos puntos pero para otro eje
    verti -> vector que contiene el perfil a rotar
    eje1 -> eje para el que esta adaptado el perfil
    eje2 -> eje para el que quiero adaptado el perfil
 *****************************************************************************/

vector<_vertex3f> _rev::conversionVertices(vector <_vertex3f> perfil, int eje1, int eje2){

    //Vector que tendra el nuevo perfil y que sera devuelto al terminar
    vector <_vertex3f> auxiliar;

    switch (eje1){

        case 1: //Si tenemos el vertice adaptado al eje x

            if (eje2 == 2){ //Si queremos pasarlo al y

                for (int i=0; i<(int)perfil.size(); i++)
                    auxiliar.push_back(_vertex3f(perfil[i]._1,perfil[i]._0,perfil[i]._2));


            }else if(eje2 == 3){    //Si queremos pasarlo al z

                for (int i=0; i<(int)perfil.size(); i++)
                    auxiliar.push_back(_vertex3f(perfil[i]._2,perfil[i]._1,perfil[i]._0));


            }else  //Si queremos pasarlo al mismo o a algun eje no valido, que lo deje como estaba

                return perfil;

            break;

        case 2: //Si tenemos el vertice adaptado al eje y

            if (eje2 == 1){ //Si queremos pasarlo al x

                for (int i=0; i<(int)perfil.size(); i++)
                    auxiliar.push_back(_vertex3f(perfil[i]._1,perfil[i]._0,perfil[i]._2));


            }else if (eje2 == 3){ //Si queremos pasarlo al z

                auxiliar = conversionVertices(perfil, 2, 1); //pasamos del y al x
                auxiliar = conversionVertices(auxiliar, 1, 3); //y del x al z

            }else //Si queremos pasarlo al mismo o a algun eje no valido, que lo deje como estaba

                return perfil;

            break;

        case 3:

            if (eje2 == 1) //Si queremos pasarlo al x

                auxiliar = conversionVertices(perfil, 1, 3);

            else if (eje2 == 2){ //Si queremos pasarlo al eje y

                auxiliar = conversionVertices(perfil, 3, 1);
                auxiliar = conversionVertices(auxiliar, 1, 2);

            }else //Si queremos pasarlo al mismo o a algun eje no valido, que lo deje como estaba

                return perfil;

            break;

    }

    return auxiliar; //Devuelve el vector con el nuevo vertice

}

/*****************************************************************************//**
 *Funcion que rota un punto sobre el eje z para generar el perfil de la esfera con el mismo arco entre las divisiones
 *punto -> vertice original que queremos girar para obtener el resto
 *num_div -> numero de veces a rotar ese punto original (que determinara cuantos vertices tiene el perfil)
 *****************************************************************************/

vector<_vertex3f> _rev::esfera_creation(_vertex3f punto, int num_div){

    //Vector que contendra los vertices del perfil una vez rotado
    vector<_vertex3f> perfil_esfera;
    //radio es el radio que tendra el giro del perfil (tam/2)
    float radio = punto._1;
    //punto auxiliar que se ira modificando e insertando en el perfil
    _vertex3f aux;
    //El angulo dependera del numero de veces que queramos rotar el punto, es sacara la posicion de los puntos
    float angle = 0;

    //bucle para calcular el punto conforme rotamos
    for(int i=0; i<num_div; i++){
        aux._0 = radio*sin(angle);
        aux._1 = radio*cos(angle);
        aux._2 = 0; //0 porque rota sobre el eje z
        angle+=M_PI/num_div;    //actualizamos el valor del angulo
        perfil_esfera.push_back(aux);
    }

    perfil_esfera.push_back(_vertex3f(0, -radio, 0)); //añadimos el punto de abajo para que tengo los valores exactos y no acumulando decimales

    return perfil_esfera; //Devolvemos el perfil

}

