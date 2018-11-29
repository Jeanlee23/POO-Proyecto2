//
// Created by jeanl on 22/11/2018.
//

#ifndef PROYECTO_2_MATRIZ_H
#define PROYECTO_2_MATRIZ_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef int numerico;
typedef char line;

class matriz {
private:
    line **imagen = nullptr;
    numerico columnas;
    numerico filas;
    numerico alto=1;
    numerico ancho=1;
    line** crear(int filas, int columnas);
public:
    matriz();
    void invertir();
    void ensanchar(numerico x);
    void alargar(numerico x);
    void agrandar(numerico x);
    void rotar90derecha();
    void rotar180();
    void rotar90izquierda();
    void volverTamannoOriginal();
    void const imprimir();
    ~matriz();
};


#endif //PROYECTO_2_MATRIZ_H
