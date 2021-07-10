#include "tablero.h"
#include <iostream>
#include <limits>

using namespace std;

_tablero::_tablero(double tam)
{

  //Vaciamos ambos por si tienen basura
  Vertices.clear();
  Triangles.clear();
  Textura.clear();

  int vertices_verticales = 6, vertices_horizontales = 7;
  unsigned int contador = 0;

  Vertices.resize(vertices_verticales*vertices_horizontales);
  Textura.resize(vertices_verticales*vertices_horizontales);
  Triangles.clear();

  for(float j = -tam/2; j <= tam/2 ; j += tam/(vertices_verticales-1)){

      for(float i = tam/2; i >= -tam/2 ; i -= tam/(vertices_horizontales-1)){

          Vertices[contador]=_vertex3f(j,i,0);
          contador++;
      }

  }


  vector <vector <unsigned int>> matriz;

  //Vaciamos la matriz por si tiene basura de otros objetos
  matriz.clear();

  vector<unsigned int> auxiliar; //Vector para inicializar la matriz y poder utilizarla con los corchetes para insertar cosas
  contador = 0;      //para rellenar la matriz con valores consecutivos desde 0 hasta n*verti.size()

  //Hacemos un resize de n que es el numero de columnas que queremos que tenga la matriz
  auxiliar.resize(vertices_verticales-1);

  //Aniadimos a la matriz ese vector de tamanio n tantas veces como filas queremos que haya (verti.size tiene la cantidad de vertices
  //que hay en el perfil que no son tapas, precisamente aquellos que queremos en la matris)
  for(int i = 0; i < vertices_horizontales ; i++)

      matriz.push_back(auxiliar);

  //Bucle que mete en el orden ascendente y de izquierda a derecha los valores consecutivos de contador
  for( int i = 0 ; i < vertices_verticales ; i++){
      for( int j = vertices_horizontales-1 ; j >= 0 ; j--){

          matriz[j][i] = contador;
          contador++;

      }
  }


  //For que asigna vertices a los triangulos de forma automatica. Se recorre de abajo a arriba y de izq a derecha
  for( int i = 0; i < vertices_verticales-1; i++){

      //Cuando termina cada iteracion se han completado todos los triangulos de una cara
      for(int j = vertices_horizontales-1 ; j > 0 ; j--){

          Triangles.push_back(_vertex3ui(matriz[j][i],matriz[j][(i+1)],matriz[j-1][i]));
          Triangles.push_back(_vertex3ui(matriz[(vertices_horizontales-1)-j][i],matriz[(vertices_horizontales-1)-j][(i+1)],matriz[vertices_horizontales-j][i+1]));

      }
  }

    contador= 0 ;
    float altura_imagen = 1.0 ;
    float anchura_imagen = 0.0;
    for(int i = 0 ; i < vertices_verticales; i++){

      altura_imagen=1.0;

      for(int j = 0 ; j < vertices_horizontales; j++){

          Textura[contador] =_vertex2f(anchura_imagen, altura_imagen);
          altura_imagen -= 1.0/(vertices_horizontales-1);
          contador++;

      }
      anchura_imagen += 1.0/(vertices_verticales-1);
    }

  //Coordenadas para las texturas del tablero
//  Textura[0]=_vertex2f(0.0f, 0.0f);
//  Textura[1]=_vertex2f(1.0f, 0.0f);
//  Textura[2]=_vertex2f(0.0f, 1.0f);
//  Textura[3]=_vertex2f(1.0f, 1.0f);

  //Calculamos las normales de los triangulos y los vertices
  normal_creation_triangles_vertex();

}
